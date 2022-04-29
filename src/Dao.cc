#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include "Dao.h"
#include"MyDB.h"
#include "ajson/ajson.hpp"
using namespace std;
using namespace ajson;

AJSON(loginMsg,userId,pwd,userName);


void Dao::StringToBuf(string param){
    cout<<"check param"<<endl;
    cout<<param<<endl;
    int length=param.length();
    param.copy(Buf,length,0);
    *(Buf+length)='\0';  
}

loginMsg Dao::StringToMsg(string param){
  StringToBuf(param);
	loginMsg msg;
	load_from_buff(msg,Buf);
	cout <<"StringToMsg:" <<msg.userId << " " << msg.pwd <<" "<<msg.userName<< std::endl;
  return msg;
}

string Dao::Register(string param){
  loginMsg msg=StringToMsg(param);
  string userId=msg.userId;
  string pwd=msg.pwd;
  string userName=msg.userName;
  MyDB db;
  db.initDB("localhost","root","521011","WeChatApp");
  string sql="INSERT INTO user(`userId`, `pwd`, `userName`) VALUES ('" +userId+  "', '"  +pwd+  "', '"+userName+"')";
  return db.RegisterSQL(sql);
}

string Dao::login(string param){
  loginMsg msg=StringToMsg(param);
  cout <<"login_msg:" <<msg.userId << " " << msg.pwd <<" "<<msg.userName<< std::endl;
  string userId=msg.userId;
  string pwd=msg.pwd;
  cout<<"test"<<userId<<" "<<pwd<<" "<<endl;
  MyDB db;
  
  db.initDB("localhost","root","521011","WeChatApp");
  cout<<"test1"<<endl;
  string sql="testsql";
  cout<<"login_sql:"<<sql<<endl;

  sql="select * from user where userId = '" +userId+ "' and pwd = '" +pwd+ "'";
  
  cout<<"login_sql:"<<sql<<endl;

  string userName;
  userName = db.loginSQL(sql);
  return userName;
}



