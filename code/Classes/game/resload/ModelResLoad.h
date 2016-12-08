#ifndef __MODEL_RES_LOAD_H__
#define __MODEL_RES_LOAD_H__

#include "cocos2d.h"
#include "common/define/DefinesNamespace.h"
#include <string>
#include <map>
#include "common/bitData/BitData.h"

enum class StateResLoad
{
	DEFAULT,
	CREATE_SKIN,
	UNLOAD_SOUND,
	LOADING_SOUND,
	LOADED_SOUND,
	UNLOAD_IMAGE,
	LOADING_IMAGE,
	LOADED_IMAGE
};

class ModelResLoad : public cocos2d::Ref
{
public:
	CREATE_FUNC(ModelResLoad);

	ModelResLoad();
	~ModelResLoad();

	virtual bool init();
	
	cocos2d::Node* getSkin();
	cocos2d::Node* getSpriteLoad();
	BitData* getBitData();

	CC_SYNTHESIZE(StateResLoad, _state, State);

private:
	cocos2d::Node* _skin;
	cocos2d::Node* _spriteLoad;
	BitData* _bitData;

};

#endif