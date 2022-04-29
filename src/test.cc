#include<iostream>

#include<sstream>
using namespace std;


int main()
{
    string a="select * from user_Tab where userId = '000124' and pwd = 'hhh';";
   const char * res =a.c_str();
    cout<<res;
}
