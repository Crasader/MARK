#pragma execution_character_set("utf-8")

#include "HandleResLoad.h"
#include "common/util/UtilString.h"
#include "common/define/DefinesRes.h"
#include "common/define/DefinesValue.h"
#include "cocos2d/cocos/audio/include/SimpleAudioEngine.h"
#include "common/util/UtilDate.h"
#include "game/ManagerHandle.h"

USING_NS_CC;
using namespace CocosDenshion;

HandleResLoad::HandleResLoad() : _layerResLoad(nullptr), _modelResLoad(nullptr)
{
}

HandleResLoad::~HandleResLoad()
{
	_layerResLoad = nullptr;
	CC_SAFE_RELEASE_NULL(_modelResLoad);
}

bool HandleResLoad::init()
{
	auto isInit = false;
	do 
	{
		_modelResLoad = ModelResLoad::create();
		_modelResLoad->retain();

		isInit = true;
	} while (0);
	return isInit;
}

void HandleResLoad::update(float delta)
{
	auto state = _modelResLoad->getState();

	if (StateResLoad::DEFAULT == state)
	{
		return;
	}

	if (StateResLoad::CREATE_SKIN == state)
	{
		createSkin();
		return;
	}

	//¼ÓÔØÉùÒô
	if (StateResLoad::UNLOAD_SOUND == state)
	{
		loadSounds();
		return;
	}

	if (StateResLoad::LOADING_SOUND == state)
	{
		loadingSounds();
		return;
	}

	if (StateResLoad::LOADED_SOUND == state)
	{
		loadedSounds();
		return;
	}
	//¼ÓÔØÍ¼Æ¬
	if (StateResLoad::UNLOAD_IMAGE == state)
	{
		loadImages();
		return;
	}

	if (StateResLoad::LOADING_IMAGE == state)
	{
		return;
	}

	if (StateResLoad::LOADED_IMAGE == state)
	{
		loadedImages();
		return;
	}
}

void HandleResLoad::createSkin()
{
	/*auto actionTimeline = CSLoader::createTimeline(RES_MODULES_WELCOME_SCENE_WELCOME_CSB);
	actionTimeline->gotoFrameAndPlay(0, true);
	skin->runAction(actionTimeline);*/
	auto skin = _modelResLoad->getSkin();
	_layerResLoad->addSkin(skin);

	_modelResLoad->setState(StateResLoad::UNLOAD_SOUND);
}

void HandleResLoad::playLoadAnimation()
{
	auto spriteLoad = _modelResLoad->getSpriteLoad();
	_layerResLoad->playLoadAnimation(spriteLoad);
}

void HandleResLoad::stopLoadAnimation()
{
	auto spriteLoad = _modelResLoad->getSpriteLoad();
	_layerResLoad->stopLoadAnimation(spriteLoad);
}

void HandleResLoad::loadSounds()
{
	auto state = _modelResLoad->getState();
	if (StateResLoad::UNLOAD_SOUND != state)
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

	_modelResLoad->setState(StateResLoad::LOADING_SOUND);
}

void HandleResLoad::loadingSounds()
{
	_modelResLoad->setState(StateResLoad::LOADED_SOUND);
}

void HandleResLoad::loadedSounds()
{
	stopLoadAnimation();
	_modelResLoad->setState(StateResLoad::UNLOAD_IMAGE);
}

void HandleResLoad::loadImages()
{
	auto state = _modelResLoad->getState();
	if (StateResLoad::UNLOAD_IMAGE != state)
	{
		return;
	}
	playLoadAnimation();

	asyncLoadImage(RES_GAME_ENTITY_PLIST_CREATURE_PLIST);
	asyncLoadImage(RES_GAME_ENTITY_PLIST_MAP_PLIST);
	asyncLoadImage(RES_GAME_ENTITY_PLIST_RUNE_PLIST);

	asyncLoadImage(RES_GAME_ACROSS_PLIST_ACROSS_PLIST);

	asyncLoadImage(RES_GAME_UI_COMMON_PLIST_COMMON_PLIST);

	_modelResLoad->setState(StateResLoad::LOADING_IMAGE);
}

void HandleResLoad::asyncLoadImage(const string &fileName)
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

	auto bitData = _modelResLoad->getBitData();
	auto totalBit = bitData->getTotalBit();
	textureCache->addImageAsync(fileNamePic, CC_CALLBACK_1(HandleResLoad::asyncLoadImageCallback, this, fileName, totalBit));
	bitData->modifyTotalBit(totalBit);
}

void HandleResLoad::asyncLoadImageCallback(Texture2D* texture, const string& fileName, const int& bit)
{
	if (fileName.find(".png") == std::string::npos)
	{
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(fileName, texture);
	}
	auto bitData = _modelResLoad->getBitData();
	bitData->setBit(bit);
	if (bitData->isAllBitTrue())
	{
		_modelResLoad->setState(StateResLoad::LOADED_IMAGE);
	}
}

void HandleResLoad::loadedImages()
{
	stopLoadAnimation();

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->dispatchCustomEvent(EVENT_LAYER_RES_LOAD_LOADED);

	_modelResLoad->setState(StateResLoad::DEFAULT);
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
