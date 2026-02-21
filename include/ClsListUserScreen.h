#pragma once 

#include<iostream>
#include "ClsScreen.h"
#include<iomanip>
#include "ClsUser.h"


class ClsListUserScreen : protected ClsScreen
{
private :
    static void _PrintUserRecordLine(ClsUser User)
    {
        cout << "|  "<< setw(15) << User.GetFirstName() ;
        cout << "|  "<< setw(15) << User.GetLastName()  ;
        cout << "|  "<< setw(20) << User.GetEmail() ;
        cout << "|  "<< setw(20) << User.GetPhoneNumber() ;
        cout << "|  "<< setw(15) << User.GetUserName() ;
        cout << "|  "<< setw(15) << User.GetPassword() ;
        cout << "|  "<< setw(20) << User.GetPermissions() ;
    }
public : 
    static void ListUserScreen()
    {
        vector<ClsUser> vUsers = ClsUser::ReadUsers() ;
        string Title = "User List Screen" ; 
        string SubTitle = "  (" + to_string(vUsers.size()) + ") User(s)" ;
        HeaderScreen(Title,SubTitle) ;
        cout << "\n--------------------------------------------------------------------------------------------------";
        cout << "------------------------------------------------------------------------------------------\n" ;
        cout << "|  " << left << setw(15) << "First Name" ;
        cout << "|  " << left << setw(15) << "Last Name" ;
        cout << "|  " << left << setw(20) << "Email" ;
        cout << "|  " << left << setw(20) << "PhoneNumber" ;
        cout << "|  " << left << setw(15) << "User Name" ;
        cout << "|  " << left << setw(15) << "Password" ;
        cout << "|  " << left << setw(20) << "Permissions" ;
        cout << "\n--------------------------------------------------------------------------------------------------";
        cout << "------------------------------------------------------------------------------------------\n" ;

        for (ClsUser User : vUsers)
        {
            _PrintUserRecordLine(User)  ;
            cout << endl ; 
        }
        cout << "\n--------------------------------------------------------------------------------------------------";
        cout << "------------------------------------------------------------------------------------------\n" ;  
    }
} ;