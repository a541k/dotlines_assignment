#include<iostream>
#include<winsock2.h>
#include "lib/data_struct.hpp"
#include "lib/email_validator.hpp"
#include "lib/database_handler.hpp"


using namespace std;

const int PORT=2222;

int main(){
    /******* //email test
    Data user1 = {77, "ashik", "mahmud", "ashik@test.com", "2014-05-28 11:30:10", "2014-05-29 12:30:10", 12};
    string email(user1.email);
    cout<<validate(email)<<endl;
    *******/

    //database test
    Data user1 = {77, "ashik", "mahmud", "ashik@test.com", "2014-05-28 11:30:10", "2014-05-29 12:30:10", 12};
    send_to_database(user1);


    /**************
    //cout<<"This is server socket program"<<endl;
    //  SOCKET CREATION--------
    //init wsadata
    WSADATA wsData;
    if(WSAStartup(MAKEWORD(2,2), &wsData) != 0){
        cout<<"wsaData init failed"<<endl;
        return 0;
    }
    //server file descriptor
    int server_socket = socket(AF_INET, SOCK_DGRAM, 0); //tcp-SOCK_STREAM
    if(server_socket == INVALID_SOCKET){
        cout<<"socket creation failed"<<endl;
        WSACleanup();
        return 0;
    }

    cout<<"socket creation successful"<<endl;


    //  BIND---------------------

    //init server address
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");//localhost


    //bind
    if(bind(server_socket, (sockaddr*)&server_address, sizeof(server_address)) ==-1){
        cout<<"binding error"<<endl;
        closesocket(server_socket);
        WSACleanup();
        return 0;
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

    cout<<"listening..."<<endl;
    while(true){


        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(server_socket, &readSet);


        //select
        int result = select(0, &readSet, NULL, NULL, &timeout);

        if(result == SOCKET_ERROR){
            //error
            cout <<"Error in select: "<<WSAGetLastError()<<endl;
            break;
        }
        else if(result == 0){
            // Timeout reached, no data received
            cout<<"Timeout reached. No data received within "<<idle_shut_down_time<<" seconds."<<endl;
            break;
        }
        else{
            // Data is ready to be received
            //listen in case of tcp
            int bytesRead = recvfrom(server_socket, buffer, sizeof(buffer), 0, (sockaddr*)&client_address, &addrSize);
            if(bytesRead == SOCKET_ERROR){
                cout<<"Error receiving data: "<<WSAGetLastError()<<endl;
            }
            else{
                //buffer[bytesRead] = '\0'; // Null-terminate the received data
                //cout<<"Received data from client: "<<buffer<<endl;

                //Data
                Data receivedData;
                memcpy(&receivedData, buffer, sizeof(receivedData));
                cout<<"ID: "<<receivedData.user_id<<" >> "<<receivedData.first_name<<" "<<receivedData.last_name<<endl;
                cout<<receivedData.email<<endl;
                cout<<receivedData.subscription_time<<endl;
                cout<<receivedData.view_time<<endl;
                cout<<receivedData.last_entry_time<<endl;


                //check email validity
                string email(receivedData.email);
                if(validate(email)){
                    //database query
                    cout<<endl<<endl<<"valid email updating database"<<endl;
                }
                else{
                    cout<<"the email is invalid"<<endl;
                }
            }
        }
    }


    closesocket(server_socket);
    WSACleanup();

    *************************************************************/
    return 0;
}
