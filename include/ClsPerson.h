#pragma once

#include<iostream>
using namespace std ; 

class ClsPerson
{
private :
    string _FirstName ; 
    string _LastName ; 
    string _Email ; 
    string _PhoneNumber ; 
public :
    ClsPerson()
    {
        _FirstName = "" ;
        _LastName = "" ;
        _Email = "" ;
        _PhoneNumber = "" ;
    }
    ClsPerson(string FirstName , string LastName , string Email , string PhoneNumber)
    {
        _FirstName = FirstName ; 
        _LastName = LastName ; 
        _Email = Email ; 
        _PhoneNumber = PhoneNumber ;
    }
    // Setters
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName ; 
    }
    void SetLastName(string LastName)
    {
        _LastName = LastName ; 
    }
    
    void SetEmail(string Email)
    {
        _Email = Email ;
    }
    void SetPhoneNumber(string PhoneNumber)
    {
        _PhoneNumber = PhoneNumber ;
    }

    // Getters
    string GetFirstName()
    {
        return _FirstName ;
    }
    string GetLastName()
    {
        return _LastName ; 
    }
    string GetEmail()
    {
        return _Email ;
    }
    string GetPhoneNumber()
    {
        return _PhoneNumber ;
    }



} ; 
