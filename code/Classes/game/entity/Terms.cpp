#include "Terms.h"

USING_NS_GAME_ENTITY;

Terms::Terms()
{
}

Terms::~Terms()
{
	_args.clear();
}

bool Terms::init()
{
	auto isInit = false;

	do
	{

		isInit = true;
	} while (0);

	return isInit;
}

void Terms::initData(const int& id, const int& count, va_list values)
{
	setId(id);
	setCount(count);

	auto temp = getCount();
	while (temp--)
	{
		auto idAttribute = va_arg(values, int);
		auto valueAttribute = va_arg(values, int);
		auto attribute = Attribute::create();
		attribute->initData(idAttribute, valueAttribute);
		_args.pushBack(attribute);
	}
}
