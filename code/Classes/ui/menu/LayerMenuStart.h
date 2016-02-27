#ifndef _UI_MENU_LAYER_MENU_START_H_
#define _UI_MENU_LAYER_MENU_START_H_

#include "cocos2d.h"
#include "HandleMenuStart.h"
#include "ui/UIWidget.h"

class LayerMenuStart : public cocos2d::Layer, ILayerMenuStart
{
public:
	CREATE_FUNC(LayerMenuStart);

	LayerMenuStart();
	~LayerMenuStart();

	virtual bool init();

	void onTouchBtn(cocos2d::Ref *ref, cocos2d::ui::Widget::TouchEventType type);

	virtual cocos2d::Layer * getSkin() { return _skin; }

private:
	const std::string btn0 = "btn0";
	const std::string btn1 = "btn1";
	const std::string btn2 = "btn2";

	cocos2d::Layer *_skin;
	HandleMenuStart *_handleMenuStart;

};

#endif
