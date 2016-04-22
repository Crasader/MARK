#include "AttributeValue.h"

AttributeValue::AttributeValue()
{
}

AttributeValue::~AttributeValue()
{
}

bool AttributeValue::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Attribute::init());

		isInit = true;
	} while (0);

	return isInit;
}

void AttributeValue::modifyValue(int val)
{
	auto temp = _value + val;
	if (temp < _min)//���޸ĺ�ǰֵС����Сֵ
	{
		_value = _min;//��ǰֵ��ֵΪ��Сֵ
	}
	else if (temp > _max)//���޸ĺ�ǰֵ�������ֵ
	{
		_value = _max;//��ǰֵ��ֵΪ���ֵ
	}
	else
	{
		_value = temp;
	}
}

void AttributeValue::modifyMin(int val)
{
	auto temp = _min + val;
	if (temp > _max)//���޸ĺ���Сֵ�������ֵ
	{
		temp = _max;
		_value = _max;
	}
	else if (temp > _value)//���޸ĺ���Сֵ���ڵ�ǰֵ
	{
		_value = temp;
	}
	_min = temp;
}

void AttributeValue::modifyMax(int val)
{
	auto temp = _max + val;
	if (temp < _min)//���޸ĺ����ֵС����Сֵ
	{
		temp = _min;
		_value = _min;
	}
	else if (temp < _value)//���޸ĺ����ֵС�ڵ�ǰֵ
	{
		_value = temp;
	}
	_max = temp;
}
