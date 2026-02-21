#pragma once

#include<iostream>
#include<vector>
#include "ClsScreen.h"
#include "ClsUser.h"
#include "ClsInputValidate.h"


class ClsAddNewUserScreen : protected ClsScreen
{
private : 

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
        cout << "Enter Permissions : " ; 
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

    static void _PrintUser(ClsUser User)
    {
        cout << "User Card : "<< endl ; 
        cout << "------------------------------------------------------------------------------" << endl ;
        cout << setw(16) << left <<"First Name" << ":  " << User.GetFirstName() << endl ;
        cout << setw(16) << left <<"Last Name"  << ":  " << User.GetLastName() << endl ;
        cout << setw(16) << left <<"Email"  << ":  " << User.GetEmail() << endl ;
        cout << setw(16) << left <<"Phone Number"  << ":  " << User.GetPhoneNumber() << endl ;
        cout << setw(16) << left <<"User Name" << ":  " << User.GetUserName() << endl ;
        cout << setw(16) << left <<"Password" << ":  " << User.GetPassword() << endl ;
        cout << setw(16) << left <<"Permissions" << ":  " << User.GetPermissions() << endl ;
        cout << "------------------------------------------------------------------------------" << endl ;
    }

public :

    static void AddNewUserScreen()
    {
        string Check = "n" ;
        string Title = "Add User Screen" ; 
        HeaderScreen(Title) ; 
        if (!CheckForOption("Do You Want To Add User ? (y/n) : "))
            return ;
        ClsUser User ;
        cout << "\n\nPlease Enter User Name : "  ; 
        string UserName = clsInputValidate::ReadString() ; 
        while(ClsUser::IsUserExist(UserName))
        {
            cout << "This User Is Already Exist ! " << endl ;
            cout << "Please Enter Another User Name : "<< endl ;
            cin >> UserName ;
        }
        User = ClsUser::GetAddNewUserObject(UserName) ;
        _ReadDataUser(User) ;
        cout << "Are You Sure You Want To Add This User ? (y/n) : " ;
        cin >> Check ;
        if (Check[0] == 'y' || Check[0] == 'Y')
        {
            switch(User.SaveUserInFile())
            {
                case ClsUser::enSave::SuccessfullySave :
                    cout << endl ;
                    cout << endl <<  "Account save successfully. " << endl << endl ; 
                    _PrintUser(User) ;
                    break ;
                case (ClsUser::enSave::AlreadyExist) :
                    cout << "Failed To Save This User , Already Exist !" << endl ; 
                    break ; 
                case (ClsUser::enSave::FailedSave) :
                    cout << "Failed To Save This User !" << endl ; 
                    break ;
            }
        }
    }
};