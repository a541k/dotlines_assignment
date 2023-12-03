#include <iostream>
#include <string>
#include "lib/data_struct.hpp"
#include "lib/database_handler.hpp"

#include <windows.h>
#include <mysql.h>


using namespace std;

const char* database = "user_information_database";
const char* host = "localhost";
const char* dbuser = "root";
const char* password = "";
unsigned int port = 3306;
const char* unixsocket = NULL;
unsigned long clientflag = 0;




bool send_to_database(Data& user){

    cout<<"this is from database_handler_cpp"<<endl;
    cout<<user.first_name<<endl;

    MYSQL* conn;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, host, dbuser, password, database, port, unixsocket, clientflag);

    if(conn){
        cout<<" congrats! "<<conn<<endl;
    }else{
        cout<<"failed"<<endl;
    }


    return true;
}
