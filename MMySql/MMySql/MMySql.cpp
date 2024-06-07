#include "pch.h"
#include <iostream>
#include<string>
#include<mysql.h>
using namespace std;

struct Student
{
	string name;
	int age;
	double score;
};

const char* host = "127.0.0.1";
const char* user = "root";
const char* psw = "123456";
const char* database_name = "ship_test";
const int port = 3306;

class MMSql
{
public:
	MMSql();
	~MMSql();
	MYSQL * getConnect();
	void updateID();
	void addToMySQL();
	void delToMySQL();
	void editToMySQL();
	void findToMySQL();
private:
	MYSQL *con;
};

MMSql::MMSql()
{
	//初始化mysql
	con = mysql_init(0);
	//VS的编译方式为GBK,因此设置MYSQL的编码方式为GBK
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

	//连接数据库
	if (!mysql_real_connect(con, host, user, psw, database_name, port, NULL, 0))
	{
		cout << mysql_error(con) << endl;
	}

}

MMSql::~MMSql()
{
	mysql_close(this->getConnect());
}

MYSQL * MMSql::getConnect()
{
	return this->con;
}

void MMSql::updateID()
{
	/////////////////////删除后重新整理id的编号/////////////////////
	const char* query[] = {
		//更新id字段的值，重新从1开始编号
		"SET @new_id = 0;",
		"UPDATE ship01 SET id = @new_id:=@new_id+1;",
		//重新设置自增序列的最小值为1
		"ALTER TABLE ship01 AUTO_INCREMENT = 1;"
	};

	// 执行多条Query语句
	int num_queries = sizeof(query) / sizeof(query[0]);
	for (int i = 0; i < num_queries; ++i) {
		if (mysql_query(this->getConnect(), query[i]) != 0) {
			cout << "执行Query语句失败: " << mysql_error(this->getConnect()) << endl;
			return ;
		}
	}
}

void MMSql::addToMySQL()
{
	Student stu;
	stu.name = "xiaowang";
	stu.age = 79;
	stu.score = 88.9;
	/////////////////////////////////增////////////////////////////
	//通过query插入数据
	string query = "INSERT INTO ship01 (`name`, age, score) VALUES ('" + stu.name + "', " + to_string(stu.age) + ", " + to_string(stu.score) + ")";

	if (mysql_query(this->getConnect(), query.c_str()) != 0)
	{
		cout << mysql_error(this->getConnect()) << endl;
		mysql_close(this->getConnect());
		return; // Exit the program with an error code
	}
	cout << "添加成功!" << "当前数据为:" << endl;
	this->updateID();//更新数据
	this->findToMySQL();
}

void MMSql::delToMySQL()
{
	///////////////////////////////删////////////////////////////////////////////////
//通过query删除数据
	string query2 = "DELETE FROM ship01 WHERE id=2;";
	if (mysql_query(this->getConnect(), query2.c_str()) != 0)
	{
		cout << mysql_error(this->getConnect()) << endl;
		mysql_close(this->getConnect());
		return; // Exit the program with an error code
	}
	cout << "删除成功!" << "当前数据为:" << endl;
	this->updateID();//更新数据
	this->findToMySQL();
}

void MMSql::editToMySQL()
{
	///////////////////////////////改////////////////////////////////////////
	int num1 = 39;
	string name1 = "fd";
	string query1 = "update ship01 set score=" + to_string(num1) + " where name = " +"'"+ name1 + "'";
	if (mysql_query(this->getConnect(), query1.c_str()) != 0)
	{
		cout << mysql_error(this->getConnect()) << endl;
		mysql_close(this->getConnect());
		return; // Exit the program with an error code
	}
	cout << "修改成功!" << "当前数据为:" << endl;
	this->findToMySQL();
}

void MMSql::findToMySQL()
{
	////////////////////////////////////查//////////////////////////////////
//通过query查询数据
	mysql_query(this->getConnect(), "SELECT * FROM ship01");
	//使用res收集查询到的数据
	MYSQL_RES *res = mysql_store_result(this->getConnect());
	if (!res)
	{
		cout << mysql_error(this->getConnect()) << endl;
		mysql_close(this->getConnect());
		return; // Exit the program with an error code
	}
	//取得收集到的数据的行数(便于遍历)
	int num_fields = mysql_num_fields(res);
	//取每一行的数据,打印
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			cout << row[i] << " ";
		}
		cout << endl;
	}
	//释放收集的数据
	mysql_free_result(res);
}


int main()
{
	MMSql *mysq = new MMSql();
	mysq->addToMySQL();

	//mysq->editToMySQL();

	//mysq->delToMySQL();

	cout << "Hello World!\n";
	return 0;
}
