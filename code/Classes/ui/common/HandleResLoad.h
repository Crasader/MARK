#pragma execution_character_set("utf-8")

#ifndef __UI_WELCOME_HANDLE_IMAGE_LOAD__
#define __UI_WELCOME_HANDLE_IMAGE_LOAD__

#include "cocos2d.h"
#include <string>
#include "model/define/DefinesValue.h"
#include "ILayerResLoad.h"
#include "ModelResLoad.h"
#include "common/bitData/BitData.h"

NS_BEGIN_UI_COMMON

class HandleResLoad : public cocos2d::Ref
{
public:
	CREATE_FUNC(HandleResLoad);

public:
	HandleResLoad();
	~HandleResLoad();

	virtual bool init();

	void update(float delta);

	void setLayerResLoad(userInerface::common::ILayerResLoad* val) { _layerResLoad = val; }

private:
	void loadSounds();
	void loadedSounds();
	void loadImages();
	void loadedImages();

	/*º”‘ÿplistªÚpng
	fileName *.plistªÚ*.png*/
	void imageAsyncLoad(const std::string& fileName);

	void imageAsyncCallback(cocos2d::Texture2D* texture, const std::string& fileName, const int& bit);

	ILayerResLoad* _layerResLoad;
	ModelResLoad* _modelResLoad;

	BitData* _bitData;
	
};

NS_END_END

#endif