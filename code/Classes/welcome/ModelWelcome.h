#ifndef __WELCOME_MODEL_WELCOME_H__
#define __WELCOME_MODEL_WELCOME_H__

#include "cocos2d.h"

class ModelWelcome : public cocos2d::Ref
{
public:
	CREATE_FUNC(ModelWelcome);

	ModelWelcome();
	~ModelWelcome();

	virtual bool init();

	cocos2d::EventListenerCustom* getEventListener() const { return _listener; }
	void setEventListener(cocos2d::EventListenerCustom* val) { _listener = val; }

private:
	cocos2d::EventListenerCustom* _listener;
};

#endif