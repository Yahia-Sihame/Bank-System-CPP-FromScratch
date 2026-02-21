#pragma once

#include "ClsScreen.h"
#include "ClsBankClient.h"

class ClsListCurrencyScreen : protected ClsScreen
{
private : 

    static void _PrintUserRecordLine(ClsBankClient::stCurrency Curr)
    {
        cout << "|  "<< setw(45) << Curr.CountryName ;
        cout << "|  "<< setw(15) << Curr.CountryCode ;
        cout << "|  "<< setw(45) << Curr.Name ;
        cout << "|  "<< setw(20) << Curr.Rate ;
    }

public : 

    static void ListCurrencyScreen() 
    {
        cout << "Hi" ; 
        vector<ClsBankClient::stCurrency> vCurr = ClsBankClient::ReadCurrencies() ;
        string Title = "Currencies List Screen" ; 
        string SubTitle = "  (" + to_string(vCurr.size()) + ") Currencies" ;
        HeaderScreen(Title,SubTitle) ;
        cout << "\n--------------------------------------------------------------------------------------------------";
        cout << "------------------------------------------------------------------------------------------\n" ;
        cout << "|  " << left << setw(45) << "Country" ;
        cout << "|  " << left << setw(15) << "Code" ;
        cout << "|  " << left << setw(45) << "Name" ;
        cout << "|  " << left << setw(20) << "Rate/(1$)" ;
        cout << "\n--------------------------------------------------------------------------------------------------";
        cout << "------------------------------------------------------------------------------------------\n" ;

        for (ClsBankClient::stCurrency Curr : vCurr)
        {
            _PrintUserRecordLine(Curr)  ;
            cout << endl ; 
        }
        cout << "\n--------------------------------------------------------------------------------------------------";
        cout << "------------------------------------------------------------------------------------------\n" ;  
    }
};