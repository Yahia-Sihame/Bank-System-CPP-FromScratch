#pragma once

#include<iostream>
#include<vector>
#include "ClsUser.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"
#include "Global.h"

class ClsUpdateUserScreen : protected ClsScreen
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
        cout << setw(16) << left <<"UserName" << ":  " << User.GetUserName() << endl ;
        cout << setw(16) << left <<"Password " << ":  " << User.GetPassword() << endl ;
        cout << setw(16) << left <<"Permissions" << ":  " << User.GetPermissions() << endl ;
        cout << "------------------------------------------------------------------------------" << endl ;
    }
    static void _ReadDataUser(ClsUser &User)
    {
        cout << "Enter First Name : " ;
        User.SetFirstName(clsInputValidate::ReadString()) ; 
        cout << "Enter Last Name : " ;
        User.SetLastName(clsInputValidate::ReadString()) ; 
        cout << "Enter Email : " ;
        User.SetEmail(clsInputValidate::ReadString()) ; 
        cout << "Enter Phone Number : " ; 
        User.SetPhoneNumber(clsInputValidate::ReadString()) ; 
        cout << "Enter Password : " ; 
        User.setPassword(clsInputValidate::ReadString()) ; 
        cout << "Enter Permissions : " << endl ; 
        User.setPermissions(_ReadPermissionsToSet()) ; 
    }
    static int _ReadPermissionsToSet()
    {
        string Check = "n" ;
        int Permissions = 0 ;
        cout << "Do you want to give full access ? (y/n) : " ;
        Check = clsInputValidate::ReadString() ;
        if (Check[0] == 'y')
        {
            return ClsUser::enPermissions::pAll ; 
        }
        cout << "Do you want to give access to : " << endl ;
        cout << "Show Client List ? (y/n) : " ; 
        Check = clsInputValidate::ReadString() ;
        if (Check[0] == 'y')
        {
            Permissions = Permissions + ClsUser::enPermissions::pListClient ; 
        }
        cout << "Add New Client ? (y/n) : " ; 
        Check = clsInputValidate::ReadString() ;
        if (Check[0] == 'y')
        {
            Permissions = Permissions + ClsUser::enPermissions::pAddNewClient ; 
        }
        cout << "Delet Client ? (y/n) : " ; 
        Check = clsInputValidate::ReadString() ;
        if (Check[0] == 'y')
        {
            Permissions = Permissions + ClsUser::enPermissions::pDeleteClient ; 
        }
        cout << "Update Client ? (y/n) : " ; 
        Check = clsInputValidate::ReadString() ;
        if (Check[0] == 'y')
        {
            Permissions = Permissions + ClsUser::enPermissions::pUpdateClient ; 
        }
        cout << "Find Client List ? (y/n) : " ; 
        Check = clsInputValidate::ReadString() ;
        if (Check[0] == 'y')
        {
            Permissions = Permissions + ClsUser::enPermissions::pFindClient ; 
        }
        cout << "Transactions ? (y/n) : " ; 
        Check = clsInputValidate::ReadString() ;
        if (Check[0] == 'y')
        {
            Permissions = Permissions + ClsUser::enPermissions::pTransactions ; 
        }
        cout << "Login Register ? (y/n) : " ; 
        Check = clsInputValidate::ReadString() ;
        if (Check[0] == 'y')
        {
            Permissions = Permissions + ClsUser::enPermissions::pLoginRegister ; 
        }
        cout << "Manage Users ? (y/n) : " ; 
        Check = clsInputValidate::ReadString() ;
        if (Check[0] == 'y')
        {
            Permissions = Permissions + ClsUser::enPermissions::pManageUsers ; 
        }
        cout << "Currency Exchange ? (y/n) : " ; 
        Check = clsInputValidate::ReadString() ;
        if (Check[0] == 'y')
        {
            Permissions = Permissions + ClsUser::enPermissions::pCurrencyExchange ; 
        }
        return Permissions ;
    }
public :
    static void UpdateUserScreen()
    {
        string Check = "n" ;
        string Title = "Update User Screen" ; 
        HeaderScreen(Title) ; 
        if (!CheckForOption("Do You Want To Update User ? (y/n) : "))
            return ;
        ClsUser User ; 

        cout << "Please Enter User Name : "  ; 
        string UserName = clsInputValidate::ReadString() ; 
        while (!ClsUser::IsUserExist(UserName))
        {
            cout << "User Name Is Not Found, Choose Another one :" ;
            UserName = clsInputValidate::ReadString() ;
        }

        User = ClsUser::Find(UserName) ; 
        User.PrintUser() ; 
        cout << "\n\nUpdate User Info : " << endl ;
        cout << "------------------------------" << endl ;
        
        _ReadDataUser(User) ; 
        cout << "Are You Sure You Want To Update This User ? (y/n) : " ;
        cin >> Check ;
        if (Check[0] == 'y' || Check[0] == 'Y')
        {
            if ( User.SaveUserInFile() == ClsUser::enSave::FailedSave )
            {
                cout << "Failed To Save This User !" << endl ; 
            }
            else 
            {
                cout << "Update Successfully. \n" << endl ;
                GlobalUser = User ;  
                _PrintUser(User) ;
            }
        }
    }
};