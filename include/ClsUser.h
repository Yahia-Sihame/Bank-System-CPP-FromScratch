#pragma once 

#include<iostream>
#include<vector>
#include<fstream>
#include "ClsString.h"
#include "ClsPerson.h"
#include "ClsDate.h"
#include "ClsUtil.h"

using namespace std ; 


class ClsUser : public ClsPerson
{
public : 

    typedef struct LoginRegisterinfo
    {
        string DateTime ; 
        string UserName ; 
        string Password ; 
        int Permissions ; 
    } LoginRegisterinfo ;

private :
    enum _enMode{EmptyMode = 0 , UpdateMode = 1 , AddMode = 2} ; 
    _enMode _Mode ; 
    string _UserName ; 
    string _Password ; 
    int _Permissions ;

    bool Delete = false ; 

    static ClsUser _ConvertLineToUserInfo(string Line , string sep)
    {
        vector<string> vstr = clsString::Split(Line,sep) ;
        ClsUser User ; 
        return ClsUser(_enMode::UpdateMode,vstr[0],vstr[1],vstr[2],vstr[3],vstr[4],(vstr[5]),stoi(vstr[6])) ; 
    }

    static ClsUser _ConvertLineToUserInfoEcrypted(string Line , string sep)
    {
        vector<string> vstr = clsString::Split(Line,sep) ;
        ClsUser User ; 
        return ClsUser(_enMode::UpdateMode,vstr[0],vstr[1],vstr[2],vstr[3],vstr[4],vstr[5],stoi(vstr[6])) ; 
    }

    static LoginRegisterinfo _ConvertLoginRegister(string Line , string sep)
    {
        vector<string> vstr = clsString::Split(Line,sep) ;
        LoginRegisterinfo Info ; 
        Info.DateTime = vstr[0] ; 
        Info.UserName = vstr[1] ; 
        Info.Password = vstr[2] ; 
        Info.Permissions = stoi(vstr[3]) ; 
        return Info ; 
    }
    
    static ClsUser _GetEmptyUser()
    {
        return ClsUser(_enMode::EmptyMode,"","",0) ;
    }

    static string _ConvertUserToLine(ClsUser User , string sep)
    {
        string Line = "";
        Line += User.GetFirstName() + sep ; 
        Line += User.GetLastName() + sep ; 
        Line += User.GetEmail() + sep ; 
        Line += User.GetPhoneNumber() + sep ; 
        Line += User.GetUserName() + sep ; 
        Line += User.GetPassword() + sep ; 
        Line += to_string(User.GetPermissions())  ; 

        return Line ;
    }
    static string _ConvertUserLoginToLine(ClsUser User , string sep)
    {
        string Line = "";
        clsDate Date ; 
        Line += clsDate::GetSystemDateTimeString() + sep ; 
        Line += User.GetUserName() + sep ; 
        Line += User.GetPassword() + sep ; 
        Line += to_string(User.GetPermissions())  ; 

        return Line ;
    }
    static vector<ClsUser> _ReadUserFromFile(string NameFile)
    {
        vector<ClsUser> vUsers ; 
        fstream MyFile ; 
        MyFile.open(NameFile,ios::in) ; 
        if ( MyFile.is_open() )
        {
            string Line ;
            while (getline(MyFile,Line))
            {
                vUsers.push_back(_ConvertLineToUserInfo(Line,"#//#")) ;
            }
            MyFile.close() ;
        }
        return vUsers ;
    }

    static vector<LoginRegisterinfo> _ReadLoginRegister(string NameFile)
    {
        vector<LoginRegisterinfo> Info ; 
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

    static void _SaveAllUsers(vector<ClsUser> vUsers) 
    {
        fstream MyFile ; 
        MyFile.open("Users.txt",ios::out) ; 
        if (MyFile.is_open())
        {
            for (ClsUser &User : vUsers)
            {
                if ( User.Delete == false )
                    MyFile << _ConvertUserToLine(User,"#//#") << endl ;
            }
            MyFile.close() ; 
        }
    }

    static ClsUser _Delete(string UserName)
    {
        vector<ClsUser> vUsers = _ReadUserFromFile("Users.txt") ;
        for ( ClsUser &User : vUsers)
        {
            if (User.GetUserName() == UserName)
            {
                User.Delete = true ; 
            }
        }
        _SaveAllUsers(vUsers) ;
        return ClsUser(_enMode::EmptyMode,"","",0) ;
    }

    void _SaveToLoginRegister()
    {
        fstream MyFile ; 
        MyFile.open("LoginRegister.txt", (ios::out | ios::app) ) ; 
        if ( MyFile.is_open())
        {
            MyFile << _ConvertUserLoginToLine(*this,"#//#") << endl ;
        }
        MyFile.close() ; 
    }
public : 

    ClsUser()
    {

    }

    ClsUser(_enMode Mode , string UserName , string Password , int Permissions)
    {
        _Mode = Mode ; 
        _UserName = UserName ; 
        _Password = Password ; 
        _Permissions = Permissions ; 
    }
    
    ClsUser(_enMode Mode , string FirstName , string LastName , string Email , string PhoneNumber , string UserName , string Password , int Permissions)
    : ClsPerson(FirstName , LastName , Email , PhoneNumber) 
    {
        _Mode = Mode ; 
        _UserName = UserName ; 
        _Password = Password ; 
        _Permissions = Permissions ; 
    }

    void setUserName(string UserName)
    {
        _UserName = UserName ; 
    }

    string GetUserName()
    {
        return _UserName ; 
    }
    
    void setPassword(string Password)
    {
        _Password = Password ; 
    }

    string GetPassword()
    {
        return _Password ; 
    }

    void setPermissions(int Permissions)
    {
        _Permissions = Permissions ; 
    }

    int GetPermissions()
    {
        return _Permissions ;
    }

    static ClsUser Find(string UserName)
    {
        vector<ClsUser> vUsers ; 
        fstream MyFile ; 
        string Line ; 
        MyFile.open("Users.txt",ios::in) ; 
        if ( MyFile.is_open())
        {
            while ( getline(MyFile,Line) )
            {
                ClsUser User = _ConvertLineToUserInfo(Line,"#//#") ;
                if (User.GetUserName() == UserName)
                {
                    MyFile.close() ;
                    return User ;
                }
            }
            MyFile.close() ;
        }
        return _GetEmptyUser() ;
    }

    static bool IsUserExist(string UserName)
    {
        ClsUser User = Find(UserName) ; 
        return !(User._Mode == _enMode::EmptyMode) ;
    }

    bool IsThisEmpty()
    {
        return (_Mode == _enMode::EmptyMode) ;
    }

    static ClsUser Find(string UserName , string Passeword)
    {
        vector<ClsUser> vUsers ; 
        fstream MyFile ; 
        string Line ; 
        MyFile.open("Users.txt",ios::in) ; 
        if ( MyFile.is_open())
        {
            while ( getline(MyFile,Line) )
            {
                ClsUser User = _ConvertLineToUserInfo(Line,"#//#") ;
                if (User.GetUserName() == UserName && User.GetPassword() == Passeword)
                {
                    MyFile.close() ;
                    return User ;
                }
            }
            MyFile.close() ;
        }
        return _GetEmptyUser() ;
    }


    enum enSave{FailedSave = 0 , SuccessfullySave = 1 , AlreadyExist = 2} ; 
    enSave SaveUserInFile()
    {
        vector<ClsUser> vUsers = _ReadUserFromFile("Users.txt") ; 
        if (_Mode == _enMode::EmptyMode)
        {
            return enSave::FailedSave ;
        }
        else if (_Mode == _enMode::UpdateMode)
        {
            for (ClsUser &U : vUsers)
            {
                if ( GetUserName() == U.GetUserName())
                {
                    U = *this ;
                }
            }
            _SaveAllUsers(vUsers) ; 
            return enSave::SuccessfullySave ; 
        }
        else if (_Mode == _enMode::AddMode)
        {
            if (ClsUser::IsUserExist(GetUserName()))
            {
                return enSave::AlreadyExist ;
            }
            else
            {
                vUsers.push_back(*this) ; 
                _SaveAllUsers(vUsers) ; 
                return enSave::SuccessfullySave ;
            }
        } 
        return enSave::FailedSave ;
    }

    static ClsUser GetAddNewUserObject(string UserName)
    {
        return ClsUser(_enMode::AddMode,UserName,"",0) ;
    }

    static ClsUser DeleteUserObject(string UserName)
    {
        return _Delete(UserName) ;
    }

    static vector<ClsUser> ReadUsers()
    {
        return _ReadUserFromFile("Users.txt") ;
    }

    static vector<LoginRegisterinfo> ReadLoginRegister()
    {
        return _ReadLoginRegister("LoginRegister.txt") ;
    }

    void PrintUser()
    {
        cout << "User Card : "<< endl ; 
        cout << "------------------------------------------------------------------------------" << endl ;
        cout << setw(16) << left <<"First Name" << ":  " << GetFirstName() << endl ;
        cout << setw(16) << left <<"Last Name"  << ":  " << GetLastName() << endl ;
        cout << setw(16) << left <<"Email"  << ":  " << GetEmail() << endl ;
        cout << setw(16) << left <<"Phone Number"  << ":  " << GetPhoneNumber() << endl ;
        cout << setw(16) << left <<"UserName" << ":  " << GetUserName() << endl ;
        cout << setw(16) << left <<"Password" << ":  " << GetPassword() << endl ;
        cout << setw(16) << left <<"Permissions" << ":  " << GetPermissions() << endl ;
        cout << "------------------------------------------------------------------------------" << endl ;
    }

    enum enPermissions{pAll = -1 , pListClient = 1 , pAddNewClient = 2 , pDeleteClient = 4 , pUpdateClient = 8 , pFindClient = 16 , pTransactions = 32 , pManageUsers = 64 , pLoginRegister = 128 , pCurrencyExchange = 256} ;


    bool CheckPermissions(enPermissions Permissions)
    {
        if ( _Permissions == enPermissions::pAll  )
        {
            return true ; 
        }
        if ((Permissions & _Permissions) == Permissions)
        {
            return true ; 
        }
        return false ; 
    }

    void SaveToLoginRegister()
    {
        _SaveToLoginRegister() ;
    }
};