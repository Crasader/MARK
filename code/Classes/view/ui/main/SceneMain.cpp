#include "SceneMain.h"

SceneMain::SceneMain()
{
}

SceneMain::~SceneMain()
{
}


bool SceneMain::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(Scene::init());

		isInit = true;
	} while (0);

	return isInit;
}
