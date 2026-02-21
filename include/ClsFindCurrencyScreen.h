#pragma once

#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "ClsBankClient.h"


class ClsFindCurrencyScreen : protected ClsScreen
{
private : 

    static void _PrintCurrency(ClsBankClient::stCurrency Curr)
    {
        cout << "Currency Card : "<< endl ; 
        cout << "------------------------------------------------------------------------------" << endl ;
        cout << setw(16) << left <<"Country" << ":  " << Curr.CountryName << endl ;
        cout << setw(16) << left <<"Code"  << ":  " << Curr.CountryCode << endl ;
        cout << setw(16) << left <<"Name"  << ":  " << Curr.Name << endl ;
        cout << setw(16) << left <<"Rate(1$)"  << ":  " << Curr.Rate << endl ;
        cout << "------------------------------------------------------------------------------" << endl ;
    }

    static void _FindByCode()
    {
        string Code = "" ;
        cout << "Please Enter CurrencyCode : " ;
        Code = clsInputValidate::ReadString() ;

        ClsBankClient::stCurrency Curr = ClsBankClient::FindCurrencyByCode(Code) ; 
        if ( Curr.IsEmpty == false )
        {
            cout << endl ;
            _PrintCurrency(Curr) ; 
            cout << endl ;
        }
        else 
        {
            cout << "Currency was Not Found ." << endl; 
            return ; 
        }
    }

    static void _FindByCountryName()
    {
        string Code = "" ;
        cout << "Please Enter Country Name : " ;
        Code = clsInputValidate::ReadString() ;

        ClsBankClient::stCurrency Curr = ClsBankClient::FindCurrencyByCountryName(Code) ; 
        if ( Curr.IsEmpty == false )
        {
            cout << endl ;
            _PrintCurrency(Curr) ; 
            cout << endl ;
        }
        else 
        {
            cout << "Currency Was Not Found ." << endl ; 
            return ; 
        }
    }

public : 

    static void FindCurrencyScreen() 
    {
        string Title = "Find Currency Screen" ; 
        HeaderScreen(Title) ; 
        if (!CheckForOption("Do You Want To Find Currency ? (y/n) : "))
            return ;
        int Check = 1 ; 
        string UserName ; 
        cout << "Find By : [1] Code or [2] Country Name : " ;
        Check = clsInputValidate::ReadIntNumberBetween(1,2) ; 
        cout << endl ;
        if( Check == 1 )
        {
            _FindByCode() ; 
        }
        else if (Check == 2)
        {
            _FindByCountryName() ; 
        }
    }
};