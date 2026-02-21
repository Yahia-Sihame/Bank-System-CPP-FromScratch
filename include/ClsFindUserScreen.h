#pragma once

#include<iostream>
#include<vector>
#include "ClsUser.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"

class ClsFindUserScreen : protected ClsScreen
{
private : 
    static void _PrintUser(ClsUser User)
    {
        cout << "User Card : "<< endl ; 
        cout << "------------------------------------------------------------------------------" << endl ;
        cout << setw(16) << left <<"First Name" << ":  " << User.GetFirstName() << endl ;
        cout << setw(16) << left <<"Last Name"  << ":  " << User.GetLastName() << endl ;
        cout << setw(16) << left <<"Email"  << ":  " << User.GetEmail() << endl ;
        cout << setw(16) << left <<"Phone Number"  << ":  " << User.GetPhoneNumber() << endl ;
        cout << setw(16) << left <<"User Name" << ":  " << User.GetUserName() << endl ;
        cout << setw(16) << left <<"Password " << ":  " << User.GetPassword() << endl ;
        cout << setw(16) << left <<"Permissions" << ":  " << User.GetPermissions() << endl ;
        cout << "------------------------------------------------------------------------------" << endl ;
    }
public : 
    static void FindUserScreen()
    {
        string Title = "Find User Screen" ; 
        HeaderScreen(Title) ; 
        if (!CheckForOption("Do You Want To Find User ? (y/n) : "))
            return ;
        string UserName ; 
        cout << "\n\nPlease Enter User Name : " ;
        cin >> UserName ;
        while ( !ClsUser::IsUserExist(UserName))
        {
            cout << "The User Is Not Exist ! \nEnter Another User Name :  " ;
            cin >> UserName ;
        }
        ClsUser User =  ClsUser::Find(UserName) ;
        _PrintUser(User) ;
    }
} ;