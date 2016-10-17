#include "LayerLogo.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "common/define/DefinesRes.h"

USING_NS_CC;
using namespace ui;

LayerLogo::LayerLogo() : _handleLogo(nullptr), _skin(nullptr)
{
}

LayerLogo::~LayerLogo()
{
	CC_SAFE_RELEASE_NULL(_handleLogo);
	_skin = nullptr;
}

bool LayerLogo::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		_handleLogo = HandleLogo::create();
		_handleLogo->retain();
		_handleLogo->setLayerLogo(this);

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerLogo::update(float delta)
{
	_handleLogo->update(delta);
}

void LayerLogo::createSkin()
{
	_skin = (Layer*)CSLoader::createNode(RES_WELCOME_LOGO_LAYER_LOGO_CSB);
	addChild(_skin);
}

void LayerLogo::playAnimation()
{
	auto actionTimeline = CSLoader::createTimeline(RES_WELCOME_LOGO_LAYER_LOGO_CSB);
	actionTimeline->play(ANIMATION_NAME, false);
	_skin->runAction(actionTimeline);
}
