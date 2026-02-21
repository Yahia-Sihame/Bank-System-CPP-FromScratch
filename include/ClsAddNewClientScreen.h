#pragma once

#include<iostream>
#include<vector>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"


using namespace std ;

class ClsAddNewClientScreen : ClsScreen
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

    static void ShowAddNewClientScreen()
    {
        if (!ClsScreen::ShowPermissions(ClsUser::enPermissions::pAddNewClient))
        {
            return ;
        }
        string Check = "n" ;
        string Title = "Add Client Screen" ; 
        HeaderScreen(Title) ; 
        if (!CheckForOption("Do You Want To Add Client ? (y/n) : "))
            return ;
        ClsBankClient Client ;
        cout << "\n\nPlease Enter Client Account Number : "  ; 
        string AccountNumber = clsInputValidate::ReadString() ; 
        while(ClsBankClient::IsClientExist(AccountNumber))
        {
            cout << "This Client Is Already Exist ! " << endl ;
            cout << "Please Enter Another Account Number : "<< endl ;
            cin >> AccountNumber ;
        }
        Client = ClsBankClient::GetAddNewClientObject(AccountNumber) ;
        _ReadDataClient(Client) ;
        cout << "Are You Sure You Want To Add This Client ? (y/n) : " ;
        cin >> Check ;
        if (Check[0] == 'y' || Check[0] == 'Y')
        {
            switch(Client.SaveClientInFile())
            {
                case ClsBankClient::enSave::SuccessfullySave :
                    cout << endl ;
                    cout << endl <<  "Account save successfully. " << endl ; 
                    _PrintClient(Client) ;
                    break ;
                case (ClsBankClient::enSave::AlreadyExist) :
                    cout << "Failed To Save This Client , Already Exist !" << endl ; 
                    break ; 
                case (ClsBankClient::enSave::FailedSave) :
                    cout << "Failed To Save This Client !" << endl ; 
                    break ;
            }
        }
    }
} ;