#ifndef __CORE_ENTITY_HANDLE_ACROSS_H__
#define __CORE_ENTITY_HANDLE_ACROSS_H__

#include "cocos2d.h"
#include "common/observer/Observer.h"
#include "ILayerAcross.h"
#include "ModelAcross.h"

class HandleAcross : public cocos2d::Ref
{
public:
	CREATE_FUNC(HandleAcross);

	HandleAcross();
	~HandleAcross();

	virtual bool init();

	void setLayerAcross(ILayerAcross* val) { _layerAcross = val; }

private:
	ILayerAcross* _layerAcross;
	ModelAcross* _modelAcross;

};

HandleAcross::HandleAcross() : _layerAcross(nullptr), _modelAcross(nullptr)
{
}

HandleAcross::~HandleAcross()
{
	_layerAcross = nullptr;
	CC_SAFE_RELEASE_NULL(_modelAcross);
}

bool HandleAcross::init()
{
	auto isInit = false;

	do 
	{

		_modelAcross = ModelAcross::create();
		_modelAcross->retain();

		isInit = true;
	} while (0);

	return isInit;
}

#endif
