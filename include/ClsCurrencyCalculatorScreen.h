#pragma once

#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "string.h"

class ClsCurrencyCalculatorScreen : protected ClsScreen
{
private : 

    static void _PrintCurrency(ClsBankClient::stCurrency Curr)
    {
        cout << "------------------------------------------------------------------------------" << endl ;
        cout << setw(16) << left <<"Country" << ":  " << Curr.CountryName << endl ;
        cout << setw(16) << left <<"Code"  << ":  " << Curr.CountryCode << endl ;
        cout << setw(16) << left <<"Name"  << ":  " << Curr.Name << endl ;
        cout << setw(16) << left <<"Rate(1$)"  << ":  " << Curr.Rate << endl ;
        cout << "------------------------------------------------------------------------------" << endl ;
    }

    static float ReturnCurrencyChangeToUsd(ClsBankClient::stCurrency CurrFrom , float Amount)
    {
        float Result = 0 ; 
        Result =  Amount  / CurrFrom.Rate ;

        return Result ;
    }
    static float ReturnCurrencyChangeFromTo(ClsBankClient::stCurrency CurrFrom , ClsBankClient::stCurrency CurrTo , float Amount)
    {
        float Result = 0 ; 
        float RateFrom = CurrFrom.Rate ;
        float RateTo = CurrTo.Rate ;

        Result = ReturnCurrencyChangeToUsd(CurrFrom,Amount) * RateTo ;

        return Result ;
    }
    static ClsBankClient::stCurrency _CheckCurrencyExist(string &CodeFrom )
    {
        ClsBankClient::stCurrency CurrFrom  ;
        do 
        {
            CurrFrom = ClsBankClient::FindCurrencyByCode(CodeFrom) ;
            if (CurrFrom.IsEmpty)
            {
                cout << "This Currency Not exist! Enter Another Code Currency : " ;
                CodeFrom = clsInputValidate::ReadString() ;
            }

        }while(CurrFrom.IsEmpty) ;

        return CurrFrom ;
    }

    static void _ReadCurrency()
    {
        cout << "Please Enter Currency code From : "  ; 
        string CodeFrom = clsInputValidate::ReadString() ; 
        ClsBankClient::stCurrency CurrFrom = _CheckCurrencyExist(CodeFrom) ;
        cout << endl ; 

        cout << "Please Enter Currency code To : " ; 
        string CodeTo = clsInputValidate::ReadString() ; 
        ClsBankClient::stCurrency CurrTo = _CheckCurrencyExist(CodeTo) ; 
        cout << endl ;
        
        
        cout << "Enter Amount To Exchange : " ;
        float Amount = clsInputValidate::ReadFloatNumber() ; 
        cout << endl ;
        
        
        if ( clsString::UpperAllString(CodeTo) == "USD" )
        {
            cout << "Convert From " << clsString::UpperAllString(CodeFrom) << " To USD : " <<endl << endl; 
            cout << "This Is " << clsString::UpperAllString(CodeFrom) << endl ; 
            _PrintCurrency(CurrFrom) ;
            cout << endl ;
            cout << "This Is USD "  << endl ; 
            _PrintCurrency(CurrTo) ;
            cout << endl << clsString::UpperAllString(CodeFrom) + " TO USD --> " ;
            cout << to_string(Amount) + " " + CodeFrom + " = " + to_string(ReturnCurrencyChangeToUsd(CurrFrom,Amount)) + " "  + clsString::UpperAllString(CodeTo) << endl << endl << endl ;
        }
        else 
        {
            cout << endl ;
            cout << "Convert From " << clsString::UpperAllString(CodeFrom) << " To " << clsString::UpperAllString(CodeTo) + " : " << endl << endl; 
            cout << "This Is " << clsString::UpperAllString(CodeFrom) << endl ; 
            _PrintCurrency(CurrFrom) ;
            cout << endl ;
            cout << "This Is " << clsString::UpperAllString(CodeTo) << endl ; 
            _PrintCurrency(CurrTo) ;
            
            cout << endl << clsString::UpperAllString(CodeFrom) + " TO "+ clsString::UpperAllString(CodeTo) + " -->  " ;
            cout << to_string(Amount) + " " + clsString::UpperAllString(CodeFrom) + " = " + to_string(ReturnCurrencyChangeFromTo(CurrFrom,CurrTo,Amount)) + " "  + clsString::UpperAllString(CodeTo) << endl << endl << endl;
        }
    }
public : 

    static void CurrencyCalculatorScreen() 
    {
        string Check = "y" ;
        string Title = "Currency Exchange Screen" ; 
        HeaderScreen(Title) ;
        if (!CheckForOption("Do You Want To Exchange Currency ? (y/n) : "))
            return ;
        while (Check[0] == 'y' || Check[0] == 'Y')
        {
            cout << endl ;
            _ReadCurrency() ;
            cout << endl << endl << "Do You Want To Perform Another Exchange ? (y/n) : " ;
            Check = clsInputValidate::ReadString() ;
        }
        cout << endl ;
    }

};