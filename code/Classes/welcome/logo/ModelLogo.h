#ifndef __MODEL_LOGO_H__
#define __MODEL_LOGO_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

enum class StateLogo
{
	DEFLATE,
	CREATE_SKIN,
	UNPLAY_LOGO,
	PLAYING_LOGO,
	PLAYED_LOGO
};

#define LAYER_LOGO_ANIMATION_0 "animation0"

class ModelLogo : public cocos2d::Ref
{
public:
	CREATE_FUNC(ModelLogo);

	ModelLogo();
	~ModelLogo();

	virtual bool init();

	cocos2d::Layer* getSkin();
	cocostudio::timeline::ActionTimeline* getAnimation(const std::string& animationName, const bool& isLoop);

	void addDuration(float val);
	bool isTimeOver();

	CC_SYNTHESIZE(StateLogo, _state, State);

private:
	cocos2d::Layer* _skin;

	float _duration;
	const float DURATION_TOTAL = 3.0f;

};

#endif