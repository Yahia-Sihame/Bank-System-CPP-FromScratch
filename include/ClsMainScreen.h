#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "ClsInputValidate.h"
#include "ClsScreen.h"
#include "ClsClientsScreen.h"
#include "ClsAddNewClientScreen.h"
#include "ClsDeleteClientScreen.h"
#include "ClsUpdateClientScreen.h"
#include "ClsFindClientScreen.h"
#include "ClsTransactionsScreen.h"
#include "ClsManageUsersScreen.h"
#include "ClsEndScreen.h"
#include "ClsLogoutScreen.h"
#include "ClsLoginRegisterScreen.h"
#include "ClsCurrencyExchangeScreen.h"

using namespace std;

class ClsMainScreen : protected ClsScreen
{
private:
    enum _enCMainMenuOptions
    {
        ClientList = 1,
        AddClient = 2,
        DeleteClient = 3,
        UpdateClient = 4,
        FindClient = 5,
        Transactions = 6,
        ManageUsers = 7,
        LoginRegister = 8,
        Currency = 9,
        Logout = 10
    };
    static int _Choose()
    {
        int Number;
        cout << setw(33) << " " << "Choose what do you want to do? [1 to 10] : ";
        Number = clsInputValidate::ReadDblNumberBetween(1, 10, "Please Enter Number Between 1 and 10 :");
        return Number;
    }
    static void _GoBackToMainMenue()
    {
        string enter;
        cout << endl << "\t\tPress any word to go back to main menu ...";
        cin >> enter;
        if (enter[0])
            MainMenu();
    }
    static void _ShowAllClientsScreen()
    {
        ClsClientsScreen::ShowClientsList();
    }
    static void _ShowAddNewClientsScreen()
    {
        ClsAddNewClientScreen::ShowAddNewClientScreen();
    }
    static void _ShowDeleteClientScreen()
    {
        ClsDeleteClientScreen::ShowDeleteClientScreen();
    }
    static void _ShowUpdateClientScreen()
    {
        ClsUpdateClientScreen::ShowUpdateClientScreen();
    }
    static void _ShowFindClientScreen()
    {
        ClsFindClientScreen::ShowFindClientScreen();
    }
    static void _ShowTransactionsMenue()
    {
        if (ClsTransactionsScreen::TransactionsMenue())
        {
            MainMenu() ; 
            return ;
        }
        _GoBackToMainMenue() ;
    }
    static void _ShowManageUsersMenue()
    {
        if (ClsManageUsersScreen::ShowManageUsersMenue())
        {
            MainMenu() ; 
            return ;
        }
        _GoBackToMainMenue() ;
    }
    static void _ShowAEndScreen()
    {
        ClsLogoutScreen::LogoutScreen() ;
    }

    static void _ShowLoginRegisterScreen()
    {
        ClsLoginRegisterScreen::LoginRegisterScreen() ;
    }

    static void _ShowCurrencExchangeyMenue()
    {
        if (ClsCurrencyExchangeScreen::CurrencyExchangeScreen())
        {
            MainMenu() ; 
            return ;
        }
        _GoBackToMainMenue() ;
    }
    static void _PerfromMainMenuOptions(_enCMainMenuOptions Choise)
    {
        switch (Choise)
        {
        case _enCMainMenuOptions::ClientList:
            system("Clear");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        case _enCMainMenuOptions::AddClient:
            system("Clear");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        case _enCMainMenuOptions::DeleteClient:
            system("Clear");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        case _enCMainMenuOptions::UpdateClient:
            system("Clear");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        case _enCMainMenuOptions::FindClient:
            system("Clear");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        case _enCMainMenuOptions::Transactions:
            system("Clear");
            _ShowTransactionsMenue();
            break;
        case _enCMainMenuOptions::ManageUsers:
            system("Clear");
            _ShowManageUsersMenue();
            break;
        case _enCMainMenuOptions::LoginRegister:
            system("Clear");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        case _enCMainMenuOptions::Currency:
            system("Clear");
            _ShowCurrencExchangeyMenue();
            break;
        case _enCMainMenuOptions::Logout:
            system("Clear");
            _ShowAEndScreen();
            break;
        }
    }

public:
    static void MainMenu()
    {
        system("clear");
        HeaderScreen("Main Screen");
        cout << setw(33) << " " << "===============================================================================\n";
        cout << setw(33) << " " << "                                 Main Menue screen                             \n";
        cout << setw(33) << " " << "===============================================================================\n";
        cout << setw(33) << " " << "\t\t [1] Show Client List." << endl;
        cout << setw(33) << " " << "\t\t [2] Add new Client." << endl;
        cout << setw(33) << " " << "\t\t [3] Delete Client." << endl;
        cout << setw(33) << " " << "\t\t [4] Update Client info." << endl;
        cout << setw(33) << " " << "\t\t [5] Find Client." << endl;
        cout << setw(33) << " " << "\t\t [6] Transactions." << endl;
        cout << setw(33) << " " << "\t\t [7] Manage Users." << endl;
        cout << setw(33) << " " << "\t\t [8] Login Register." << endl;
        cout << setw(33) << " " << "\t\t [9] Currency Exchange." << endl;
        cout << setw(33) << " " << "\t\t [10] Logout." << endl;
        cout << setw(33) << " " << "===============================================================================\n";
        _PerfromMainMenuOptions(_enCMainMenuOptions(_Choose()));
    }
};