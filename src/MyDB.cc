#include<iostream>
#include<string>
#include "MyDB.h"
#include "Dao.h"
using namespace std;

MyDB::MyDB()
{
    mysql=mysql_init(NULL);   
    if(mysql==NULL)
    {
        cout<<"Error:"<<mysql_error(mysql);
        exit(1);
    }
}

MyDB::~MyDB()
{
    if(mysql!=NULL)  
    {
        mysql_close(mysql);
    }
}


bool MyDB::initDB(string host,string user,string passwd,string db_name)
{
     
    mysql = mysql_real_connect(mysql, host.c_str(), user.c_str(), passwd.c_str(), db_name.c_str(), 0, NULL, 0);  
    if(mysql == NULL)  
    {  
        cout << "Error: " << mysql_error(mysql);  
        exit(1);  
    }  
    return true;  
}

vector<string> MyDB::loginSQL(string sql)
{
    vector<string> res;
    res.push_back("fail");
    cout<<"loginSQL_BEGIN"<<endl;
   
    if (mysql_query(mysql,sql.c_str()))
    {
        cout<<"Query Error: "<<endl;
        cout<<mysql_error(mysql)<<endl;
        return res;
    }
    else 
    {
        cout<<"Query Success: "<<endl;
        result = mysql_store_result(mysql);  //获取结果集
        int  num_rows=mysql_num_rows(result);  
        int  num_fields = mysql_num_fields(result); 
        cout<<"num_rows"<<num_rows<<endl;   
        if(num_rows==0)return res;//查出空行  
        row=mysql_fetch_row(result);   
        for(int i=0;i<num_fields;i++){
          res.push_back(row[i]);
        }     
        
        return res;
       
    }
    cout<<"loginSQL_END"<<endl;
    return res;

}

// string MyDB::loginSQL(string sql)
// {
    
//     cout<<"loginSQL_BEGIN"<<endl;
//     string userName="";
//     cout<<"test1"<<endl;
//     if (mysql_query(mysql,sql.c_str()))
//     {
//         cout<<"Query Error: ";
//         cout<<mysql_error(mysql)<<endl;
//         return "false";
//     }
//     else 
//     {
//         cout<<"Query Success: ";

//         int  num_rows=mysql_num_rows(result);  
//         cout<<"num_rows"<<num_rows<<endl;   
//         if(num_rows==0)return "false";//查出空行
//         result = mysql_store_result(mysql);       
//         row=mysql_fetch_row(result);    
//         userName=row[2];  
//         cout<<row[0]<<"     "<<row[1]<<"    "<< row[2]<<endl;          
//         cout<<"userName :"<<userName<<endl;
//         return userName;
       
//     }
//     cout<<"loginSQL_END"<<endl;
//     return "false";

// }

string MyDB::RegisterSQL(string sql)
{
    cout<<sql<<endl;
    //mysql_query()执行成功返回0,执行失败返回非0值。
    if (mysql_query(mysql,sql.c_str()))
    {
        cout<<"Query Error: "<<mysql_error(mysql);
        return "fail";
    }
   else
        {
            if(mysql_field_count(mysql) == 0)   //代表执行的是update,insert,delete类的非查询语句
            {
                // (it was not a SELECT)
                int num_rows = mysql_affected_rows(mysql);  //返回update,insert,delete影响的行数
            }
            else // error
            {
                cout<<"Get result error: "<<mysql_error(mysql);
                return "fail";
            }
        }
    
    return "success";

}


bool MyDB::submitSQL(string sql)
{
    cout<<sql<<endl;
    //mysql_query()执行成功返回0,执行失败返回非0值。
    if (mysql_query(mysql,sql.c_str()))
    {
        cout<<"Query Error: "<<mysql_error(mysql);
        return false;
    }
    else  // result==NULL
    {
        if(mysql_field_count(mysql) == 0)   //代表执行的是update,insert,delete类的非查询语句
            {
                // (it was not a SELECT)
                int num_rows = mysql_affected_rows(mysql);  //返回update,insert,delete影响的行数
            }
            else // error
            {
                cout<<"Get result error: "<<mysql_error(mysql);
                return false;
            }
    }
    

    return true;

}
// bool MyDB::exeSQL(string sql)
// {
//     cout<<sql<<endl;
//     //mysql_query()执行成功返回0,执行失败返回非0值。
//     if (mysql_query(mysql,sql.c_str()))
//     {
//         cout<<"Query Error: "<<mysql_error(mysql);
//         return false;
//     }
//     else // 查询成功
//     {
//         result = mysql_store_result(mysql);  //获取结果集
//         if (result)  // 返回了结果集
//         {
//            int  num_fields = mysql_num_fields(result);   //获取结果集中总共的字段数，即列数
//            int  num_rows=mysql_num_rows(result);       //获取结果集中总共的行数
//            for(int i=0;i<num_rows;i++) //输出每一行
//             {
//                 //获取下一行数据
//                 row=mysql_fetch_row(result);
//                 if(row<0) break;

//                 for(int j=0;j<num_fields;j++)  //输出每一字段
//                 {
//                     cout<<row[j]<<"\t\t";
//                 }
//                 cout<<endl;
//             }

//         }
//         else  // result==NULL
//         {
//             if(mysql_field_count(mysql) == 0)   //代表执行的是update,insert,delete类的非查询语句
//             {
//                 // (it was not a SELECT)
//                 int num_rows = mysql_affected_rows(mysql);  //返回update,insert,delete影响的行数
//             }
//             else // error
//             {
//                 cout<<"Get result error: "<<mysql_error(mysql);
//                 return false;
//             }
//         }
//     }

//     return true;

// }