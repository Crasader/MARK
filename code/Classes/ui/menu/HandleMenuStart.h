#ifndef __UI_MENU_HADLE_MENU_START_H__
#define __UI_MENU_HADLE_MENU_START_H__

#include "cocos2d.h"
#include "IMenu.h"

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