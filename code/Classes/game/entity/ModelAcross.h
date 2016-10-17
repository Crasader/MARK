#ifndef __CORE_ENTITY_MODEL_ACROSS_H__
#define __CORE_ENTITY_MODEL_ACROSS_H__

#include "cocos2d.h"

class ModelAcross : public cocos2d::Ref
{
public:
	CREATE_FUNC(ModelAcross);

	ModelAcross();
	~ModelAcross();

	virtual bool init();

private:

};

ModelAcross::ModelAcross()
{
}

ModelAcross::~ModelAcross()
{
}

bool ModelAcross::init()
{
	auto isInit = false;

	do 
	{

		isInit = true;
	} while (0);

	return isInit;
}

#endif
