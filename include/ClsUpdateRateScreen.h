#pragma once

#include "ClsScreen.h"
#include "ClsInputValidate.h"

class ClsUpdateRateScreen : protected ClsScreen
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

    static void _UpdateScreen(ClsBankClient::stCurrency &Curr)
    { 
        cout << "Update Currency Rate : " << endl ; 
        cout << "-----------------------" << endl ;
        cout << "Enter New Rate : " ; 
        float NewRate = clsInputValidate::ReadFloatNumber() ;
        Curr.Rate = NewRate ;
        cout << "Are you sure You Want To Update The Rate Of This Currency ? (y/n) : " ; 
        string Check = clsInputValidate::ReadString() ; 
        if ( Check[0] == 'y' || Check[0] == 'Y')
        {
            ClsBankClient::UpdateRateCarrencyInFile(Curr) ;
            cout << endl << "Currency Rate Updated Successfully ." << endl << endl ;
            _PrintCurrency(Curr) ; 
        }

    }

public : 

    static void UpdateRateScreen() 
    {
        ClsBankClient::stCurrency Curr ;
        HeaderScreen("Update Currency Screen") ;
        if (!CheckForOption("Do You Want To Update Rate Currency ? (y/n) : "))
            return ;
        cout << "Please Enter Currency Code : "  ; 
        string CurrCode = clsInputValidate::ReadString() ; 
        Curr = ClsBankClient::FindCurrencyByCode(CurrCode) ;
        while (Curr.IsEmpty)
        {
            cout << "Currency Code Is Not Found, Choose Another one :" ;
            CurrCode = clsInputValidate::ReadString() ;
        }
        cout << endl ; 
        _PrintCurrency(Curr) ; 

        cout << endl << endl ;
        _UpdateScreen(Curr) ;

    }
};