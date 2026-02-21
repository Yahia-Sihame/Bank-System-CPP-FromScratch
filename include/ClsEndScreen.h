#pragma once

#include "ClsScreen.h"

class ClsEndScreen : protected ClsScreen
{
public : 
    static void EndScreen()
    {
        HeaderScreen("End Programme") ;
    }
} ;