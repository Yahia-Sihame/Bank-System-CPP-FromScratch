#pragma once 
#include <iostream>
#include "ClsScreen.h"
#include "ClsUser.h"
#include "Global.h"
#include "ClsInputValidate.h"
#include "ClsMainScreen.h"

using namespace std ; 

class ClsLoginScreen : protected ClsScreen
{
private : 
    static bool _Login()
    {
        string UserName ; 
        string Password ; 
        int Count = 3 ;
        bool Check = false ;  
        do
        {
            if ( Check && Count )
            {
                cout << "\n\nInvalide UserName/Password!"  ; 
                cout << "\nYou have " << --Count << " Trials To Login." << endl << endl ;
                if ( Count == 0 )
                {
                    cout << "You are Locked After 3 Faild Tials" << endl ;
                    return false ; 
                }
            }
            
            cout << "Enter Your User Name : " ;
            UserName = clsInputValidate::ReadString() ;

            cout << "Enter Your Password : " ;
            Password = clsInputValidate::ReadString() ;

            GlobalUser = ClsUser::Find(UserName,Password) ; 
            if (GlobalUser.IsThisEmpty()) 
            {
                Check = true ; 
            }
            else 
            {
                Check = false ; 
            } 
        }while(Check && Count ) ;
        
        GlobalUser.SaveToLoginRegister();
        ClsMainScreen::MainMenu() ;
        return true ;
    }
public :

    static bool ShowLoginScreen()
    {
        HeaderScreen("Login Screen") ; 
        return _Login();
    }

    
};