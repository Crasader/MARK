#include "SceneMain.h"

USING_NS_CC;

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
