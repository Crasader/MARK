#pragma execution_character_set("utf-8")

#include "HandleResLoad.h"
#include "common/util/UtilString.h"
#include "model/define/DefinesRes.h"
#include "model/config/ManagerCfg.h"
#include "cocos2d/cocos/audio/include/SimpleAudioEngine.h"
#include "common/util/UtilDate.h"
#include "core/ManagerHandle.h"

USING_NS_UI_COMMON;
using namespace CocosDenshion;

HandleResLoad::HandleResLoad() : _bitData(nullptr), _modelResLoad(nullptr)
{
}

HandleResLoad::~HandleResLoad()
{
	_layerResLoad = nullptr;
	CC_SAFE_RELEASE_NULL(_modelResLoad);
	CC_SAFE_RELEASE_NULL(_bitData);
}

bool HandleResLoad::init()
{
	auto isInit = false;
	do 
	{
		_modelResLoad = ModelResLoad::create();
		_modelResLoad->retain();

		_bitData = BitData::create();
		_bitData->retain();

		isInit = true;
	} while (0);
	return isInit;
}

void HandleResLoad::update(float delta)
{
	auto state = _modelResLoad->getState();

	if (StateResLoad::UNINIT == state)
	{
		_layerResLoad->createSkin();
		_modelResLoad->setState(StateResLoad::UNLOAD_SOUND);
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
	}
}

void HandleResLoad::loadSounds()
{
	auto state = _modelResLoad->getState();
	if (StateResLoad::UNLOAD_SOUND != state)
	{
		return;
	}
	_modelResLoad->setState(StateResLoad::LOADING_SOUND);

	_layerResLoad->playLoad();

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

	_modelResLoad->setState(StateResLoad::LOADED_SOUND);
}

void HandleResLoad::loadedSounds()
{
	_modelResLoad->setState(StateResLoad::UNLOAD_IMAGE);

	_layerResLoad->stopLoad();
}

void HandleResLoad::loadImages()
{
	auto state = _modelResLoad->getState();
	if (StateResLoad::UNLOAD_IMAGE != state)
	{
		return;
	}
	_modelResLoad->setState(StateResLoad::LOADING_IMAGE);

	_layerResLoad->playLoad();

	imageAsyncLoad(RES_UI_COMMON_PLIST_COMMON_PLIST);
	imageAsyncLoad(RES_CORE_ENTITY_PLIST_CREATURE_PLIST);
	imageAsyncLoad(RES_CORE_ENTITY_PLIST_MAP_PLIST);
	imageAsyncLoad(RES_CORE_ENTITY_PLIST_RUNE_PLIST);
	
	/*//¼ÓÔØ±³¾°Í¼Æ¬
	auto dicCfgLevels = ManagerCfg::getInstance()->getDicCfgLevels();
	for (auto var : dicCfgLevels)
	{
		auto cfgLevels = var.second;
		auto vecUrlPic = cfgLevels.vecUrlPic;
		if (vecUrlPic.size() == 0)
		{
			continue;
		}
		for (auto urlPic : vecUrlPic)
		{
			if (urlPic == "")
			{
				continue;
			}
			if (_dicUrlLoaded.find(urlPic) == _dicUrlLoaded.end())
			{
				_dicUrlLoaded[urlPic] = true;
				imageAsyncLoad(urlPic);
			}
		}
	}
	//¼ÓÔØÊµÌåÍ¼Æ¬
	auto dicCfgEntity = ManagerCfg::getInstance()->getDicCfgEntity();
	for (auto var : dicCfgEntity)
	{
		auto cfgEntity = var.second;
		vector<string> vecUrlPic;
		vecUrlPic.push_back(cfgEntity.urlPicEntity);
		vecUrlPic.push_back(cfgEntity.urlPicEntityBreak);
		for (auto urlPic : vecUrlPic)
		{
			if (urlPic == "")
			{
				continue;
			}
			if (_dicUrlLoaded.find(urlPic) == _dicUrlLoaded.end())
			{
				_dicUrlLoaded[urlPic] = true;
				imageAsyncLoad(urlPic);
			}
		}
	}*/
}

void HandleResLoad::loadedImages()
{
	_layerResLoad->stopLoad();

	auto manager = ManagerHandle::getInstance();
	manager->notify((int)ID_OBSERVER::HANDLE_SCENE_MAIN, TO_HANDLE_SCENE_MAIN::LAYER_RES_LOAD_REMOVE);
	manager->notify((int)ID_OBSERVER::HANDLE_SCENE_MAIN, TO_HANDLE_SCENE_MAIN::LAYER_ENTITY_ADD);
	manager->notify((int)ID_OBSERVER::HANDLE_SCENE_MAIN, TO_HANDLE_SCENE_MAIN::LAYER_MENU_START_ADD);
	
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

void HandleResLoad::imageAsyncLoad(const string &fileName)
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

	auto bit = _bitData->getTotalBit();

	textureCache->addImageAsync(fileNamePic, CC_CALLBACK_1(HandleResLoad::imageAsyncCallback, this, fileName, bit));
	
	_bitData->setTotalBit(bit);
}

void HandleResLoad::imageAsyncCallback(Texture2D* texture, const string& fileName, const int& bit)
{
	if(fileName.find(".png") == std::string::npos)
	{
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(fileName, texture);
	}
	_bitData->setBit(bit);
	if (_bitData->isAllBitTrue())
	{
		_modelResLoad->setState(StateResLoad::LOADED_IMAGE);
	}
}
