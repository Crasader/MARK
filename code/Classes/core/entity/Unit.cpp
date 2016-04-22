#include "Unit.h"

USING_NS_CORE_ENTITY;

Unit::Unit()
{
}

Unit::~Unit()
{
	_poolAttribute.clear();
}

bool Unit::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Entity::init());

		isInit = true;
	} while (0);

	return isInit;
}

void Unit::insertAttribute(const int& id, const int& value, const int& min /*= 0*/, const int& max /*= INT_MAX*/)
{
	auto attribute = Attribute::create();
	attribute->initData(id, value, min, max);
	_poolAttribute.insert(id, attribute);
}

void Unit::deleteAttribute(const int& id)
{
	_poolAttribute.erase(id);
}

Attribute* Unit::getAttribute(const int& id) const
{
	auto attribute = _poolAttribute.at(id);
	return attribute;
}

void Unit::modifyAttributeValue(const int& id, const int& val)
{
	auto attribute = _poolAttribute.at(id);
	if (attribute == nullptr)
	{
		return;
	}
	attribute->modifyValue(val);
}

void Unit::modifyAttributeMin(const int& id, const int& val)
{
	auto attribute = _poolAttribute.at(id);
	if (attribute == nullptr)
	{
		return;
	}
	attribute->modifyMin(val);
}

void Unit::modifyAttributeMax(const int& id, const int& val)
{
	auto attribute = _poolAttribute.at(id);
	if (attribute == nullptr)
	{
		return;
	}
	attribute->modifyMax(val);
}
