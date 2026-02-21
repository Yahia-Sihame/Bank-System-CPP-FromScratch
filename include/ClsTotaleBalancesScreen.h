#pragma once

#include<iostream>
#include<vector>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"
#include "ClsUtil.h"

class ClsTotaleBalancesScreen : protected ClsScreen 
{
private : 

    static void _PrintClientRecordBalanceLine(ClsBankClient Client)
    {
        cout << "\t\t\t|  "<< setw(17) << left <<Client.GetAccountNumber()  ;
        cout << "\t\t\t|  "<< setw(17) << left <<Client.GetFirstName() + " " + Client.GetLastName() ;
        cout << "\t\t\t|  "<< setw(17) << left <<Client.GetAccountBalance() ;
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
    static void TotaleBalancesScreen()
    {
        vector<ClsBankClient> Clients = ClsBankClient::ReadClients() ;
        string Title = "Totale Balances Screen" ;
        string SubTitle = " (" + to_string(Clients.size()) + ") Client(s)" ;
        HeaderScreen(Title,SubTitle) ;
        float TotaleBalances = _ReturnTotalBalances(Clients) ;

        cout << "\n\t\t==============================================================================================================\n" ;
        cout << setw(20) << left << "\t\t\t|  Acount Number " ; 
        cout << setw(20) << left << "\t\t\t|  Client Name " ; 
        cout << setw(20) << left << "\t\t\t|  Balance " ; 
        cout << "\n\t\t==============================================================================================================\n" ;
        if (Clients.size() == 0)
        {
            cout << "\t\t\t\t\t\t No Clients Available In the Systeme !" << endl ; 
            cout << "\t\t==============================================================================================================\n" ;
        }
        else
        {
            for (ClsBankClient Client : Clients)
            {
                _PrintClientRecordBalanceLine(Client)  ;
                cout << endl ; 
            }
            cout << "\n\t\t\t                                  Totale Balances = " << TotaleBalances << endl ;
            cout << "\t\t\t                                    ( " << clsUtil::NumberToText(TotaleBalances) << ")" << endl ;
        }
    }

} ;