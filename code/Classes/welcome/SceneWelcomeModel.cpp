#include "SceneWelcome.h"
#include "logo/LayerLogo.h"

USING_NS_CC;

SceneWelcomeModel::SceneWelcomeModel() :
	_stateCallback(),
	_isLogoPlayOver(false),
	_dicLayers(),
	_listener(nullptr)
{
	_stateCallback.setState(StateWelcome::UNPLAY_LOGO);
}

SceneWelcomeModel::~SceneWelcomeModel()
{
	_stateCallback.clearDic();
	_isLogoPlayOver = false;
	_dicLayers.clear();
	_listener = nullptr;
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

