#ifndef __UI_COMMON_I_LAYER_IMAGE_LOAD_H__
#define __UI_COMMON_I_LAYER_IMAGE_LOAD_H__

#include "model/define/DefinesNamespace.h"

NS_BEGIN_UI_COMMON

class ILayerResLoad
{
public:
	virtual void createSkin() {}
	virtual void playLoad() {}//���ż��ض���
	virtual void stopLoad() {}//ֹͣ���ض���

};

NS_END_END

#endif