#ifndef __I_LAYER_MENU_SYSTEM_H__
#define __I_LAYER_MENU_SYSTEM_H__

#include "cocos2d.h"
#include "ui/UIButton.h"
#include "ui/UIWidget.h"

class ILayerMenuSystem
{
public:
	virtual void addLayer(cocos2d::Layer* layer) {}
	virtual void addEvent(cocos2d::ui::Button* btn, const std::string& titleName, const cocos2d::ui::Widget::ccWidgetTouchCallback& onTouch) {}
	virtual void playAnimation(cocos2d::Layer* layer, cocos2d::Action* action) {}
};
#endif