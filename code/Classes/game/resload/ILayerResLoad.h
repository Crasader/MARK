#ifndef __I_LAYER_RES_LOAD_H__
#define __I_LAYER_RES_LOAD_H__

#include "cocos2d.h"

class ILayerResLoad
{
public:
	virtual void addSkin(cocos2d::Node* skin) {}
	virtual void playLoadAnimation(cocos2d::Node* node) {}//���ż��ض���
	virtual void stopLoadAnimation(cocos2d::Node* node) {}//ֹͣ���ض���

};

#endif