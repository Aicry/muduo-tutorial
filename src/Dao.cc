#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include "Dao.h"
#include"MyDB.h"
#include "ajson/ajson.hpp"
using namespace std;
using namespace ajson;

AJSON(StudentMsg,Id,pwd,name,college,major,stuClass,submitdays);
AJSON(DailySubmitMsg,Id ,address ,inSchool ,inCity ,temperature ,healthy ,personType ,relative, note ,date)

void Dao::StringToBuf(string param){
    cout<<"check param"<<endl;
    cout<<param<<endl;
    int length=param.length();
    param.copy(Buf,length,0);
    *(Buf+length)='\0';  
}

StudentMsg Dao::StringToStudentMsg(string param){
  StringToBuf(param);
	StudentMsg msg;
	load_from_buff(msg,Buf);
	cout <<"StringToStudentMsg:" <<msg.Id << " " << msg.pwd <<" "<<msg.name<< std::endl;
  return msg;
}

DailySubmitMsg Dao::StringToDailySubmitMsg(string param){
  StringToBuf(param);
	DailySubmitMsg msg;
	load_from_buff(msg,Buf);
	cout <<"StringToDailySubmitMsg:" << std::endl;
  return msg;
}

string Dao::Register(string param){
  StudentMsg msg=StringToStudentMsg(param);
  string Id=msg.Id;
  string pwd=msg.pwd;
  string name=msg.name;
  string college=msg.college;
  string major= msg.major;
  string stuClass=msg.stuClass;
  string submitdays=msg.submitdays;
  MyDB db;
  db.initDB("localhost","root","521011","WeChatApp");
  /*(`Id`, `pwd`, `name`)*/
  string sql="INSERT INTO Student VALUES ('" +Id+  "', '"  +pwd+  "', '"+name+"', '"+college+"','"+major+"', '"+stuClass+"', '"+submitdays+"')";
  return db.RegisterSQL(sql);
}

string Dao::StudentMsgToString(StudentMsg msg){
       string_stream ss;
       save_to(ss,msg);
       cout<<"StudentMsgToString:"<<ss.str()<<endl;
       return ss.str();
}
string Dao::StudentLogin(string param){
  StudentMsg msg=StringToStudentMsg(param);
  cout <<"login_msg:" <<msg.Id << " " << msg.pwd <<" "<<msg.name<< std::endl;
  string Id=msg.Id;
  string pwd=msg.pwd;
  cout<<"StudentLogin"<<Id<<" "<<pwd<<" "<<endl;
  MyDB db;
  db.initDB("localhost","root","521011","WeChatApp");
  cout<<"test1"<<endl;
  string sql="testsql";
  cout<<"login_sql:"<<sql<<endl;
  sql="select * from Student where Id = '" +Id+ "' and pwd = '" +pwd+ "'";
  cout<<"login_sql:"<<sql<<endl;
  vector<string> res;
  res = db.loginSQL(sql);
  if(res.size()>1){
  msg.name =res[3];
  msg.college=res[4];
  msg.major=res[5];
  msg.stuClass=res[6];
  msg.submitdays=res[7];
  }
  return StudentMsgToString(msg);
}


string Dao::StudentSubmit(string param){
  DailySubmitMsg msg=StringToDailySubmitMsg(param);
  MyDB db;
  db.initDB("localhost","root","521011","WeChatApp");
  cout<<"StudentSubmit"<<endl;
  string Id=msg.Id;
  string address=msg.address;
  string inSchool=msg.inSchool;
  string inCity=msg.inCity;
  string temperature=msg.temperature;
  string healthy=msg.healthy;
  string personType=msg.personType;
  string relative=msg.relative;
  string note=msg.note;
  string date=msg.date;
  /*(`Id`, `address`, `inSchool`, `inCity`, `temperature`, `healthy`, `personType`, `relative`, `note`, `date`)*/
  string sql="INSERT INTO DailySubmit VALUES ('"+Id+"', '"+address+"', '"+inSchool+"','"+inCity+"','"  +temperature+  "','"+healthy+"','"+personType+"','"+relative+"','"+note+"','"+date+"')";
  cout<<"submitSQL:"<<sql<<endl;
  string result;
  result = db.submitSQL(sql);
  return result;
}



