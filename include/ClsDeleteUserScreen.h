#pragma once

#include<iostream>
#include<vector>
#include "ClsUser.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"

class ClsDeleteUserScreen : protected ClsScreen
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
    static void DeleteUserScreen()
    {
        string Check = "n" ; 
        string Title = "Delete User Screen" ; 
        HeaderScreen(Title) ; 
        if (!CheckForOption("Do You Want To Delete User ? (y/n) : "))
            return ;
        ClsUser User ;
        cout << "\n\nPlease Enter User Name : "  ; 
        string UserName = clsInputValidate::ReadString() ; 
        while(!ClsUser::IsUserExist(UserName))
        {
            cout << "This User Is Not Exist ! " << endl ;
            cout << "Please Enter Another User Name : "<< endl ;
            cin >> UserName ;
        }
        User = ClsUser::Find(UserName) ; 
        _PrintUser(User) ;
        cout << "Are You Sure You Want To Delete This User ? (y/n) : " ;
        cin >> Check ;
        if (Check[0] == 'y' || Check[0] == 'Y')
        {
            User = ClsUser::DeleteUserObject(UserName) ;
            cout << "User Deleted Successfully : "<< endl ; 
            _PrintUser(User) ;
        }
    }
};