#include "ModelWelcome.h"
#include "logo/LayerLogo.h"

USING_NS_CC;

ModelWelcome::ModelWelcome() : 
	_listenerLayerLogoOver(nullptr), 
	_state(StateWelcome::UNPLAY_LOGO)
{
}

ModelWelcome::~ModelWelcome()
{
	_listenerLayerLogoOver = nullptr;
}

bool ModelWelcome::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}

Layer* ModelWelcome::getLayer(const TypeLayerInWelcome& type)
{
	auto layer = getLayerByType(type);
	if (layer == nullptr)
	{
		layer = createLayerByType(type);
		insertLayerByType(type, layer);
	}
	return layer;
}

void ModelWelcome::setLayerNullptr(const TypeLayerInWelcome& type)
{
	eraseLayerByType(type);
}

bool ModelWelcome::insertLayerByType(const TypeLayerInWelcome& type, Layer* layer)
{
	auto layerInDic = getLayerByType(type);
	if (layerInDic != nullptr)
	{
		return false;
	}
	_dicLayers.insert(type, layer);
	return true;
}

Layer* ModelWelcome::createLayerByType(const TypeLayerInWelcome& type)
{
	switch (type)
	{
	case TypeLayerInWelcome::LOGO:
		return LayerLogo::create();
	default:
		return nullptr;
	}
}

bool ModelWelcome::eraseLayerByType(const TypeLayerInWelcome& type)
{
	auto layer = getLayerByType(type);
	if (layer == nullptr)
	{
		return false;
	}
	_dicLayers.erase(type);
	return true;
}

Layer* ModelWelcome::getLayerByType(const TypeLayerInWelcome& type)
{
	auto layer = _dicLayers.at(type);
	return layer;
}
