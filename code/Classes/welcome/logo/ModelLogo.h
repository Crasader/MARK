#ifndef __WELCOME_LOGO_MODEL_LOGO_H__
#define __WELCOME_LOGO_MODEL_LOGO_H__

#include "cocos2d.h"

enum class StateLogo
{
	SKIN_UNCREATE,
	SKIN_CREATED,
	LOGOPLAYING,
	LOGOOVER
};

class ModelLogo : public cocos2d::Ref
{
public:
	CREATE_FUNC(ModelLogo);

	ModelLogo();
	~ModelLogo();

	virtual bool init();

	void addDuration(float val);
	bool isTimeOver();

	CC_SYNTHESIZE(StateLogo, _state, State);

private:
	float _duration;

	const float DURATION_TOTAL = 3.0f;

};

#endif