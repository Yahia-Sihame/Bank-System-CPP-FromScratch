#pragma once 

#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "ClsBankClient.h"

class ClsTransferScreen : protected ClsScreen
{
private : 
    static void _Transfer(ClsBankClient &Client1 , ClsBankClient &Client2)
    {
        float Amount ;
        string Check = "n" ; 
        cout << "Enter Transfer Amount : "; 
        Amount = clsInputValidate::ReadFloatNumber() ;
        cout << endl ;
        while ( Amount > Client1.GetAccountBalance() )
        {
            cout << "Amount Exceeds the available Balance, Enter another amount : " ;
            Amount = clsInputValidate::ReadFloatNumber() ;
        }

        cout << "Are you sure you want to perform this operator ? (y/n) : " ;
        Check = clsInputValidate::ReadString() ;
        cout << endl ;
        if ( Check[0] == 'y' || Check[0] == 'Y')
        {
            cout << "Transfer Done successfully" << endl << endl ;
            Client1.SetAccountBalance(Client1.GetAccountBalance() - Amount) ; 
            Client1.SaveClientInFile() ;
            Client2.SetAccountBalance(Client2.GetAccountBalance() + Amount) ; 
            Client2.SaveClientInFile() ;
            ClsBankClient::SaveToTransferLog(Client1,Client2,Amount) ; 
            _PrintClient(Client1) ;
            _PrintClient(Client2) ;
        }
    }
    static void _PrintClient(ClsBankClient Client)
    {
        cout << "Client Card : "<< endl ; 
        cout << "------------------------------------------------------------------------------" << endl ;
        cout << setw(16) << left <<"Full Name" << ":  " << Client.GetFirstName() + " " + Client.GetLastName() << endl ;
        cout << setw(16) << left <<"Account Number" << ":  " << Client.GetAccountNumber() << endl ;
        cout << setw(16) << left <<"Account Balance" << ":  " << Client.GetAccountBalance() << endl ;
        cout << "------------------------------------------------------------------------------" << endl ;
    }
public :

    static void TransferScreen()
    {
        string AccountNumber1 ;
        string AccountNumber2 ;
        HeaderScreen("Transfer Screen") ; 
        if (!CheckForOption("Do You Want To Transfere Amount To Client ? (y/n) : "))
            return ;
        cout << "Please Enter Account Number To transfer from : " ;
        AccountNumber1 = clsInputValidate::ReadString() ; 

        if ( ClsBankClient::IsClientExist(AccountNumber1) ) 
        {
            ClsBankClient Client1 =  ClsBankClient::Find(AccountNumber1) ;
            _PrintClient(Client1) ;
            cout << "Please Enter Account Number To transfer to : " ;
            AccountNumber2 = clsInputValidate::ReadString() ; 
            
            if (ClsBankClient::IsClientExist(AccountNumber2))
            {
                ClsBankClient Client2 =  ClsBankClient::Find(AccountNumber2) ;
                _PrintClient(Client2) ;
                _Transfer(Client1,Client2) ; 
            }
            else
                cout << "\n\nClient with Account Number [" << AccountNumber2 << "] is not found !" << endl ; 
        }
        else
            cout << "\n\nClient with Account Number [" << AccountNumber1 << "] is not found !" << endl ; 
        
        
    }
};