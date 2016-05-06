#ifndef __UI_MENU_HANDLE_MENU_SYSTEM_H__
#define __UI_MENU_HANDLE_MENU_SYSTEM_H__

#include "cocos2d.h"
#include "ILayerMenuSystem.h"

class HandleMenuSystem : public cocos2d::Ref
{
public:
	CREATE_FUNC(HandleMenuSystem);

	HandleMenuSystem();
	~HandleMenuSystem();

	virtual bool init();

	void setLayerMenuSystem(ILayerMenuSystem* val) { _layerMenuSystem = val; }

	void gameSetting();//开关游戏设置层
	void gameSounds();//开关游戏声效

private:
	ILayerMenuSystem* _layerMenuSystem;

};

#endif