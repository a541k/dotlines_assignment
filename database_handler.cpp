#include <iostream>
#include <string>
#include "lib/data_struct.hpp"
#include "lib/database_handler.hpp"

#include <windows.h>
#include <mysql.h>

#include <fstream>


using namespace std;

const char* database = "user_information_database";
const char* host = "localhost";
const char* dbuser = "root";
const char* password = "";
unsigned int port = 3306;
const char* unixsocket = NULL;
unsigned long clientflag = 0;




bool send_to_database(Data& user){

    //cout<<"this is from database_handler_cpp"<<endl;
    //cout<<user.first_name<<endl;
    try{
        MYSQL* conn;

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, host, dbuser, password, database, port, unixsocket, clientflag);

        if(!conn){
            //cout<<"failed to connect"<<endl;
            throw "failed to connect to database";
        }

        cout<<"\t\t\t >>connected to database"<<endl;

        //data conversion to string for query
        string uId = to_string(user.user_id);
        string fName(user.first_name), lName(user.last_name);
        string email(user.email);
        string subTime(user.subscription_time);
        string lastEntryTime(user.last_entry_time);
        string viewTime = to_string(user.view_time);

        //insert query
        string sql_query = "INSERT INTO `user_info`(`id`, `first_name`, `last_name`, `email`, `subscription_time`, `last_entry_time`,`view_time`) VALUES ("  + uId + ",'" + fName + "', '"
        + lName + "', '" + email + "', '" + subTime + "', '" + lastEntryTime + "', " + viewTime + ")";
        //cout<<sql_query<<endl;
        //--------------------------------------

        //query log-- should remove------
        string filePath = "C:\\Users\\hp\\Desktop\\sqlLog.txt";
        // Open a file for writing
        ofstream outputFile(filePath);
        // Check if the file is open
        if (outputFile.is_open()) {
            // Write data to the file
            outputFile<<sql_query;
            // Close the file
            outputFile.close();
            //cout<<"Data written to the file successfully.\n";
        } else {
            //cout<<"Unable to open the file for writing.\n";
        }
        //-----------------------------------------



        int qstate = 0;

        qstate = mysql_query(conn, sql_query.c_str());

        if(qstate == 0){
            cout<<"\t\t\t >>database query successful"<<endl;
        }else{
            throw "database query failed";
        }



    }
    catch(const char* msg){
        cout<<"\t\t\t >>"<<msg<<endl;
        return false;
    }

    return true;
}
