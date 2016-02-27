#ifndef _UI_MENU_HADLE_MENU_START_H_
#define _UI_MENU_HADLE_MENU_START_H_

#include "cocos2d.h"

class ILayerMenuStart
{
public:
	virtual cocos2d::Layer * getSkin() { return nullptr; }
};

class HandleMenuStart : public cocos2d::Ref
{
public:
	CREATE_FUNC(HandleMenuStart);

	HandleMenuStart();
	~HandleMenuStart();

	virtual bool init();

	void gameStart();
	void gameSaveLoad();
	void gameSetting();

	ILayerMenuStart * getLayerMenuStart() const { return _layerMenuStart; }
	void setLayerMenuStart(ILayerMenuStart * val) { _layerMenuStart = val; }

private:
	ILayerMenuStart *_layerMenuStart;
};

#endif