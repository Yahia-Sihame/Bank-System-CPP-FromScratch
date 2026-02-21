#pragma once 
#include<iostream>
#include<vector>
#include<iomanip>
#include "ClsBankClient.h"
#include "ClsScreen.h" 
#include "ClsInputValidate.h"

using namespace std ; 

class ClsClientsScreen : protected ClsScreen
{
private :
    static void _PrintClientRecordLine(ClsBankClient Client)
    {
        cout << "|  "<< setw(15) << Client.GetFirstName() ;
        cout << "|  "<< setw(15) << Client.GetLastName()  ;
        cout << "|  "<< setw(20) << Client.GetEmail() ;
        cout << "|  "<< setw(20) << Client.GetPhoneNumber() ;
        cout << "|  "<< setw(15) << Client.GetAccountNumber() ;
        cout << "|  "<< setw(15) << Client.GetPinCode() ;
        cout << "|  "<< setw(20) << Client.GetAccountBalance() ;
    }
    static void _PrintClientRecordBalanceLine(ClsBankClient Client)
    {
        cout << "|  "<< setw(17) << left <<Client.GetAccountNumber()  ;
        cout << "|  "<< setw(17) << left <<Client.GetFirstName() + " " + Client.GetLastName() ;
        cout << "|  "<< setw(17) << left <<Client.GetAccountBalance() ;
    }

    static float _ReturnTotalBalances(vector<ClsBankClient> Clients)
    {
        float sum = 0 ;
        for (ClsBankClient Client : Clients)
        {
            sum = sum + Client.GetAccountBalance() ; 
        }
        return sum ; 
    }
public :
    static void ShowClientsList()
    {
        if (!ClsScreen::ShowPermissions(ClsUser::enPermissions::pListClient))
        {
            return ;
        }
        vector<ClsBankClient> Clients = ClsBankClient::ReadClients() ;
        string Title = "Client List Screen" ; 
        string SubTitle = "  (" + to_string(Clients.size()) + ") Client(s)" ;
        HeaderScreen(Title,SubTitle) ;
        cout << "\n--------------------------------------------------------------------------------------------------";
        cout << "------------------------------------------------------------------------------------------\n" ;
        cout << "|  " << left << setw(15) << "First Name" ;
        cout << "|  " << left << setw(15) << "Last Name" ;
        cout << "|  " << left << setw(20) << "Email" ;
        cout << "|  " << left << setw(20) << "PhoneNumber" ;
        cout << "|  " << left << setw(15) << "AccountNumber" ;
        cout << "|  " << left << setw(15) << "Pin Code" ;
        cout << "|  " << left << setw(20) << "AccountBalace" ;
        cout << "\n--------------------------------------------------------------------------------------------------";
        cout << "------------------------------------------------------------------------------------------\n" ;

        for (ClsBankClient Client : Clients)
        {
            _PrintClientRecordLine(Client)  ;
            cout << endl ; 
        }
        cout << "\n--------------------------------------------------------------------------------------------------";
        cout << "------------------------------------------------------------------------------------------\n" ;  
    }


    static void ShowTotaleBalances()
    {
        vector<ClsBankClient> Clients = ClsBankClient::ReadClients() ;
        float TotaleBalances = _ReturnTotalBalances(Clients) ;
        cout << "\n                                Balances List ("<< Clients.size() << ") Client(s)                      \n" ;
        cout << "\n===============================================================================\n" ;
        cout << setw(20) << left << "|  Acount Number " ; 
        cout << setw(20) << left << "|  Client Name " ; 
        cout << setw(20) << left << "|  Balance " ; 
        cout << "\n===============================================================================\n" ;
        if (Clients.size() == 0)
        {
            cout << "\t\t\t No Clients Available In the Systeme !" << endl ; 
            cout << "===============================================================================\n" ;
        }
        else
        {
            for (ClsBankClient Client : Clients)
            {
                _PrintClientRecordBalanceLine(Client)  ;
                cout << endl ; 
            }
            cout << "                                  Totale Balances = " << TotaleBalances << endl ;
            cout << "                                  ( " << clsUtil::NumberToText(TotaleBalances) << ")" << endl ;
        }
    }


} ;
