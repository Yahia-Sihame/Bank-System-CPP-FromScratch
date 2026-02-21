#pragma once

#include<iostream>
#include<vector>
#include "ClsUser.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"
#include "ClsUtil.h"

class ClsLoginRegisterScreen : protected ClsScreen 
{
private : 

    static void _PrintUserRecordBalanceLine(ClsUser::LoginRegisterinfo User)
    {
        cout << "\t\t\t|  "<< setw(17) << left <<User.DateTime  ;
        cout << "\t\t\t|  "<< setw(17) << left <<User.UserName ;
        cout << "\t\t\t|  "<< setw(17) << left <<User.Password ;
        cout << "\t\t\t|  "<< setw(17) << left <<User.Permissions ;
    }
public : 
    static void LoginRegisterScreen()
    {
        if (!ClsScreen::ShowPermissions(ClsUser::enPermissions::pLoginRegister))
        {
            return ;
        }
        vector<ClsUser::LoginRegisterinfo> Users = ClsUser::ReadLoginRegister() ;
        string Title = "Login Register List Screen" ;
        string SubTitle = " (" + to_string(Users.size()) + ") Records(s)" ;
        HeaderScreen(Title,SubTitle) ;

        cout << "\n\t\t============================================================================================================================================================\n" ;
        cout << setw(20) << left << "\t\t\t|  Date/Time " ; 
        cout << setw(20) << left << "\t\t\t|  User Name " ; 
        cout << setw(20) << left << "\t\t\t|  Password " ; 
        cout << setw(20) << left << "\t\t\t|  Permissions " ; 
        cout << "\n\t\t============================================================================================================================================================\n" ;
        if (Users.size() == 0)
        {
            cout << "\t\t\t\t\t\t No Login Rgister Available In the Systeme !" << endl ; 
            cout << "\t\t============================================================================================================================================================\n" ;
        }
        else
        {
            for (ClsUser::LoginRegisterinfo User : Users)
            {
                _PrintUserRecordBalanceLine(User)  ;
                cout << endl ; 
            }
        }
    }

} ;