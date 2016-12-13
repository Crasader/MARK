#include "ModelEntity.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

ModelEntity::ModelEntity() :
	_state(StateEntity::UNCREATE_SKIN),
	_id(0),
	_bitIndex(0),
	_skin(nullptr)
{
}

ModelEntity::~ModelEntity()
{
	_skin = nullptr;
}

bool ModelEntity::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}

cocos2d::Sprite* ModelEntity::getSkin()
{
	if (_skin == nullptr)
	{
		_skin = createSprite();
	}
	return _skin;
}
