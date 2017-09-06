#include "LayerResLoad.h"
#include <string>
#include "defines/DefinesRes.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

LayerResLoadModel::LayerResLoadModel() : 
	_stateCallback(StateLayerResLoad::CREATE_SKIN),
	_skin(nullptr),
	_spriteLoad(nullptr),
	_bitData(nullptr)
{
}

LayerResLoadModel::~LayerResLoadModel()
{
	CC_SAFE_RELEASE_NULL(_bitData);
	_spriteLoad = nullptr;
	_skin = nullptr;
	_stateCallback.clearDic();
}

bool LayerResLoadModel::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}

cocos2d::Node* LayerResLoadModel::getSkin()
{
	if (_skin == nullptr)
	{
		_skin = CSLoader::createNode(RES_GAME_UI_COMMON_LAYER_RES_LOAD_CSB);
	}
	return _skin;
}

cocos2d::Node* LayerResLoadModel::getSpriteLoad()
{
	if (_spriteLoad == nullptr)
	{
		auto spriteLoad = _skin->getChildByName("spriteLoad");
		_spriteLoad = spriteLoad;
	}
	return _spriteLoad;
}

BitData* LayerResLoadModel::getBitData()
{
	if (_bitData == nullptr)
	{
		_bitData = BitData::create();
		_bitData->retain();
	}
	return _bitData;
}
