#ifndef __UI_COMMON_MODEL_RES_LOAD_H__
#define __UI_COMMON_MODEL_RES_LOAD_H__

#include "cocos2d.h"
#include "model/define/DefinesNamespace.h"
#include <string>
#include <map>

NS_BEGIN_UI_COMMON

enum class StateResLoad
{
	UNINIT,
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
	
	CC_SYNTHESIZE(StateResLoad, _state, State);
	CC_SYNTHESIZE(int, _numPlistNeedLoad, NumPlistNeedLoad);

private:

};

NS_END_END

#endif