#pragma once

#include<iostream>
#include<vector>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"
#include "ClsUtil.h"
#include "ClsListUserScreen.h"
#include "ClsAddNewUserScreen.h"
#include "ClsDeleteUserScreen.h"
#include "ClsUpdateUserScreen.h"
#include "ClsFindUserScreen.h"

class ClsManageUsersScreen : protected ClsScreen
{
private : 

    enum _enCManageUsersOptions{ListUser = 1 , AddNewUser = 2 , DeleteUser = 3 , UpdateUser = 4 , FindUser = 5 , MainMenue = 6} ;
    static int _Choose()
    {
        int Number ;
        cout << setw(33) << " " << "Choose what do you want to do? [1 to 6] : " ;
        Number = clsInputValidate::ReadDblNumberBetween(1,6,"Please Enter Number Between 1 and 6 :") ;
        return Number ;
    }

    static void _GoBackToManageUsersMenue()
    {
        string enter ;
        cout << endl << "\t\tPress any word to go back to Users Menue ..." ;
        cin >> enter ; 
        if (enter[0])
            ShowManageUsersMenue() ; 
    }

    static void _ShowListUserScreen()
    {
        ClsListUserScreen::ListUserScreen() ; 
    }
    static void _ShowAddNewUserScreen()
    {
        ClsAddNewUserScreen::AddNewUserScreen() ; 
    }
    static void _ShowDeleteUserScreen()
    {
        ClsDeleteUserScreen::DeleteUserScreen() ;
    }
    static void _ShowUpdateUserScreen()
    {
        ClsUpdateUserScreen::UpdateUserScreen() ;
    }
    static void _ShowFindUserScreen()
    {
        ClsFindUserScreen::FindUserScreen() ; 
    }
    static void _PerfromManageUsersOptions(_enCManageUsersOptions Choise)
    {
        switch(Choise)
        {
            case _enCManageUsersOptions::ListUser : 
                system("Clear") ;
                _ShowListUserScreen() ;
                _GoBackToManageUsersMenue() ;
                break ;
            case _enCManageUsersOptions::AddNewUser :  
                system("Clear") ;
                _ShowAddNewUserScreen() ;
                _GoBackToManageUsersMenue() ;
                break ;
            case _enCManageUsersOptions::DeleteUser : 
                system("Clear") ;
                _ShowDeleteUserScreen() ;
                _GoBackToManageUsersMenue() ;
                break ; 
            case _enCManageUsersOptions::UpdateUser : 
                system("Clear") ;
                _ShowUpdateUserScreen() ;
                _GoBackToManageUsersMenue() ;
                break ; 
            case _enCManageUsersOptions::FindUser : 
                system("Clear") ;
                _ShowFindUserScreen() ;
                _GoBackToManageUsersMenue() ;
                break ; 
            case _enCManageUsersOptions::MainMenue : 
                break ;
        }
    }
public :
    static bool ShowManageUsersMenue()
    {
        if (!ClsScreen::ShowPermissions(ClsUser::enPermissions::pManageUsers))
        {
            return false ;
        }
        system("clear"); 
        HeaderScreen("Manage Users Screen") ;
        cout << setw(33) << " " << "===============================================================================\n" ;
        cout << setw(33) << " " << "                                 Manage Users Menue                            \n" ; 
        cout << setw(33) << " " << "===============================================================================\n" ;
        cout << setw(33) << " " << "\t\t [1] List Users." << endl ;
        cout << setw(33) << " " << "\t\t [2] Add new User." << endl ;
        cout << setw(33) << " " << "\t\t [3] Delete User." << endl ;
        cout << setw(33) << " " << "\t\t [4] Update User." << endl ;
        cout << setw(33) << " " << "\t\t [5] Find User." << endl ;
        cout << setw(33) << " " << "\t\t [6] Main Menue." << endl ;
        cout << setw(33) << " " << "===============================================================================\n" ;
        _PerfromManageUsersOptions(_enCManageUsersOptions(_Choose())) ;
        return true ; 
    }
};