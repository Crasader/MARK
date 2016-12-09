#include "ModelResLoad.h"
#include <string>
#include "common/define/DefinesRes.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

ModelResLoad::ModelResLoad() : 
	_state(StateResLoad::CREATE_SKIN),
	_skin(nullptr),
	_spriteLoad(nullptr),
	_bitData(nullptr)
{
}

ModelResLoad::~ModelResLoad()
{
	_skin = nullptr;
	_spriteLoad = nullptr;
	CC_SAFE_RELEASE_NULL(_bitData);
}

bool ModelResLoad::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}

cocos2d::Node* ModelResLoad::getSkin()
{
	if (_skin == nullptr)
	{
		_skin = CSLoader::createNode(RES_GAME_UI_COMMON_LAYER_RES_LOAD_CSB);
	}
	return _skin;
}

cocos2d::Node* ModelResLoad::getSpriteLoad()
{
	if (_spriteLoad == nullptr)
	{
		auto spriteLoad = _skin->getChildByName("spriteLoad");
		_spriteLoad = spriteLoad;
	}
	return _spriteLoad;
}

BitData* ModelResLoad::getBitData()
{
	if (_bitData == nullptr)
	{
		_bitData = BitData::create();
		_bitData->retain();
	}
	return _bitData;
}
