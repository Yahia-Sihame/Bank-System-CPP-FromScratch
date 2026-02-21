#pragma once 

#include<iostream>
#include<iomanip>
#include "ClsUser.h"
#include "Global.h"
#include "ClsDate.h" 
#include "ClsInputValidate.h"
using namespace std ; 

class ClsScreen
{
protected : 
    static void HeaderScreen(string Title , string SubTitle = "")
    {
        clsDate Date = clsDate::GetSystemDate() ; 
        cout << endl ;
        cout << setw(35) << " " << "-----------------------------------------------------------------------\n"  ;
        cout << setw(35) << " " << "\t\t\t\t" << Title << "\n" ; 
        cout << setw(35) << " " << "\t\t\t\t" << SubTitle << "\n" ; 
        cout << setw(35) << " " << "User : " << GlobalUser.GetUserName() <<"\n" ; 
        cout << setw(35) << " " << "Date : " << Date.GetDay() << "/" << Date.GetMonth() << "/" << Date.GetYear() << "\n\n" ; 
        cout << setw(35) << " " << "-----------------------------------------------------------------------\n"  ;
    }

    static bool ShowPermissions(ClsUser::enPermissions Permissions)
    {
        if (!GlobalUser.CheckPermissions(Permissions))
        {
            cout << endl ;
            cout << setw(35) << " " << "-----------------------------------------------------------------------\n"  ;
            cout << setw(35) << " " << "\t\t\t" << "Acces Denied! Contact your Admin" << "\n" ; 
            cout << setw(35) << " " << "-----------------------------------------------------------------------\n"  ;
            return false ; 
        }
        return true ;
    }

    static bool CheckForOption(string message)
    {
        cout << endl ;
        cout << message ;
        string Check = clsInputValidate::ReadString() ;
        if (Check[0] == 'n' || Check[0] == 'N')
            return false ; 
        return true ; 
    }

} ;