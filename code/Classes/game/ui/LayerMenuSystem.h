#ifndef __GAME_UI_LAYER_MENU_SYSTEM_H__
#define __GAME_UI_LAYER_MENU_SYSTEM_H__

#include "ILayerMenuSystem.h"
#include "HandleMenuSystem.h"
#include "ui/UIWidget.h"

class LayerMenuSystem : public cocos2d::Layer, ILayerMenuSystem
{
public:
	CREATE_FUNC(LayerMenuSystem);

	LayerMenuSystem();
	~LayerMenuSystem();

	virtual bool init();

	void onTouchBtn(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);

private:
	const std::string btn0 = "btn0";
	const std::string btn1 = "btn1";

	cocos2d::Layer *_skin;
	HandleMenuSystem* _handleMenuSystem;

};

#endif