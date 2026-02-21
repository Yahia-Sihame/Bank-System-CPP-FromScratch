#pragma once

#include<iostream>
#include<vector>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"

class ClsDepositScreen : protected ClsScreen 
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
    static void _DepositAmount(ClsBankClient &Client , float Amount)
    {
        Client.SetAccountBalance(Client.GetAccountBalance() + Amount)  ;
    }
public :
    static void DepositScreen()
    {
        string Title = "Deposit Screen" ;
        HeaderScreen(Title) ;
        if (!CheckForOption("Do You Want To Deposit Amount To Client ? (y/n) : "))
            return ;
        float Amount ;
        vector<ClsBankClient> Vclients = ClsBankClient::ReadClients() ;
        string AccNumber ;
        string Check = "n" ;
        cout << "\n\nEnter Account Number : " ;
        AccNumber = clsInputValidate::ReadString();;

        if ( ClsBankClient::IsClientExist(AccNumber)) 
        {
            ClsBankClient Client = ClsBankClient::Find(AccNumber) ;
            cout << endl ;
            _PrintClient(Client) ;
            cout << endl <<"Please Enter Deposit amount : " ;
            cin >> Amount ;
            cout << "\nAre You sure You want perform this transaction ? (yes/no) " ; 
            cin >> Check ;
            if (Check[0] == 'y' || Check[0] == 'Y')
            {
                _DepositAmount(Client,Amount) ; 
                Client.SaveClientInFile() ;
                cout << "\n\nDeposet Successfuly. " << endl << endl ;
                _PrintClient(Client) ;
            }
        }
        else 
            cout << "\n\nClient with Account Number [" << AccNumber << "] is not found !" << endl ; 
    }
} ;