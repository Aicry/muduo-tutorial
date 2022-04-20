#include<iostream>
#include"MyDB.hh"
#include<sstream>
using namespace std;


int main()
{
    MyDB db; 
    //连接数据库
    db.initDB("localhost","root","521011","WeChatApp");
   
    db.exeSQL("SELECT * from user_Tab;");
   
    return 0;
}
