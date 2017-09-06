#pragma execution_character_set("utf-8")

#include "LayerResLoad.h"
#include "common/util/UtilString.h"
#include "defines/DefinesRes.h"
#include "defines/DefinesValue.h"
#include "cocos2d/cocos/audio/include/SimpleAudioEngine.h"
#include "common/util/UtilDate.h"
#include "game/ManagerHandle.h"

USING_NS_CC;
using namespace CocosDenshion;

LayerResLoadHandle::LayerResLoadHandle() : _view(nullptr), _model(nullptr)
{
}

LayerResLoadHandle::~LayerResLoadHandle()
{
	_view = nullptr;
	CC_SAFE_RELEASE_NULL(_model);
}

bool LayerResLoadHandle::init()
{
	auto isInit = false;
	do 
	{
		_model = LayerResLoadModel::create();
		_model->retain();

		attachStateCallback();

		isInit = true;
	} while (0);
	return isInit;
}

void LayerResLoadHandle::attachStateCallback()
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.insertCallback(StateLayerResLoad::DEFAULT, nullptr);
	stateCallback.insertCallback(StateLayerResLoad::CREATE_SKIN, CC_CALLBACK_0(LayerResLoadHandle::createSkin, this));
	stateCallback.insertCallback(StateLayerResLoad::UNLOAD_SOUND, CC_CALLBACK_0(LayerResLoadHandle::loadSounds, this));
	stateCallback.insertCallback(StateLayerResLoad::LOADING_SOUND, CC_CALLBACK_0(LayerResLoadHandle::loadingSounds, this));
	stateCallback.insertCallback(StateLayerResLoad::LOADED_SOUND, CC_CALLBACK_0(LayerResLoadHandle::loadedSounds, this));
	stateCallback.insertCallback(StateLayerResLoad::UNLOAD_IMAGE, CC_CALLBACK_0(LayerResLoadHandle::loadImages, this));
	stateCallback.insertCallback(StateLayerResLoad::LOADING_IMAGE, nullptr);
	stateCallback.insertCallback(StateLayerResLoad::LOADED_IMAGE, CC_CALLBACK_0(LayerResLoadHandle::loadedImages, this));
}

void LayerResLoadHandle::update(float delta)
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.doCallbackByCurrentState(delta);
}

void LayerResLoadHandle::createSkin()
{
	/*auto actionTimeline = CSLoader::createTimeline(RES_MODULES_WELCOME_SCENE_WELCOME_CSB);
	actionTimeline->gotoFrameAndPlay(0, true);
	skin->runAction(actionTimeline);*/
	auto skin = _model->getSkin();
	_view->addSkin(skin);

	_model->setState(StateLayerResLoad::UNLOAD_SOUND);
}

void LayerResLoadHandle::playLoadAnimation()
{
	auto spriteLoad = _model->getSpriteLoad();
	_view->playLoadAnimation(spriteLoad);
}

void LayerResLoadHandle::stopLoadAnimation()
{
	auto spriteLoad = _model->getSpriteLoad();
	_view->stopLoadAnimation(spriteLoad);
}

void LayerResLoadHandle::loadSounds()
{
	auto state = _model->getState();
	if (StateLayerResLoad::UNLOAD_SOUND != state)
	{
		return;
	}
	playLoadAnimation();

	/*SimpleAudioEngine::getInstance()->preloadBackgroundMusic(SOUND_MUSIC_BATTLE_0.c_str());
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(SOUND_MUSIC_BATTLE_1.c_str());

	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_AIM.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_ANGER.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_ARMADD.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_ARMHURT.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_ARMSUB.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_BURN.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_COMA.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_COOK.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_ELEMENT.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_FURY.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_HEAL_CURE.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_MAID_ATTACK.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_MST_ATTACK_0.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_MST_ATTACK_1.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_PALSY.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_PENETRATE.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_POISON.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_PURIFY.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_REMOVE.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_SENSITIVE.c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(SOUND_EFFECT_BATTLE_WEAK.c_str());*/
	SimpleAudioEngine::getInstance()->preloadEffect(((string)SOUND_EFFECT_SYSTEM_BTN_0_MP3).c_str());
	SimpleAudioEngine::getInstance()->preloadEffect(((string)SOUND_EFFECT_SYSTEM_BTN_1_MP3).c_str());

	_model->setState(StateLayerResLoad::LOADING_SOUND);
}

void LayerResLoadHandle::loadingSounds()
{
	_model->setState(StateLayerResLoad::LOADED_SOUND);
}

void LayerResLoadHandle::loadedSounds()
{
	stopLoadAnimation();
	_model->setState(StateLayerResLoad::UNLOAD_IMAGE);
}

void LayerResLoadHandle::loadImages()
{
	auto state = _model->getState();
	if (StateLayerResLoad::UNLOAD_IMAGE != state)
	{
		return;
	}
	playLoadAnimation();

	asyncLoadImage(RES_GAME_ENTITY_PLIST_CREATURE_PLIST);
	asyncLoadImage(RES_GAME_ENTITY_PLIST_MAP_PLIST);
	asyncLoadImage(RES_GAME_ENTITY_PLIST_RUNE_PLIST);

	asyncLoadImage(RES_GAME_ACROSS_PLIST_ACROSS_PLIST);

	asyncLoadImage(RES_GAME_UI_COMMON_PLIST_COMMON_PLIST);

	_model->setState(StateLayerResLoad::LOADING_IMAGE);
}

void LayerResLoadHandle::asyncLoadImage(const string &fileName)
{
	string fileNamePic = fileName;
	if (fileName.find(".png") == std::string::npos)
	{
		UtilString::stringReplace(fileNamePic, ".plist", ".png");
	}
	auto fullpath = FileUtils::getInstance()->fullPathForFilename(fileNamePic);
	// check if file exists
	if (fullpath.empty() || !FileUtils::getInstance()->isFileExist(fullpath))
	{
		return;
	}
	auto textureCache = Director::getInstance()->getTextureCache();
	if (textureCache->getTextureForKey(fullpath))
	{
		return;
	}

	auto bitData = _model->getBitData();
	auto bitIndex = bitData->getTotalBit();
	bitData->modifyTotalBit(bitIndex);
	textureCache->addImageAsync(fileNamePic, CC_CALLBACK_1(LayerResLoadHandle::asyncLoadImageCallback, this, fileName, bitIndex));
}

void LayerResLoadHandle::asyncLoadImageCallback(Texture2D* texture, const string& fileName, const int& bitIndex)
{
	if (fileName.find(".png") == std::string::npos)
	{
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(fileName, texture);
	}
	auto bitData = _model->getBitData();
	bitData->setBit(bitIndex);
	if (bitData->isAllBitTrue())
	{
		_model->setState(StateLayerResLoad::LOADED_IMAGE);
	}
}

void LayerResLoadHandle::loadedImages()
{
	stopLoadAnimation();

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->dispatchCustomEvent(EVENT_LAYER_RES_LOAD_LOADED);

	_model->setState(StateLayerResLoad::DEFAULT);
	/*auto time = UtilDate::getSecond();
	log("```````````````LayerWelcome::handleLoading loaded time:%s", Value(time).asString().c_str());
	//
	ManagerData::getInstance()->dataFileGet();
	ManagerData::getInstance()->getHandleDataEntity()->createDataEntityMaid();
	ManagerData::getInstance()->getHandleDataLevels()->createDicDataLevel();
	ManagerData::getInstance()->getHandleDataGrade()->setIdGradeLast();
	time = UtilDate::getSecond();
	log("```````````````LayerWelcome::handleLoading loaded time:%s", Value(time).asString().c_str());
	//
	ManagerTimer::getInstance()->timerStartDeal();
	time = UtilDate::getSecond();
	log("```````````````LayerWelcome::handleLoading loaded time:%s", Value(time).asString().c_str());
	//
	auto isSaveFileExist = ManagerData::getInstance()->isSaveFileExist();
	if (isSaveFileExist)
	{
		ManagerUI::getInstance()->replaceScene(TypeScene::MAIN);
	}
	else
	{
		ManagerUI::getInstance()->replaceScene(TypeScene::PLOT);
	}
	time = UtilDate::getSecond();
	log("```````````````LayerWelcome::handleLoading loaded time:%s", Value(time).asString().c_str());*/
}
