#pragma once

#include<iostream>
#include<vector>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"

using namespace std ;


class ClsWithdrawScreen : protected ClsScreen
{
private : 
    static void _PrintClient(ClsBankClient Client)
    {
        cout << "Client Card : "<< endl ; 
        cout << "------------------------------------------------------------------------------" << endl ;
        cout << setw(16) << left <<"First Name" << ":  " << Client.GetFirstName() << endl ;
        cout << setw(16) << left <<"Last Name"  << ":  " << Client.GetLastName() << endl ;
        cout << setw(16) << left <<"Email"  << ":  " << Client.GetEmail() << endl ;
        cout << setw(16) << left <<"Phone Number"  << ":  " << Client.GetPhoneNumber() << endl ;
        cout << setw(16) << left <<"Account Number" << ":  " << Client.GetAccountNumber() << endl ;
        cout << setw(16) << left <<"Pin Code" << ":  " << Client.GetPinCode() << endl ;
        cout << setw(16) << left <<"Account Balance" << ":  " << Client.GetAccountBalance() << endl ;
        cout << "------------------------------------------------------------------------------" << endl ;
    }
    static void _WithDrawAmount(ClsBankClient &Client )
    {
        float Number ;
        float Amount ;
        string Check = "n";
        cout << "Please Enter WhithDraw amount : " ;
        Amount = clsInputValidate::ReadFloatNumber() ; 
        cout << "Are You sure You want perform this transaction ? (yes/no) " ; 
        Check = clsInputValidate::ReadString() ;
        
        while (Amount > Client.GetAccountBalance() )
        {
            cout << "Amount Exceeds the balance, you can WhitDraw up to : " << Client.GetAccountBalance() << endl ;
            cout << "Please enter another Amount : " ; 
            Amount = clsInputValidate::ReadFloatNumber("Enter Number ! ") ; 
            cout << "\n\nAre You sure You want perform this transaction ? (yes/no) " ; 
            Check = clsInputValidate::ReadString() ;
        }
        if ( Check[0] == 'y' || Check[0] == 'Y')
        {
            Client.SetAccountBalance(Client.GetAccountBalance() - Amount)   ;
            Client.SaveClientInFile() ;
            cout << "\n\nWithDraw Successfuly. " << endl << endl ;
            _PrintClient(Client) ;
            return ;
        }
        else 
            return ;
    }

public : 
    static void WithdrawScreen()
    {
        string Title = "Withdraw Screen" ;
        HeaderScreen(Title) ; 
        if (!CheckForOption("Do You Want To Withdraw Amount From Client ? (y/n) : "))
            return ;
        string AccNumber ;
        cout << "Enter Account Number : " ;
        cin >> AccNumber ;

        if ( ClsBankClient::IsClientExist(AccNumber) ) 
        {
            ClsBankClient Client =  ClsBankClient::Find(AccNumber) ;
            _PrintClient(Client) ;
            _WithDrawAmount(Client) ; 
        }
        else
            cout << "\n\nClient with Account Number [" << AccNumber << "] is not found !" << endl ; 
    }

} ;