#include "ModelEntity.h"

USING_NS_GAME_ENTITY;

ModelEntity::ModelEntity() : _state(StateLayerEntity::WORLD_UNCREATE), _dataEntityCreate(nullptr)
{
}

ModelEntity::~ModelEntity()
{
	CC_SAFE_RELEASE_NULL(_dataEntityCreate);
}

bool ModelEntity::init()
{
	auto isInit = false;

	do
	{
		_dataEntityCreate = BitData::create();
		_dataEntityCreate->retain();

		isInit = true;
	} while (0);

	return isInit;
}
