#ifndef __HANDLE_LOGO_H__
#define __HANDLE_LOGO_H__

#include "cocos2d.h"
#include "ILayerLogo.h"
#include "ModelLogo.h"

class HandleLogo : public cocos2d::Ref
{
public:
	CREATE_FUNC(HandleLogo);

	HandleLogo();
	~HandleLogo();

	virtual bool init();

	void update(float delta);

	void setLayerLogo(ILayerLogo* val) { _layerLogo = val; }
	
private:
	void createSkin();
	void playLogo();
	void playingLogo(float delta);
	void playedLogo();

	ILayerLogo* _layerLogo;
	ModelLogo* _modelLogo;

};

#endif