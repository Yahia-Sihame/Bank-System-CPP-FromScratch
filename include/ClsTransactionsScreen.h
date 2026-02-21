#pragma once

#include<iostream>
#include<vector>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"
#include "ClsDepositScreen.h"
#include "ClsWithdrawScreen.h"
#include "ClsTotaleBalancesScreen.h"
#include "ClsTransferScreen.h" 
#include "ClsTransferLog.h"

class ClsTransactionsScreen : protected ClsScreen
{
private : 
    enum _enTransactionMenuOptions{ Deposit = 1 , Withdraw = 2 , TotaleBlances = 3 , Transfer = 4 , TransferLog = 5,MainMenue = 6} ;
    static int _Choose()
    {
        int Number ;
        cout << setw(33) << " " << "Choose what do you want to do? [1 to 6] : " ;
        Number = clsInputValidate::ReadDblNumberBetween(1,6,"Please Enter Number Between 1 and 6 :") ;
        return Number ;
    }
    static void _GoBackToTransactionMenu()
    {
        string enter ;
        cout << endl <<"\t\tPress any word to go back to main menu ..." ;
        cin >> enter ; 
        if (enter[0])
            TransactionsMenue() ; 
    }
    static void _ShowDepositScreen()
    {
        ClsDepositScreen::DepositScreen() ; 
    }
    static void _ShowWithdrawScreen()
    {
        ClsWithdrawScreen::WithdrawScreen() ;
    }
    static void _ShowTransferScreen()
    {
        ClsTransferScreen::TransferScreen() ; 
    }
    static void _ShowTransferLogScreen()
    {
        ClsTransferLog::TransferLog() ; 
    }
    static void _ShowTotaleBlancesScreen()
    {
        cout << "TotaleBalancesScreen" ; 
        ClsTotaleBalancesScreen::TotaleBalancesScreen() ;
    }
    static void _PerfromTransactionsMenuOptions(_enTransactionMenuOptions Choise)
    {
        switch(Choise)
        {
            case _enTransactionMenuOptions::Deposit : 
                system("Clear") ;
                _ShowDepositScreen() ;
                _GoBackToTransactionMenu() ;
                break ;
            case _enTransactionMenuOptions::Withdraw :  
                system("Clear") ;
                _ShowWithdrawScreen() ;
                _GoBackToTransactionMenu() ;
                break ;
            case _enTransactionMenuOptions::TotaleBlances : 
                system("Clear") ;
                _ShowTotaleBlancesScreen() ;
                _GoBackToTransactionMenu() ;
                break ; 
            case _enTransactionMenuOptions::Transfer : 
                system("Clear") ;
                _ShowTransferScreen() ;
                _GoBackToTransactionMenu() ;
                break ; 
            case _enTransactionMenuOptions::TransferLog : 
                system("Clear") ;
                _ShowTransferLogScreen() ;
                _GoBackToTransactionMenu() ;
                break ; 
            case _enTransactionMenuOptions::MainMenue : 
                break ; 
        }
    }
public : 
    static bool TransactionsMenue()
    {
        if (!ClsScreen::ShowPermissions(ClsUser::enPermissions::pTransactions))
        {
            return false;
        }
        system("clear"); 
        HeaderScreen("Transactions Screen") ;
        cout << endl << endl ;
        cout << setw(33) << " " << "===============================================================================\n" ;
        cout << setw(33) << " " << "                                 Transactions Menue screen                             \n" ; 
        cout << setw(33) << " " << "===============================================================================\n" ;
        cout << setw(33) << " " << "\t\t [1] Deposit." << endl ;
        cout << setw(33) << " " << "\t\t [2] Withdraw." << endl ;
        cout << setw(33) << " " << "\t\t [3] Totale Blances." << endl ;
        cout << setw(33) << " " << "\t\t [4] Transfer." << endl ;
        cout << setw(33) << " " << "\t\t [5] Transfer Log." << endl ;
        cout << setw(33) << " " << "\t\t [6] Main Menue." << endl ;
        cout << setw(33) << " " << "===============================================================================\n" ;
        _PerfromTransactionsMenuOptions(_enTransactionMenuOptions(_Choose())) ;
        return true ;
    }
} ;