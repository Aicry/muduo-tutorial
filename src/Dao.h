#ifndef _DAO_H
#define _DAO_H

#include<iostream>
#include<string>
#include<map>
#include"MyDB.h"
using namespace std;
struct loginMsg
{
  string userName;
  string userId;
  string pwd;
};




class Dao
{

public:
 loginMsg StringToMsg(string param);
 string Register(string param);
 void StringToBuf(string param);
 string login(string param);

private:
 char Buf[500];
};









#endif