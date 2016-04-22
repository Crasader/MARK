#pragma execution_character_set("utf-8")

#include "LayerResLoad.h"
#include "model/define/DefinesRes.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_UI_COMMON;
using namespace std;
using namespace cocos2d::ui;

LayerResLoad::LayerResLoad() : _skin(nullptr), _handleImageLoad(nullptr)
{
}

LayerResLoad::~LayerResLoad()
{
	_skin = nullptr;
	CC_SAFE_RELEASE_NULL(_handleImageLoad);
}

bool LayerResLoad::init()
{
	auto isInit = false;

	do 
	{
		CC_BREAK_IF(!Layer::init());

		_handleImageLoad = HandleResLoad::create();
		_handleImageLoad->retain();
		_handleImageLoad->setLayerResLoad(this);

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerResLoad::update(float delta)
{
	_handleImageLoad->update(delta);
}

void LayerResLoad::createSkin()
{
	_skin = CSLoader::createNode(RES_UI_COMMON_LAYER_RES_LOAD_CSB);
	addChild(_skin);

	/*auto actionTimeline = CSLoader::createTimeline(RES_MODULES_WELCOME_SCENE_WELCOME_CSB);
	actionTimeline->gotoFrameAndPlay(0, true);
	skin->runAction(actionTimeline);*/
}

void LayerResLoad::playLoad()
{
	auto spriteLoad = (Sprite *)_skin->getChildByName(SPRITELOAD);
	spriteLoad->runAction(RepeatForever::create(RotateBy::create(3.0f, 360.0f)));
}

void LayerResLoad::stopLoad()
{
	auto spriteLoad = (Sprite *)_skin->getChildByName(SPRITELOAD);
	spriteLoad->stopAllActions();
}
