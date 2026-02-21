#include<iostream>
#include<vector>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsUtil.h"
#include "ClsMainScreen.h"
#include "ClsUser.h"
#include "ClsLoginScreen.h"

using namespace std ;




int main()
{
    // ClsBankClient Client1 ;
    // Client1 = ClsBankClient::Find("A101","1234") ;
    // Client1.PrintClient() ;

    // ShowClientsList() ;
    // ShowTotaleBalances() ;

    // ClsMainScreen::MainMenu() ; 
    // ClsUser User1 ; 
    // User1 = ClsUser::Find("User1") ;

    // User1.PrintUser() ; 
    while(true)
    {
        if ( !ClsLoginScreen::ShowLoginScreen() )
            break ; 
    }
}