#include "ModelGame.h"
#include "common/sqlite/DbHelper.h"

USING_NS_CC;

ModelGame::ModelGame()
{
}

ModelGame::~ModelGame()
{
}

bool ModelGame::init()
{
	auto isInit = false;

	do
	{
		
		isInit = true;
	} while (0);

	return isInit;
}

void ModelGame::createDatabase()
{
	auto dbHelper = DbHelper::getInstance();
	dbHelper->dataBaseOpen();
	/*dbHelper->tableCreate();*/
	dbHelper->dataBaseClose();
}
