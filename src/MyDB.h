#ifndef _MYDB_H
#define _MYDB_H
#include<iostream>
#include<string>
#include<mysql.h>
#include<vector>
#include"Dao.h"
using namespace std;


class MyDB
{
    public:
    MyDB();
    ~MyDB();
    bool initDB(string host,string user,string pwd,string db_name); //连接mysql
    vector<string> loginSQL(string sql);
    string RegisterSQL(string sql);
    bool submitSQL(string sql);
    private:
    MYSQL *mysql;          //连接mysql句柄指针
    MYSQL_RES *result;    //指向查询结果的指针
    MYSQL_ROW row;       //按行返回的查询信息
};


#endif

