#pragma once

#include<iostream>
#include<vector>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"

using namespace std ; 

class ClsDeleteClientScreen : protected ClsScreen
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
    static void ShowDeleteClientScreen()
    {
        if (!ClsScreen::ShowPermissions(ClsUser::enPermissions::pDeleteClient))
        {
            return ;
        }
        string Check = "n" ; 
        string Title = "Delete Client Screen" ; 
        HeaderScreen(Title) ; 
        if (!CheckForOption("Do You Want To Delete Client ? (y/n) : "))
            return ;
        ClsBankClient Client ;
        cout << "\n\nPlease Enter Client Account Number : "  ; 
        string AccountNumber = clsInputValidate::ReadString() ; 
        while(!ClsBankClient::IsClientExist(AccountNumber))
        {
            cout << "This Client Is Not Exist ! " << endl ;
            cout << "Please Enter Another Account Number : "<< endl ;
            cin >> AccountNumber ;
        }
        Client = ClsBankClient::Find(AccountNumber) ; 
        _PrintClient(Client) ;
        cout << "Are You Sure You Want To Delete This Client ? (y/n) : " ;
        cin >> Check ;
        if (Check[0] == 'y' || Check[0] == 'Y')
        {
            Client = ClsBankClient::DeleteClientObject(AccountNumber) ;
            cout << "Client Deleted Successfully : "<< endl ; 
            _PrintClient(Client) ;
        }
    }
} ;