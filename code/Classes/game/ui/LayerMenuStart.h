#ifndef __LAYER_MENU_START_H__
#define __LAYER_MENU_START_H__

#include "cocos2d.h"
#include "HandleMenuStart.h"
#include "ui/UIWidget.h"

class LayerMenuStartModel : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerMenuStartModel);

	LayerMenuStartModel();
	~LayerMenuStartModel();

	virtual bool init();

private:

};

class ILayerMenuStart
{
public:
	virtual cocos2d::Layer * getSkin() { return nullptr; }
};

class LayerMenuStartHandle : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerMenuStartHandle);

	LayerMenuStartHandle();
	~LayerMenuStartHandle();

	virtual bool init();

	void gameStart();
	void gameSaveLoad();
	void gameSetting();

	ILayerMenuStart * getLayerMenuStart() const { return _layerMenuStart; }
	void setLayerMenuStart(ILayerMenuStart * val) { _layerMenuStart = val; }

private:
	ILayerMenuStart *_layerMenuStart;
};

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
	LayerMenuStartHandle *_handleMenuStart;

};

#endif
