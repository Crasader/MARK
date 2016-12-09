#ifndef __HANDLE_WELCOME_H__
#define __HANDLE_WELCOME_H__

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

	void update(float delta);

	void setSceneWelcome(ISceneWelcome* val) { _sceneWelcome = val; }

private:
	void createLayer(const TypeLayerInWelcome& type);
	void deleteLayer(const TypeLayerInWelcome& type);

	void playLogo();
	void addEventLayerLogoOver();
	void removeEventLayerLogoOver();
	void onEventLayerLogoOver(cocos2d::EventCustom* event);
	void playedLogo();

	void replaceSceneToGame();//ÇÐ»»ÎªÓÎÏ·³¡¾°

	ISceneWelcome* _sceneWelcome;
	ModelWelcome* _modelWelcome;

};

#endif