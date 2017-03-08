#include "Entity.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

EntityModel::EntityModel() :
	_stateCallback(StateEntity::UNCREATE_SKIN),
	_id(0),
	_type(),
	_bitIndex(0),
	_skin(nullptr)
{
}

EntityModel::~EntityModel()
{
	_skin = nullptr;
	_stateCallback.clearDic();
}

bool EntityModel::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}

cocos2d::Sprite* EntityModel::getSkin()
{
	if (_skin == nullptr)
	{
		_skin = createSprite();
	}
	return _skin;
}
