#include <iostream>
#include "manage.h"
#include "accounts.h"
#include "accountsCredit.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    Manage m;
    std::vector<std::string> choices;
    std::string inputLine;

    // while(true)
    // {
        cout << "Please input your code" << endl;

        std::getline(std::cin, inputLine);

        std::istringstream iss(inputLine);
        std::string word;

        while (iss >> word) {
            choices.push_back(word);
        }

        // std::cout << "Vector contents:";
        // for (const auto& w : choices) {
        //     std::cout << " " << w;
        // }

        // std::cout << std::endl;
        
        // Display the first item in the vector
        if (!choices.empty()) {
            // std::cout << "First item in the vector: " << choices[0] << std::endl;

            // Check the value of the first item using if and else if
            if (choices[0] == "add") {
                // add user
                m.Add_Acc(choices[1]);

            } else if (choices[0] == "show") {
                // show users
                m.Show_Acc();
            } else if (choices[0] == "update") {
                // update user
                m.Mod_Acc(choices[1], choices[2]);
            } else if (choices[0] == "delete") {
                m.Del_Acc(choices[1]);
                // remove user
            } else if (choices[0] == "search") {
                // search user
                m.Search_Acc(choices[1]);
            } else {
                // default case
                exit(0);
            }
        } else {
            std::cout << "Vector is empty." << std::endl;
        }

    // }



    return 0;
}

