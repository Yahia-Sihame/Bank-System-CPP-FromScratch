#pragma once

#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "ClsListCurrencyScreen.h"
#include "ClsFindCurrencyScreen.h"
#include "ClsUpdateRateScreen.h"
#include "ClsCurrencyCalculatorScreen.h"

using namespace std ; 

class ClsCurrencyExchangeScreen : protected ClsScreen
{
private : 
    enum _enCUrrencyOptions {ListCurrency = 1 , FindCurrency = 2 , UpdateRate = 3 , CurrencyCalculator = 4 , MainMenue = 5 } ; 

    static int _Choose()
    {
        int Number ;
        cout << setw(33) << " " << "Choose what do you want to do? [1 to 5] : " ;
        Number = clsInputValidate::ReadDblNumberBetween(1,5,"Please Enter Number Between 1 and 5 :") ;
        return Number ;
    }

    static void _GoBackToCurrencyScreen()
    {
        string enter ;
        cout << endl << "\t\tPress any word to go back to Users Menue ..." ;
        cin >> enter ; 
        if (enter[0])
            CurrencyExchangeScreen() ; 
    }
    static void _ShowListurrencyScreen()
    {
        ClsListCurrencyScreen::ListCurrencyScreen() ; 
    }
    static void _ShowFindCurrencyScreen()
    {
        ClsFindCurrencyScreen::FindCurrencyScreen() ;
    }
    static void _ShowUpdateRateScreen()
    {
        ClsUpdateRateScreen::UpdateRateScreen() ;
    }
    static void _ShowCurrencyCalculatorScreen()
    {
        ClsCurrencyCalculatorScreen::CurrencyCalculatorScreen() ;
    }
    static void _PerfromManageUsersOptions(_enCUrrencyOptions Choise)
    {
        switch(Choise)
        {
            case _enCUrrencyOptions::ListCurrency : 
                system("Clear") ;
                _ShowListurrencyScreen() ;
                _GoBackToCurrencyScreen() ;
                break ;
            case _enCUrrencyOptions::FindCurrency :  
                system("Clear") ;
                _ShowFindCurrencyScreen() ;
                _GoBackToCurrencyScreen() ;
                break ;
            case _enCUrrencyOptions::UpdateRate : 
                system("Clear") ;
                _ShowUpdateRateScreen() ;
                _GoBackToCurrencyScreen() ;
                break ; 
            case _enCUrrencyOptions::CurrencyCalculator : 
                system("Clear") ;
                _ShowCurrencyCalculatorScreen() ;
                _GoBackToCurrencyScreen() ;
                break ; 
            case _enCUrrencyOptions::MainMenue :
                break ;
        }
    }

public : 
    static bool CurrencyExchangeScreen()
    {
        if (!ClsScreen::ShowPermissions(ClsUser::enPermissions::pCurrencyExchange))
        {
            return false ;
        }
        system("clear"); 
        HeaderScreen("Currency Exchange Main Screen") ;
        cout << setw(33) << " " << "===============================================================================\n" ;
        cout << setw(33) << " " << "                                 Currency Exchange Menue                            \n" ; 
        cout << setw(33) << " " << "===============================================================================\n" ;
        cout << setw(33) << " " << "\t\t [1] List Currency." << endl ;
        cout << setw(33) << " " << "\t\t [2] Find Currency." << endl ;
        cout << setw(33) << " " << "\t\t [3] Update Rite." << endl ;
        cout << setw(33) << " " << "\t\t [4] Currency Calculator." << endl ;
        cout << setw(33) << " " << "\t\t [5] Main Menue." << endl ;
        cout << setw(33) << " " << "===============================================================================\n" ;
        _PerfromManageUsersOptions(_enCUrrencyOptions(_Choose())) ;
        return true ; 
    }
};