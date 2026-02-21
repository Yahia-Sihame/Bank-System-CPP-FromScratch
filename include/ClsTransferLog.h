#pragma once 

#include<iostream>
#include<vector>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"
#include "ClsUtil.h"


class ClsTransferLog : protected ClsScreen
{
private : 

    static void _PrintUserRecordBalanceLine(ClsBankClient::stTransfereLog Info)
    {
        cout << "\t|  "<< setw(20) << left <<Info.DateTime  ;
        cout << "\t|  "<< setw(12) << left <<Info.AccountNumberFrom ;
        cout << "\t|  "<< setw(12) << left <<Info.AccountNumberTo ;
        cout << "\t|  "<< setw(12) << left <<Info.Amount ;
        cout << "\t|  "<< setw(12) << left <<Info.AccountBalenceAfterWithdrawAmountfrom ;
        cout << "\t|  "<< setw(12) << left <<Info.AccountBalenceAfterDepositAmountTo ;
        cout << "\t|  "<< setw(12) << left <<Info.UserName ;
    }

public : 
    static void TransferLog()
    {
        vector<ClsBankClient::stTransfereLog> Infos = ClsBankClient::ReadTransferLog() ;
        string Title = "Transfer Log List screen" ;
        string SubTitle = " (" + to_string(Infos.size()) + ") Records(s)" ;
        HeaderScreen(Title,SubTitle) ;

        cout << "\n\t============================================================================================================================================================\n" ;
        cout << setw(20) << left << "\t|  Date/Time " ; 
        cout << setw(12) << left << "\t|  s.Acct " ; 
        cout << setw(12) << left << "\t|  d.Acct " ; 
        cout << setw(12) << left << "\t|  Amount " ; 
        cout << setw(12) << left << "\t|  s.Balance " ; 
        cout << setw(12) << left << "\t|  d.Balance " ; 
        cout << setw(12) << left << "\t|  User Name " ; 
        cout << "\n\t============================================================================================================================================================\n" ;
        if (Infos.size() == 0)
        {
            cout << "\t\t\t\t\t\t No Transfer Log Available In the Systeme !" << endl ; 
            cout << "\t\t============================================================================================================================================================\n" ;
        }
        else
        {
            for (ClsBankClient::stTransfereLog Info : Infos)
            {
                _PrintUserRecordBalanceLine(Info)  ;
                cout << endl ; 
            }
        }
    }
};