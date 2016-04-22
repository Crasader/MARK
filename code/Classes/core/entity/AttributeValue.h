#ifndef __CORE_ENTITY_ATTRIBUTE_VALUE_H__
#define __CORE_ENTITY_ATTRIBUTE_VALUE_H__

#include "Attribute.h"

/**
* ֵ������
* ����һ������С���ֵԼ����ֵ
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