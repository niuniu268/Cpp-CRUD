#include "manage.h"

Manage::Manage()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open())
    {   
        this->m_Num = 0;
        this->m_Array = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        this->m_Num = 0;
        this->m_Array = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;

    }

    int num = this->get_Num();
    this->m_Num = num;
    this->m_Array = new Accounts *[this->m_Num];
    this->init_Emp();

    // cout<< num << endl;
    // for (int i = 0; i < m_Num; i++)
    // {
    //     cout << this->m_Array[i]->m_Name<<endl;
    // }
    
    

}

Manage::~Manage()
{

}

void Manage::Show_Menu()
{
    cout << "**********************" << endl;
}

void Manage::ExitSys()
{
    cin.ignore();
    exit(0);
}

void Manage::Add_Acc(string input)
{
    int check = IsExist(input);

    if (check >= 0)
    {
        cout<<"account already exists"<<endl;
        return;
    }
     
    int newSize = this->m_Num + 1;

    Accounts ** newSpace = new Accounts*[newSize];

    if (this->m_Array != NULL)
    {
        for (int i = 0; i < this->m_Num; i++)
        {
            newSpace[i] = this->m_Array[i];
        }
        
    }
    
    Accounts * account = NULL;

    account = new AccountsCredits(input);
    
    newSpace[this->m_Num] = account;

    delete[] this->m_Array;
    this->m_Array = newSpace;
    this ->m_Num = newSize;
    this->m_FileIsEmpty = false;

    this->save();

    cout << "success" << endl;


}

void Manage::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_Num; i++)
    {
        ofs << this->m_Array[i]->m_Name << endl;
    }
    ofs.close();
}

int Manage::get_Num()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    string name;
    int num = 0;
    while (ifs>>name)
    {
        num++;
    }
    return num;
}

void Manage::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    string name;

    int index = 0;

    while (ifs >> name)
    {
        Accounts * account = NULL;
        account = new AccountsCredits(name);
        this->m_Array[index] = account;
        index++;
    }
    ifs.close();
    
}

void Manage::Show_Acc()
{
    if (this->m_FileIsEmpty)
    {
        cout<< "file is empty or file does not exit" <<endl;
    } else
    {
        for (int i = 0; i < this->m_Num; i++)
        {
            this->m_Array[i]->showInfo();
        }
        
    }


    
}

void Manage::Del_Acc(string input)
{
    int check = IsExist(input);

    if (check != -1)
    {

        for (int i = check; i < this->m_Num-1; i++)
        {
            this->m_Array[i] = this->m_Array[i + 1];
        }

        this->m_Num--;
        this->save();

        cout<<"success"<<endl;
    }


    

}
int Manage::IsExist(string name)
{
    int index = -1;

    for (int i = 0; i < this->m_Num; i++)
    {
        if (this->m_Array[i]->m_Name == name)
        {
            index = i;
            break;

        }
        
    }
    return index;
    
}

void Manage::Mod_Acc(string oldInput, string newInput)
{
    int index = IsExist(oldInput);

    if (index != -1)
    {

        delete this->m_Array[index];

        Accounts * account = new AccountsCredits(newInput);
        account->m_Name = newInput;

        this->m_Array[index] = account;

        this->save();

        cout<<"success"<<endl;

    }
    else
    {
        cout<<"failure update"<<endl;
    }

}

void Manage::Search_Acc(string input)
{
    int check = IsExist(input);

    if (check != -1)
    {

        cout<< input+"exists"<<endl;
    }else
    {
        cout<< input+"does not exist"<<endl;
    }
    

}