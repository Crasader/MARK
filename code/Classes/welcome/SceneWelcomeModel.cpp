#include "SceneWelcome.h"
#include "logo/LayerLogo.h"

USING_NS_CC;

SceneWelcomeModel::SceneWelcomeModel() :
	_stateCallback(StateWelcome::UNPLAY_LOGO),
	_isLogoPlayOver(false),
	_dicLayers(),
	_listenerLogoOver(nullptr)
{
}

SceneWelcomeModel::~SceneWelcomeModel()
{
	_stateCallback.clearDic();
	_isLogoPlayOver = false;
	_dicLayers.clear();
	_listenerLogoOver = nullptr;
}

bool SceneWelcomeModel::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}
//Layers
Layer* SceneWelcomeModel::getLayer(const TypeLayerInWelcome& type)
{
	auto layer = getLayerByType(type);
	if (layer == nullptr)
	{
		layer = createLayerByType(type);
		insertLayerByType(type, layer);
	}
	return layer;
}

void SceneWelcomeModel::setLayerNullptr(const TypeLayerInWelcome& type)
{
	eraseLayerByType(type);
}

Layer* SceneWelcomeModel::createLayerByType(const TypeLayerInWelcome& type)
{
	switch (type)
	{
	case TypeLayerInWelcome::LOGO:
		return LayerLogo::create();
	default:
		return nullptr;
	}
}

bool SceneWelcomeModel::insertLayerByType(const TypeLayerInWelcome& type, Layer* layer)
{
	auto layerInDic = getLayerByType(type);
	if (layerInDic != nullptr)
	{
		return false;
	}
	_dicLayers.insert(type, layer);
	return true;
}

bool SceneWelcomeModel::eraseLayerByType(const TypeLayerInWelcome& type)
{
	auto layer = getLayerByType(type);
	if (layer == nullptr)
	{
		return false;
	}
	_dicLayers.erase(type);
	return true;
}

Layer* SceneWelcomeModel::getLayerByType(const TypeLayerInWelcome& type)
{
	auto layer = _dicLayers.at(type);
	return layer;
}

void SceneWelcomeModel::addEventListenerLogoOver(const std::function<void(cocos2d::EventCustom*)>& callback)
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	_listenerLogoOver = dispatcher->addCustomEventListener(EVENT_LAYER_LOGO_OVER, callback);
}

void SceneWelcomeModel::removeEventLIstenerLogoOver()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeEventListener(_listenerLogoOver);
}

