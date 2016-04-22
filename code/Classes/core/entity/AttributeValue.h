#ifndef __CORE_ENTITY_ATTRIBUTE_VALUE_H__
#define __CORE_ENTITY_ATTRIBUTE_VALUE_H__

#include "Attribute.h"

/**
* 值属性类
* 具有一个受最小最大值约束的值
*/
class AttributeValue : public Attribute
{
public:
	CREATE_FUNC(AttributeValue);

	AttributeValue();
	~AttributeValue();

	virtual bool init();

	CC_SYNTHESIZE(int, _id, Id);
	CC_SYNTHESIZE(int, _value, Value);
	CC_SYNTHESIZE(int, _min, Min);
	CC_SYNTHESIZE(int, _max, Max);
	virtual void modifyValue(int val);
	virtual void modifyMin(int val);
	virtual void modifyMax(int val);

private:

};

#endif