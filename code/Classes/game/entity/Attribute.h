#ifndef __CORE_ENTITY_DATA_ENTITY_H__
#define __CORE_ENTITY_DATA_ENTITY_H__

#include "cocos2d.h"
#include "defines/DefinesNamespace.h"

NS_BEGIN_GAME_ENTITY

/**
* 属性类
* 具有一个受最小最大值约束的值
*/
class Attribute : public cocos2d::Ref
{
public:
	CREATE_FUNC(Attribute);

	Attribute();
	~Attribute();

	virtual bool init();
	virtual void initData(const int& id, const int& value, const int& min = 0, const int& max = INT_MAX);

	CC_SYNTHESIZE(int, _id, Id);
	CC_SYNTHESIZE(int, _value, Value);
	CC_SYNTHESIZE(int, _min, Min);
	CC_SYNTHESIZE(int, _max, Max);
	virtual void modifyValue(int val);
	virtual void modifyMin(int val);
	virtual void modifyMax(int val);

private:

};

NS_END_END

#endif