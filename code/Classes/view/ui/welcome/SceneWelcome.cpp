#include "SceneWelcome.h"

SceneWelcome::SceneWelcome()
{
}

SceneWelcome::~SceneWelcome()
{
}

bool SceneWelcome::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(Scene::init());

		isInit = true;
	} while (0);

	return isInit;
}
