#include "Unit.h"

USING_NS_CC;
USING_NS_GAME_ENTITY;

UnitModel::UnitModel()
{
}

UnitModel::~UnitModel()
{
	_poolAttribute.clear();
}

bool UnitModel::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!EntityModel::init());

		isInit = true;
	} while (0);

	return isInit;
}

void UnitModel::insertAttribute(const int& id, const int& value, const int& min /*= 0*/, const int& max /*= INT_MAX*/)
{
	auto attribute = Attribute::create();
	attribute->initData(id, value, min, max);
	_poolAttribute.insert(id, attribute);
}

void UnitModel::deleteAttribute(const int& id)
{
	_poolAttribute.erase(id);
}

Attribute* UnitModel::getAttribute(const int& id) const
{
	auto attribute = _poolAttribute.at(id);
	return attribute;
}

void UnitModel::modifyAttributeValue(const int& id, const int& val)
{
	auto attribute = _poolAttribute.at(id);
	if (attribute == nullptr)
	{
		return;
	}
	attribute->modifyValue(val);
}

void UnitModel::modifyAttributeMin(const int& id, const int& val)
{
	auto attribute = _poolAttribute.at(id);
	if (attribute == nullptr)
	{
		return;
	}
	attribute->modifyMin(val);
}

void UnitModel::modifyAttributeMax(const int& id, const int& val)
{
	auto attribute = _poolAttribute.at(id);
	if (attribute == nullptr)
	{
		return;
	}
	attribute->modifyMax(val);
}
