#pragma once
#include<iostream>
using namespace std;
#include "accounts.h"

class AccountsCredits : public Accounts
{
private:
    /* data */
public:
    AccountsCredits( string name);

    virtual void showInfo();
};



