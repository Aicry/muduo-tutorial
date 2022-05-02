#ifndef _DAO_H
#define _DAO_H

#include<iostream>
#include<string>
#include<map>
#include"MyDB.h"
using namespace std;

struct StudentMsg
{
 string Id;
 string pwd; 
 string name;
 string college;
 string major;
 string stuClass;
 string submitdays;
};

struct AdminLoginMsg
{
  string Id;
  string pwd;
  string name;
  string college;
};

struct SuperAdminMsg
{
  string Id;
  string pwd;
};

struct DailySubmitMsg
{
  string Id;
  string address;
  string inSchool;
  string inCity ;
  string temperature;
  string healthy;
  string personType;
  string relative;
  string note;
  string date;
};



class Dao
{

public:
 StudentMsg StringToStudentMsg(string param);
 DailySubmitMsg StringToDailySubmitMsg(string param);
 string Register(string param);
 void StringToBuf(string param);
 string StudentLogin(string param);
 string StudentSubmit(string param);
 string StudentMsgToString(StudentMsg msg);
private:
 char Buf[500];
};









#endif