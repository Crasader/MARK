#include "SceneWelcome.h"

SceneWelcome::SceneWelcome() : _handleWelcome(nullptr), _layerLogo(nullptr)
{
}

SceneWelcome::~SceneWelcome()
{
	CC_SAFE_RELEASE_NULL(_handleWelcome);
	layerLogoRemove();
}

bool SceneWelcome::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Scene::init());

		_handleWelcome = HandleWelcome::create();
		_handleWelcome->retain();
		_handleWelcome->setSceneWelcome(this);

		layerLogoAdd();

		isInit = true;
	} while (0);

	return isInit;
}

void SceneWelcome::layerLogoAdd()
{
	if (!_layerLogo)
	{
		_layerLogo = LayerLogo::create();
		addChild(_layerLogo);
	}
}

void SceneWelcome::layerLogoRemove()
{
	if (_layerLogo)
	{
		_layerLogo->removeFromParent();
		_layerLogo = nullptr;
	}
}
