#include "lib/data_struct.hpp"
#include "lib/print_data_struct.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

void print_data(Data receivedData){

    cout<<setw(30)<<right<<"|"<<"ID "              <<":"<< receivedData.user_id<<setw(20)<<left<<"|"<<endl;
    cout<<setw(30)<<right<<"|"<<"First Name "       <<":"<< receivedData.first_name<<setw(20)<<left<<"|"<<endl;
    cout<<setw(30)<<right<<"|"<<"Last Name "        <<":"<<receivedData.last_name<<setw(20)<<left<<"|"<<endl;
    cout<<setw(30)<<right<<"|"<<"Email "            <<":"<<receivedData.email<<setw(20)<<left<<"|"<<endl;
    cout<<setw(30)<<right<<"|"<<"Subscription Time "<<":"<<receivedData.subscription_time<<setw(20)<<left<<"|"<<endl;
    cout<<setw(30)<<right<<"|"<<"View Time "        <<":"<<receivedData.view_time<<setw(20)<<left<<"|"<<endl;
    cout<<setw(30)<<right<<"|"<<"Last Entry Time "  <<":"<< receivedData.last_entry_time<<setw(20)<<left<<"|"<<endl;

}
