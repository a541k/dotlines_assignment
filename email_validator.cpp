#include "lib/email_validator.hpp"
#include<iostream>
#include<string>

using namespace std;

//https://snov.io/knowledgebase/what-is-a-valid-email-address-format/

bool validate(string email){
    int len = email.size();


    //len < 9 or first char not alphabet
    if(len < 9 || (email[0]<'a' || email[0]>'z')) {
        cout<<"len / firstchar checker"<<endl;
        return false; //shortest -> a@test.xx
    }

    //bool isValid = false;
    bool containTestSubstr = false;
    int indexOfAt = -1;
    int indexOfLastDot = -1;


    //search for 'test' substr '@' and '.'
    for(int i=0; i < len; i++){
        if(i+3<len && email[i] == 't' && email[i+1] == 'e' && email[i+2] == 's' && email[i+3] == 't'){
            containTestSubstr = true;
            //break;
        }
        if(email[i] == '@'){
            indexOfAt = i;
        }
        else if(email[i] == '.'){
            indexOfLastDot = i;
        }
    }

    if(!containTestSubstr || indexOfAt>indexOfLastDot || indexOfAt==-1|| indexOfLastDot==-1){
        cout<<"not test or . or @"<<endl;
        return false;
    }


    //check before @
    for(int i=0; i<indexOfAt; i++){
        //consecutive speacial character check
        if(email[i]=='.' || email[i] == '_' || email[i]=='-'){
            if(email[i+1]=='.' || email[i+1] == '_' || email[i+1]=='-' || email[i+1]=='@'){
                cout<<"repetitive special char before @"<<endl;
                return false;
            }
        }

        //anything other than a-z0-9, ., -, _
        else if((email[i]<'a' || email[i]>'z') && (email[i]<'0' || email[i]>'9')){
            cout<<"illigal character before @"<<endl;
            return false;
        }
    }

    //check after @
    for(int i=indexOfAt+1; i<indexOfLastDot; i++){

        //consecutive speacial character check
        if(email[i]=='.' || email[i]=='-'){
            if(email[i+1]=='.' || email[i+1]=='-' || email[i-1]=='@'){
                cout<<"consecutive speacial char after @"<<endl;
                return false;
            }
        }

        //anything other than a-z0-9, ., -, _
        else if((email[i]<'a' || email[i]>'z') && (email[i]<'0' || email[i]>'9')){
            cout<<"illigal character after @"<<endl;
            return false;
        }
    }

    //check after last dot
    if(len-1 - indexOfLastDot < 2) {
        //must be atleast 2 char
        cout<<"not enough char after last dot"<<endl;
        return false;
    }
    for(int i = indexOfLastDot + 1; i<len; i++){
        //anything other than a-z0-9, ., -, _
        if((email[i]<'a' || email[i]>'z') && (email[i]<'0' || email[i]>'9')){
            cout<<"illegal character after last dot"<<endl;
            return false;
        }
    }

    return true;




}
