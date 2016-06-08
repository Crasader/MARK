#include "Attribute.h"

USING_NS_GAME_ENTITY;

Attribute::Attribute()
{
}

Attribute::~Attribute()
{
}

bool Attribute::init()
{
	auto isInit = false;

	do
	{

		isInit = true;
	} while (0);

	return isInit;
}

void Attribute::initData(const int& id, const int& value, const int& min /*= 0*/, const int& max /*= INT_MAX*/)
{
	setValue(value);
	setMin(min);
	setMax(max);
}

void Attribute::modifyValue(int val)
{
	auto temp = _value + val;
	if (temp < _min)//若修改后当前值小于最小值
	{
		_value = _min;//当前值赋值为最小值
	}
	else if (temp > _max)//若修改后当前值大于最大值
	{
		_value = _max;//当前值赋值为最大值
	}
	else
	{
		_value = temp;
	}
}

void Attribute::modifyMin(int val)
{
	auto temp = _min + val;
	if (temp > _max)//若修改后最小值大于最大值
	{
		temp = _max;
		_value = _max;
	}
	else if (temp > _value)//若修改后最小值大于当前值
	{
		_value = temp;
	}
	_min = temp;
}

void Attribute::modifyMax(int val)
{
	auto temp = _max + val;
	if (temp < _min)//若修改后最大值小于最小值
	{
		temp = _min;
		_value = _min;
	}
	else if (temp < _value)//若修改后最大值小于当前值
	{
		_value = temp;
	}
	_max = temp;
}
