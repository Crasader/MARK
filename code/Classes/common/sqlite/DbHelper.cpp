#include "DbHelper.h"

USING_NS_CC;
using namespace std;

DbHelper* DbHelper::_instance = new DbHelper();

DbHelper::~DbHelper()
{
	_dataBase = nullptr;
}

void DbHelper::dataBaseOpen()
{
	if (!_dataBase)//若数据库未开启
	{
		auto path = FileUtils::getInstance()->getWritablePath() + strDbName;//指定数据库的路径

		auto result = sqlite3_open(path.c_str(), &_dataBase);//打开一个数据库，如果该数据库不存在，则创建一个数据库文件
		if (result != SQLITE_OK)
		{
			log("ManagerSqlite::dataBaseOpen open database failed,  number%d", result);
		}
	}
}

void DbHelper::dataBaseClose()
{
	sqlite3_close(_dataBase);
}

void DbHelper::tableCreate(std::string tableName, int columnNum, ...)
{
	//"create table student(ID integer primary key autoincrement,name text,sex text)"
	
	auto sql = strCrateTable + tableName + "(";//创建表
	va_list values;
	va_start(values, columnNum);
	while (columnNum--)
	{
		auto columnName = va_arg(values,string);
		auto columnType = va_arg(values, string);
		sql += columnName + " " + columnType + (columnNum ? "," : "");
	}
	va_end(values);
	
	executeSql(sql);
}

void DbHelper::dataInsert(std::string tableName, std::string values)
{
	//"insert into student values(1,'student1','male')"//向表中插入1条数据
	
	auto sql = strInsertInto + tableName + values;
	executeSql(sql);
}

void DbHelper::dataQuery(std::string tableName, std::string columnName, std::string condition /*= ""*/)
{
	/*char **result;//查询结果
	int r, c;//行、列
	std::string sql = "select * from student";

	sqlite3_get_table(_dataBase, sql.c_str(), &result, &r, &c, nullptr);
	log("ManagerSqlite::dataQuery row is %d,column is %d", r, c);
	for (auto i = 1; i < r; i++)
	{
		for (auto j = 0; j < c; j++)
		{
			log("%s", result[i * c + j]);
		}
	}
	sqlite3_free_table(result);*/

	auto sql = strSelect + columnName + strFrom + (condition != "" ? strWhere + condition : "");
	executeSql(sql);
}

void DbHelper::dataDelete(std::string tableName, std::string condition /*= ""*/)
{
	//"delete from student where ID=1"; //删除ID = 1的学生

	std::string sql = strDeleteFrom + tableName + (condition != "" ? strWhere + condition : "");
	executeSql(sql);
}

void DbHelper::executeSql(std::string sql, std::vector<std::map<std::string, std::string>>* vec /*= nullptr*/)
{
	dataBaseOpen();

	auto isSelect = vec != nullptr && sql.find(strSelect) != string::npos;

	char* errmsg;
	auto result = sqlite3_exec(_dataBase, sql.c_str(), (isSelect ? loadData : nullptr), (isSelect ? vec : nullptr), &errmsg);
	if (result != SQLITE_OK)
	{
		log("ManagerSqlite::executeSql failed result:%d errmsg%s", result, errmsg);
	}

	dataBaseClose();
}

int loadData(void* para, int columnNum, char** columnValue, char** columnName)
{
	map<string, string> dic;
	for (auto i = 0; i < columnNum; i++)
	{
		dic.insert(make_pair<string, string>((string)columnName[i], (string)columnValue[i]));
	}
	auto vec = (vector<map<string, string>>*)para;
	vec->push_back(dic);
	return 0;
}

DbHelper::DbHelper() : _dataBase(nullptr)
{
}

DbHelper::DbHelper(const DbHelper&)
{

}

DbHelper& DbHelper::operator=(const DbHelper&)
{
	return *_instance;
}
