#include "ModelUnit.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

ModelUnit::ModelUnit()
{
}

ModelUnit::~ModelUnit()
{
	_poolAttribute.clear();
}

bool ModelUnit::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!ModelEntity::init());

		isInit = true;
	} while (0);

	return isInit;
}

void ModelUnit::insertAttribute(const int& id, const int& value, const int& min /*= 0*/, const int& max /*= INT_MAX*/)
{
	auto attribute = Attribute::create();
	attribute->initData(id, value, min, max);
	_poolAttribute.insert(id, attribute);
}

void ModelUnit::deleteAttribute(const int& id)
{
	_poolAttribute.erase(id);
}

Attribute* ModelUnit::getAttribute(const int& id) const
{
	auto attribute = _poolAttribute.at(id);
	return attribute;
}

void ModelUnit::modifyAttributeValue(const int& id, const int& val)
{
	auto attribute = _poolAttribute.at(id);
	if (attribute == nullptr)
	{
		return;
	}
	attribute->modifyValue(val);
}

void ModelUnit::modifyAttributeMin(const int& id, const int& val)
{
	auto attribute = _poolAttribute.at(id);
	if (attribute == nullptr)
	{
		return;
	}
	attribute->modifyMin(val);
}

void ModelUnit::modifyAttributeMax(const int& id, const int& val)
{
	auto attribute = _poolAttribute.at(id);
	if (attribute == nullptr)
	{
		return;
	}
	attribute->modifyMax(val);
}
