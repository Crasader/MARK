#ifndef __GAME_UI_I_LAYER_IMAGE_LOAD_H__
#define __GAME_UI_I_LAYER_IMAGE_LOAD_H__

#include "common/define/DefinesNamespace.h"

NS_BEGIN_UI_COMMON

class ILayerResLoad
{
public:
	virtual void createSkin() {}
	virtual void playLoad() {}//播放加载动画
	virtual void stopLoad() {}//停止加载动画

};

NS_END_END

#endif