#ifndef __CORE_ENTITY_ATTRIBUTE_TERMS_H__
#define __CORE_ENTITY_ATTRIBUTE_TERMS_H__

#include "cocos2d.h"
#include "Attribute.h"
#include "common/define/DefinesNamespace.h"

NS_BEGIN_GAME_ENTITY

/**
* ����������
* ���в�����
*/
class Terms : public cocos2d::Ref
{
public:
	CREATE_FUNC(Terms);

	Terms();
	~Terms();

	virtual bool init();
	virtual void initData(const int& id, const int& count, va_list values);

	CC_SYNTHESIZE(int, _id, Id);
	CC_SYNTHESIZE(int, _count, Count);//��������

private:
	cocos2d::Vector<Attribute*> _args;//������

};

NS_END_END

#endif