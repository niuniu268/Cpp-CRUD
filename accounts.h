#pragma once
#include<iostream>
#include<string>

using namespace std;

class Accounts
{
    public:

        virtual void showInfo() = 0;

        string m_Name;

        virtual ~Accounts() {}
};