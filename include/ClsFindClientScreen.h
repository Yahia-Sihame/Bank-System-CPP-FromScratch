#pragma once

#include<iostream>
#include<vector>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"

using namespace std ; 

class ClsFindClientScreen : protected ClsScreen
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
public : 
    static void ShowFindClientScreen()
    {
        if (!ClsScreen::ShowPermissions(ClsUser::enPermissions::pFindClient))
        {
            return ;
        }
        string Title = "Find Client Screen" ; 
        HeaderScreen(Title) ; 
        if (!CheckForOption("Do You Want To Find Client ? (y/n) : "))
            return ;
        string AccountNumber ; 
        cout << "\n\nPlease Enter Account Number : " ;
        cin >> AccountNumber ;
        while ( !ClsBankClient::IsClientExist(AccountNumber))
        {
            cout << "The Client Is Not Exist ! \nEnter Another Account Number :  " ;
            cin >> AccountNumber ;
        }
        ClsBankClient Client =  ClsBankClient::Find(AccountNumber) ;
        _PrintClient(Client) ;
    }
} ;