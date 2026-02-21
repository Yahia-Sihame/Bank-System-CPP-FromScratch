#pragma once

#include<iostream>
#include<vector>
#include<fstream>
#include "ClsPerson.h"
#include "ClsString.h"
#include "Global.h"
#include "ClsDate.h"

using namespace std ; 

class ClsBankClient : public ClsPerson
{
public : 
    typedef struct stTransfereLog
    {
        string DateTime ; 
        string AccountNumberFrom ; 
        string AccountNumberTo ; 
        float Amount ; 
        float AccountBalenceAfterWithdrawAmountfrom ; 
        float AccountBalenceAfterDepositAmountTo ; 
        string UserName ; 
    } stTransfereLog ; 


    typedef struct stCurrency
    {
        string CountryName ; 
        string CountryCode ; 
        string Name ;
        float Rate ; 
        bool IsEmpty  = false ;
    } stCurrency;
private : 
    string _AccountNumber ; 
    string _PinCode ; 
    float _AccountBalance ;
    bool Delete = false ;
    enum _enMode{EmptyMode = 0 , UpdateMode = 1 , AddMode = 2} ;
    _enMode _Mode ;

    void _SetMode(_enMode Mode)
    {
        _Mode = Mode ;
    }

    static ClsBankClient _ConvertLineToClientInfo(string Line , string sep)
    {
        vector<string> vstr = clsString::Split(Line,sep) ;
        
        return ClsBankClient(_enMode::UpdateMode,vstr[0],vstr[1],vstr[2],vstr[3],vstr[4],vstr[5],stof(vstr[6])) ; 
    }

    static stCurrency _ConvertLineTostCurrency(string Line , string sep)
    {
        vector<string> vCurr = clsString::Split(Line,sep) ;
        stCurrency Crr ; 
        Crr.CountryName = vCurr[0] ;
        Crr.CountryCode = vCurr[1] ; 
        Crr.Name = vCurr[2] ; 
            Crr.Rate = stof(vCurr[3]) ; 

        return Crr ;
    }

    static ClsBankClient _GetEmptyClient()
    {
        return ClsBankClient(_enMode::EmptyMode,"","","","","","",0) ;
    }

    static string _ConvertUserLoginToLine(ClsBankClient Client1 , ClsBankClient Client2 , float Amount , string sep)
    {
        string Line = "";
        clsDate Date ; 
        Line += clsDate::GetSystemDateTimeString() + sep ; 
        Line += Client1.GetAccountNumber() + sep ; 
        Line += Client2.GetAccountNumber() + sep ; 
        Line += to_string(Amount) + sep ; 
        Line += to_string(Client1.GetAccountBalance()) + sep ; 
        Line += to_string(Client2.GetAccountBalance()) + sep ; 
        Line += GlobalUser.GetUserName() ; 

        return Line ;
    }

    static stTransfereLog _ConvertLoginRegister(string Line , string sep)
    {
        vector<string> vInfo = clsString::Split(Line,sep) ; 
        stTransfereLog Info ; 
        Info.DateTime = vInfo[0] ; 
        Info.AccountNumberFrom = vInfo[1] ; 
        Info.AccountNumberTo = vInfo[2] ; 
        Info.Amount = stof(vInfo[3]) ; 
        Info.AccountBalenceAfterWithdrawAmountfrom = stof(vInfo[4]) ; 
        Info.AccountBalenceAfterDepositAmountTo = stof(vInfo[5]) ; 
        Info.UserName  = vInfo[6]; 

        return Info ;
    }
    
    static vector<stTransfereLog> _ReadTransferLogFromFile(string NameFile)
    {
        vector<stTransfereLog> Info ; 
        fstream MyFile ; 
        MyFile.open(NameFile,ios::in) ; 
        if ( MyFile.is_open() )
        {
            string Line ;
            while (getline(MyFile,Line))
            {
                Info.push_back(_ConvertLoginRegister(Line,"#//#")) ;
            }
            MyFile.close() ;
        }
        return Info ;
    }

    static void _SaveToTransferLog(ClsBankClient Client1 , ClsBankClient Client2 , float Amount)
    {
        fstream MyFile ; 
        MyFile.open("TransferLog.txt", (ios::out | ios::app) ) ; 
        if ( MyFile.is_open())
        {
            MyFile << _ConvertUserLoginToLine(Client1,Client2,Amount,"#//#") << endl ;
        }
        MyFile.close() ; 
    }


    static vector<ClsBankClient> _ReadClientFromFile(string NameFile)
    {
        vector<ClsBankClient> vClients ; 
        fstream MyFile ; 
        MyFile.open(NameFile,ios::in) ; 
        if ( MyFile.is_open())
        {
            string Line ;
            while (getline(MyFile,Line))
            {
                vClients.push_back(_ConvertLineToClientInfo(Line,"#//#")) ;
            }
            MyFile.close() ;
        }
        return vClients ;
    }
    static string _ConvertClientToLine(ClsBankClient Client , string sep)
    {
        string Line = "";
        Line += Client.GetFirstName() + sep ; 
        Line += Client.GetLastName() + sep ; 
        Line += Client.GetEmail() + sep ; 
        Line += Client.GetPhoneNumber() + sep ; 
        Line += Client.GetAccountNumber() + sep ; 
        Line += Client.GetPinCode() + sep ; 
        Line += to_string(Client.GetAccountBalance())  ; 

        return Line ;
    }
    static string _ConvertCurrencyToLine(ClsBankClient::stCurrency Curr , string sep)
    {
        string Line = "";
        Line += Curr.CountryName + sep ; 
        Line += Curr.CountryCode + sep ; 
        Line += Curr.Name + sep ; 
        Line += to_string(Curr.Rate)  ; 

        return Line ;
    }
    static void _SaveAllClients(vector<ClsBankClient> vClients) 
    {
        fstream MyFile ; 
        MyFile.open("Clients.txt",ios::out) ; 
        if (MyFile.is_open())
        {
            for (ClsBankClient &Client : vClients)
            {
                if (Client.Delete == false)
                    MyFile << _ConvertClientToLine(Client,"#//#") << endl ;
            }
            MyFile.close() ; 
        }
    }
    static ClsBankClient _Delete(string AccountNumber)
    {
        vector<ClsBankClient> vClients = _ReadClientFromFile("Clients.txt") ;
        for ( ClsBankClient &Client : vClients)
        {
            if (Client.GetAccountNumber() == AccountNumber)
            {
                Client.Delete = true ; 
            }
        }
        _SaveAllClients(vClients) ;
        return ClsBankClient(_enMode::EmptyMode,"","","","","","",0) ;
    }

    static vector<stCurrency> _ReadCurrenciesFromFile(string NameFile)
    {
        vector<stCurrency> vCurr ; 
        fstream MyFile ; 
        MyFile.open(NameFile,ios::in) ; 
        if ( MyFile.is_open() )
        {
            string Line ;
            while (getline(MyFile,Line))
            {
                vCurr.push_back(_ConvertLineTostCurrency(Line,"#//#")) ;
            }
            MyFile.close() ;
        }
        return vCurr ;
    }
    static void _UpdateRateCarrency(ClsBankClient::stCurrency Curr) 
    { 
        fstream MyFile ; 
        vector<ClsBankClient::stCurrency> vCurr = _ReadCurrenciesFromFile("Currencies.txt") ; 
        MyFile.open("Currencies.txt",ios::out) ; 
        if (MyFile.is_open())
        {
            for (ClsBankClient::stCurrency &C : vCurr )
            {
                if ( C.CountryCode == Curr.CountryCode )
                    MyFile << _ConvertCurrencyToLine(Curr,"#//#") << endl ;
                else 
                    MyFile << _ConvertCurrencyToLine(C,"#//#") << endl ;
            }
            MyFile.close() ; 
        }
    }
public :
    ClsBankClient()
    {
        _Mode = _enMode::EmptyMode ;
        _AccountNumber = "" ;
        _PinCode = "" ;
        _AccountBalance = 0 ; 
    }
    ClsBankClient(_enMode Mode ,string FirstName , string LastName , string Email , string PhoneNumber , string AccountNumber , string PinCode , float AccountBalance) : ClsPerson(FirstName , LastName , Email , PhoneNumber)
    {
        _Mode = Mode ;
        _AccountNumber = AccountNumber ;
        _PinCode = PinCode ;
        _AccountBalance = AccountBalance ; 
    }

    void setPinCode(string PinCode)
    {
        _PinCode = PinCode ; 
    }
    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance ;
    }
    string GetAccountNumber()
    {
        return _AccountNumber ;
    }
    string GetPinCode()
    {
        return _PinCode ;
    }
    float GetAccountBalance()
    {
        return _AccountBalance ;
    }

    static ClsBankClient Find(string AccountNumber)
    {
        vector<ClsBankClient> vClient ; 
        fstream MyFile ; 
        string Line ; 
        MyFile.open("Clients.txt",ios::in) ; 
        if ( MyFile.is_open())
        {
            while ( getline(MyFile,Line) )
            {
                ClsBankClient Client = _ConvertLineToClientInfo(Line,"#//#") ;
                if (Client.GetAccountNumber() == AccountNumber)
                {
                    MyFile.close() ;
                    return Client ;
                }
            }
            MyFile.close() ;
        }
        return _GetEmptyClient() ;
    }
    static ClsBankClient Find(string AccountNumber , string PinCode)
    {
        vector<ClsBankClient> vClient ; 
        fstream MyFile ; 
        string Line ; 
        MyFile.open("Clients.txt",ios::in) ; 
        if ( MyFile.is_open())
        {
            while ( getline(MyFile,Line) )
            {
                ClsBankClient Client = _ConvertLineToClientInfo(Line,"#//#") ;
                if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
                {
                    MyFile.close() ;
                    return Client ;
                }
            }
            MyFile.close() ;
        }
        return _GetEmptyClient() ;
    }

    static bool IsClientExist(string AccountNumber)
    {
        ClsBankClient Client = Find(AccountNumber) ; 
        return !(Client._Mode == _enMode::EmptyMode) ;
    }

    void PrintClient()
    {
        cout << "Client Card : "<< endl ; 
        cout << "------------------------------------------------------------------------------" << endl ;
        cout << setw(16) << left <<"First Name" << ":  " << GetFirstName() << endl ;
        cout << setw(16) << left <<"Last Name"  << ":  " << GetLastName() << endl ;
        cout << setw(16) << left <<"Email"  << ":  " << GetEmail() << endl ;
        cout << setw(16) << left <<"Phone Number"  << ":  " << GetPhoneNumber() << endl ;
        cout << setw(16) << left <<"Account Number" << ":  " << _AccountNumber << endl ;
        cout << setw(16) << left <<"Pin Code" << ":  " << GetPinCode() << endl ;
        cout << setw(16) << left <<"Account Balance" << ":  " << GetAccountBalance() << endl ;
        cout << "------------------------------------------------------------------------------" << endl ;
    }

    enum enSave{FailedSave = 0 , SuccessfullySave = 1 , AlreadyExist = 2} ; 
    enSave SaveClientInFile()
    {
        vector<ClsBankClient> vClients = _ReadClientFromFile("Clients.txt") ; 
        if (_Mode == _enMode::EmptyMode)
        {
            return enSave::FailedSave ;
        }
        else if (_Mode == _enMode::UpdateMode)
        {
            for (ClsBankClient &C : vClients)
            {
                if ( GetAccountNumber() == C.GetAccountNumber())
                {
                    C = *this ;
                }
            }
            _SaveAllClients(vClients) ; 
            return enSave::SuccessfullySave ; 
        }
        else if (_Mode == _enMode::AddMode)
        {
            if (ClsBankClient::IsClientExist(GetAccountNumber()))
            {
                return enSave::AlreadyExist ;
            }
            else
            {
                vClients.push_back(*this) ; 
                _SaveAllClients(vClients) ; 
                return enSave::SuccessfullySave ;
            }
        } 
        return enSave::FailedSave ;
    }
    static ClsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return ClsBankClient(_enMode::AddMode,"","","","",AccountNumber,"",0) ;
    }
    static ClsBankClient DeleteClientObject(string AccountNumber)
    {
        return _Delete(AccountNumber) ;
    }
    static vector<ClsBankClient> ReadClients()
    {
        return _ReadClientFromFile("Clients.txt") ;
    }

    static vector <stTransfereLog> ReadTransferLog()
    {
        return _ReadTransferLogFromFile("TransferLog.txt") ;
    }
    static void SaveToTransferLog(ClsBankClient Client1 , ClsBankClient Client2 , float Amount)
    {
        _SaveToTransferLog(Client1,Client2,Amount) ; 
    }


    static vector<stCurrency> ReadCurrencies()
    {
        return _ReadCurrenciesFromFile("Currencies.txt") ;
    }

    static stCurrency FindCurrencyByCode(string Code)
    {
        vector<stCurrency> vCurr ; 
        fstream MyFile ; 
        string Line ; 
        MyFile.open("Currencies.txt",ios::in) ; 
        if ( MyFile.is_open())
        {
            while ( getline(MyFile,Line) )
            {
                stCurrency Curr = _ConvertLineTostCurrency(Line,"#//#") ;
                if (clsString::UpperAllString(Curr.CountryCode) == clsString::UpperAllString(Code))
                {
                    MyFile.close() ;
                    return Curr ;
                }
            }
            MyFile.close() ;
        }
        stCurrency Curr2 ;
        Curr2.IsEmpty =true ; 
        return  Curr2 ;
    }
    static stCurrency FindCurrencyByCountryName(string CountryName)
    {
        vector<stCurrency> vCurr ; 
        fstream MyFile ; 
        string Line ; 
        MyFile.open("Currencies.txt",ios::in) ; 
        if ( MyFile.is_open())
        {
            while ( getline(MyFile,Line) )
            {
                stCurrency Curr = _ConvertLineTostCurrency(Line,"#//#") ;
                if (clsString::UpperAllString(Curr.CountryName) == clsString::UpperAllString(CountryName))
                {
                    MyFile.close() ;
                    return Curr ;
                }
            }
            MyFile.close() ;
        }
        stCurrency Curr2 ;
        Curr2.IsEmpty =true ; 
        return  Curr2 ;
    }

    static void UpdateRateCarrencyInFile(ClsBankClient::stCurrency Curr)
    {
        _UpdateRateCarrency(Curr) ;
    }
} ;