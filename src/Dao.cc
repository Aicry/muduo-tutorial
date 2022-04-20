#include<iostream>
#include<string>
#include "MyDB.h"

using namespace std;

class Dao::Dao()
{

}

string Dao::loginCheck(string param){
    //MyDB db; 
    //连接数据库
    db.initDB("localhost","root","521011","WeChatApp");
   
    db.exeSQL("SELECT * from user_Tab;");
   
    return "test";
}

