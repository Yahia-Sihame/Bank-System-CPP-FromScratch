#pragma once 
#include "ClsUser.h"
#include "ClsScreen.h"
#include "Global.h"

class ClsLogoutScreen 
{
public : 
    static void LogoutScreen()
    {
        GlobalUser = ClsUser::Find("","") ;
        
    }
} ;