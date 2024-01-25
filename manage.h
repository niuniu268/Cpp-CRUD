#pragma once
#include<iostream>
#include <string>
#include "accounts.h"
#include "accountsCredit.h"
using namespace std;
#include <fstream>
#define FILENAME "database.txt"


class Manage
{
    public:
        Manage();

        void Show_Menu();

        void ExitSys();

        int m_Num;

        Accounts ** m_Array;

        bool m_FileIsEmpty;

        int get_Num();

        void init_Emp();

        void Add_Acc(string input);
        
        void Show_Acc();

        void Del_Acc(string input);

        int IsExist(string name);

        void Mod_Acc(string oldInput, string newInput);

        void Search_Acc(string input);

        void save();

        ~Manage();
};