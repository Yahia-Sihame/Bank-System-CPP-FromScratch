#pragma once

#include<iostream>
#include<vector>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"

class ClsUpdateClientScreen : protected ClsScreen 
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
    static void _ReadDataClient(ClsBankClient &Client)
    {
        cout << "Enter First Name : " ; 
        Client.SetFirstName(clsInputValidate::ReadString()) ; 
        cout << "Enter Last Name : " ; 
        Client.SetLastName(clsInputValidate::ReadString()) ; 
        cout << "Enter Email : " ; 
        Client.SetEmail(clsInputValidate::ReadString()) ; 
        cout << "Enter Phone Number : " ; 
        Client.SetPhoneNumber(clsInputValidate::ReadString()) ; 
        cout << "Enter PinCode : " ; 
        Client.setPinCode(clsInputValidate::ReadString()) ; 
        cout << "Enter Account Balance : " ; 
        Client.SetAccountBalance(clsInputValidate::ReadFloatNumber()) ; 
    }
public : 
    static void ShowUpdateClientScreen()
    {
        if (!ClsScreen::ShowPermissions(ClsUser::enPermissions::pUpdateClient))
        {
            return ;
        }
        string Check = "n" ;
        string Title = "Update Client Screen" ; 
        HeaderScreen(Title) ; 
        if (!CheckForOption("Do You Want To Update Client ? (y/n) : "))
            return ;
        vector<ClsBankClient> vClients ;
        ClsBankClient Client ; 

        cout << "Please Enter Client Account Number : "  ; 
        string AccountNumber = clsInputValidate::ReadString() ; 
        while (!ClsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number Is Not Found, Choose Another one :" ;
            AccountNumber = clsInputValidate::ReadString() ;
        }

        Client = ClsBankClient::Find(AccountNumber) ; 
        Client.PrintClient() ; 
        cout << "\n\nUpdate Client Info : " << endl ;
        cout << "------------------------------" << endl ;
        
        _ReadDataClient(Client) ; 
        cout << "Are You Sure You Want To Update This Client ? (y/n) : " ;
        cin >> Check ;
        if (Check[0] == 'y' || Check[0] == 'Y')
        {
            if ( Client.SaveClientInFile() == ClsBankClient::enSave::FailedSave )
            {
                cout << "Failed To Save This Client !" << endl ; 
            }
            else 
            {
                cout << "Update Successfully. \n" << endl ;  
                _PrintClient(Client) ;
            }
        }
    }
} ;