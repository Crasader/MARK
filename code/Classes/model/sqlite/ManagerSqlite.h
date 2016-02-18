#ifndef _MODEL_SQLITE_MANAGER_SQLITE_H_
#define _MODEL_SQLITE_MANAGER_SQLITE_H_

#include "cocos2d.h"
#include "sqlite3.h"

USING_NS_CC;

class ManagerSqlite
{
public:
	static ManagerSqlite *getInstance();//提供getInstance全局指针
	static void destroyInstance();

public:
	~ManagerSqlite();

	void dataBaseOpen();
	void dataBaseClose();
	void tableCreate();
	void dataInsert();
	void dataQuery();
	void dataDelete();

private:
	ManagerSqlite();

	sqlite3 *_dataBase;//数据库指针

};

#endif
