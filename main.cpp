#include<iostream>
#include<winsock2.h>
#include "lib/data_struct.hpp"
#include "lib/email_validator.hpp"
#include "lib/database_handler.hpp"
#include <iomanip>
#include "lib/print_data_struct.hpp"
#include <vector>


using namespace std;

const int PORT=2222;

int main()
{

    //****************************
    try
    {

        WSADATA wsData;
        if(WSAStartup(MAKEWORD(2,2), &wsData) != 0)
        {
            throw "wsaData init failed";
        }
        //server file descriptor
        int server_socket = socket(AF_INET, SOCK_DGRAM, 0); //tcp-SOCK_STREAM
        if(server_socket == INVALID_SOCKET)
        {
            WSACleanup();
            throw "socket creation failed";
        }

        cout<<"socket creation successful"<<endl;


        //  BIND---------------------

        //init server address
        sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(PORT);
        server_address.sin_addr.s_addr = inet_addr("127.0.0.1");//localhost


        //bind
        if(bind(server_socket, (sockaddr*)&server_address, sizeof(server_address)) ==-1)
        {
            closesocket(server_socket);
            WSACleanup();
            throw "binding error";
        }
        cout<<"binded socket successfully"<<endl;

        //  -----------------------------------------------------------------------//
        //  Set up timeout

        int idle_shut_down_time = 120;
        timeval timeout;
        timeout.tv_sec = idle_shut_down_time;//30 seconds
        timeout.tv_usec = 0;


        // Receive data from clients
        char buffer[1024];
        sockaddr_in client_address;
        int addrSize = sizeof(client_address);


        while(true)
        {
            cout<<endl<<"listening..."<<endl;

            fd_set readSet;
            FD_ZERO(&readSet);
            FD_SET(server_socket, &readSet);


            //select
            int result = select(0, &readSet, NULL, NULL, &timeout);

            if(result == SOCKET_ERROR)
            {
                //error
                WSACleanup();
                closesocket(server_socket);
                throw "Error in select";
            }
            else if(result == 0)
            {
                // Timeout reached, no data received
                cout<<"Timeout reached. No data received within "<<idle_shut_down_time<<" seconds."<<endl;
                closesocket(server_socket);
                WSACleanup();
                break;
            }
            else
            {
                // Data is ready to be received
                //listen in case of tcp
                int bytesRead = recvfrom(server_socket, buffer, sizeof(buffer), 0, (sockaddr*)&client_address, &addrSize);
                if(bytesRead == SOCKET_ERROR)
                {
                    cout<<"Error receiving data: "<<WSAGetLastError()<<endl;
                    //WSACleanup();
                    //closesocket(server_socket);
                    //throw "Error receiving data";
                }
                else
                {
                    //buffer[bytesRead] = '\0'; // Null-terminate the received data
                    //cout<<"Received data from client: "<<buffer<<endl;

                    //Data
                    cout<<endl<<endl<<setw(25)<<right<<"<"<<"<<<Recieved data from a user>>>>"<<endl<<endl;

                    Data receivedData;
                    memcpy(&receivedData, buffer, sizeof(receivedData));

                    //print the received data
                    print_data(receivedData);


                    //check email validity
                    string email(receivedData.email);

                    if(validate(email))//true -- valid email
                    {
                        //database query

                        cout<<endl<<"\t\t\t >>valid email updating database"<<endl;


                        if(!send_to_database(receivedData)){
                            cout<<endl<<"\t\t\t >>could not update database"<<endl;
                        }
                        else{
                            cout<<endl<<"\t\t\t >>updated database"<<endl;
                        }
                    }
                    else//false -- invalid email
                    {
                        cout<<endl<<"\t\t\t >>the email is invalid"<<endl;
                        //throw "invalid email recieved";
                    }
                }
            }
        }


        closesocket(server_socket);
        WSACleanup();
    }



    catch(const char* errorMessage)
    {
        cout<<errorMessage<<endl;
    }
    //***********************************/






    /******* //email test
    Data user1 = {77, "ashik", "mahmud", "ashik@test.com", "2014-05-28 11:30:10", "2014-05-29 12:30:10", 12};
    string email(user1.email);
    cout<<validate(email)<<endl;
    *******/

    //email validation test case
    /*
    vector<string> testCase = {
        "test.com",
        "abc@gmail.com",
        "abctest@gmail.com",
        "a@test.cc",
        "fa@test.c",
        "afhs.hfs.@test.cc",
        "afk.sjk.fhk@test-er.cc",
        "fa@test.c",
        "ffh-fk_fh@.test-hello.-com"
    };

    for(int i=1; i<testCase.size(); i++){
        cout<<i<<" : "<<testCase[i-1]<<endl;
        cout<<validate(testCase[i-1])<<endl;
    }
    */

    //database test
    //Data user1 = {77, "ashik", "mahmud", "ashik@test.com", "2014-05-28 11:30:10", "2014-05-29 12:30:10", 12};
    //send_to_database(user1);



    return 0;

}
