#ifndef __WELCOME_HANDLE_WELCOME_H__
#define __WELCOME_HANDLE_WELCOME_H__

#include "cocos2d.h"
#include "ISceneWelcome.h"
#include "ModelWelcome.h"

class HandleWelcome : public cocos2d::Ref
{
public:
	CREATE_FUNC(HandleWelcome);

	HandleWelcome();
	~HandleWelcome();

	virtual bool init();

	void onEventLayerLogoOver(cocos2d::EventCustom* event);
	void replaceSceneToGame();//ÇÐ»»ÎªÓÎÏ·³¡¾°

	void setSceneWelcome(ISceneWelcome* val) { _sceneWelcome = val; }

private:
	ISceneWelcome* _sceneWelcome;
	ModelWelcome* _modelWelcome;

};

#endif