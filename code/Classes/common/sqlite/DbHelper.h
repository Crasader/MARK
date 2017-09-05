#ifndef __DB_HELPER_H__
#define __DB_HELPER_H__

#include "cocos2d.h"
#include "sqlite3.h"
#include <string>
#include <vector>
#include <map>

class DbHelper
{
public:
	static DbHelper* getInstance()
	{
		return _instance;
	}//提供getInstance全局指针
	
	~DbHelper();

	void dataBaseOpen();
	void dataBaseClose();
	void tableCreate(std::string tableName, int columnNum, ...);
	void dataInsert(std::string tableName, std::string values);
	void dataQuery(std::string tableName, std::string columnName, std::string condition = "");
	void dataDelete(std::string tableName, std::string condition /*= ""*/);

	void executeSql(std::string sql, std::vector<std::map<std::string, std::string>>* vec = nullptr);

private:
	DbHelper();
	DbHelper(const DbHelper&);
	DbHelper& operator=(const DbHelper&);

	static DbHelper* _instance;

	const std::string strDbName = "dataBase.db";
	const std::string strCrateTable = "create table ";
	
	const std::string strInsertInto = "insert into  ";
	const std::string strValueBegan = "values(";
	const std::string strValueEnd = ")";
	
	const std::string strSelect = "select ";
	const std::string strFrom = "from  ";

	const std::string strDeleteFrom = "delete from ";

	const std::string strWhere = "where ";

	sqlite3* _dataBase;//数据库指针
	
};

#endif
