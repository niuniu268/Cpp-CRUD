#include "accountsCredit.h"

AccountsCredits::AccountsCredits(string name)
{
    this->m_Name = name;
}

void AccountsCredits::showInfo()
{
    cout << "account name: " << this ->m_Name << endl;
}