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

	void gameSetting();//������Ϸ���ò�
	void gameSounds();//������Ϸ��Ч

private:
	ILayerMenuSystem* _layerMenuSystem;

};

#endif