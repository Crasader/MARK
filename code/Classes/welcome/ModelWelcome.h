#ifndef __MODEL_WELCOME_H__
#define __MODEL_WELCOME_H__

#include "cocos2d.h"

enum class StateWelcome
{
	DEFAULT,
	UNPLAY_LOGO,
	PLAYING_LOGO,
	PLAYED_LOGO,
	REPLACE_SCENE_TO_GAME
};

enum class TypeLayerInWelcome
{
	LOGO,
	
};

class ModelWelcome : public cocos2d::Ref
{
public:
	CREATE_FUNC(ModelWelcome);

	ModelWelcome();
	~ModelWelcome();

	virtual bool init();

	cocos2d::Layer* getLayer(const TypeLayerInWelcome& type);
	void setLayerNullptr(const TypeLayerInWelcome& type);

	CC_SYNTHESIZE(cocos2d::EventListenerCustom*, _listenerLayerLogoOver, ListenerLayerLogoOver);
	CC_SYNTHESIZE(StateWelcome, _state, StateWelcome);

private:
	cocos2d::Layer* createLayerByType(const TypeLayerInWelcome& type);
	bool insertLayerByType(const TypeLayerInWelcome& type, cocos2d::Layer* layer);
	bool eraseLayerByType(const TypeLayerInWelcome& type);
	cocos2d::Layer* getLayerByType(const TypeLayerInWelcome& type);

	cocos2d::Map<TypeLayerInWelcome, cocos2d::Layer*> _dicLayers;

};

#endif