#pragma execution_character_set("utf-8")

#ifndef __HANDLE_RES_LOAD_H__
#define __HANDLE_RES_LOAD_H__

#include "cocos2d.h"
#include <string>
#include "ILayerResLoad.h"
#include "ModelResLoad.h"

class HandleResLoad : public cocos2d::Ref
{
public:
	CREATE_FUNC(HandleResLoad);

public:
	HandleResLoad();
	~HandleResLoad();

	virtual bool init();

	void update(float delta);

	void setLayerResLoad(ILayerResLoad* val) { _layerResLoad = val; }

private:
	void createSkin();

	void playLoadAnimation();
	void stopLoadAnimation();

	void loadSounds();
	void loadingSounds();
	void loadedSounds();
	
	void loadImages();
	/*º”‘ÿplistªÚpng
	fileName *.plistªÚ*.png*/
	void asyncLoadImage(const std::string& fileName);
	void asyncLoadImageCallback(cocos2d::Texture2D* texture, const std::string& fileName, const int& bitIndex);
	void loadedImages();

	ILayerResLoad* _layerResLoad;
	ModelResLoad* _modelResLoad;

};

#endif