#ifndef _MODEL_SQLITE_MANAGER_SQLITE_H_
#define _MODEL_SQLITE_MANAGER_SQLITE_H_

#include "cocos2d.h"
#include "sqlite3.h"

class ManagerSqlite
{
public:
	static const ManagerSqlite* getInstance()
	{
		return _instance;
	}//提供getInstance全局指针
	
	~ManagerSqlite();

	void dataBaseOpen();
	void dataBaseClose();
	void tableCreate();
	void dataInsert();
	void dataQuery();
	void dataDelete();

private:
	ManagerSqlite();
	ManagerSqlite(const ManagerSqlite&);
	ManagerSqlite& operator=(const ManagerSqlite&);

	static ManagerSqlite* _instance;

	sqlite3 *_dataBase;//数据库指针

};

#endif
