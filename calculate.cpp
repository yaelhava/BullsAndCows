#include "calculate.hpp"

/////////////////////////////////
#include <iostream>

using std::string;

string bullpgia::calculateBullAndPgia(string choice, string guess)
{
    int bullCounter = 0, pgiaCounter = 0, length = choice.size();
    bool bullArr[length], pgiaArr[length];

    for (int i = 0; i < length; i++)
    {
        bullArr[i] = 0;
        pgiaArr[i] = 0;
    }

    for (int i = 0; i < length; i++)
    {
        if (choice.at(i) == guess.at(i))
        {
            bullArr[i] = true;
            pgiaArr[i] = true;
            bullCounter++;
        }
    }

    for (int i = 0; i < length; i++)
    {
        if (bullArr[i])     
            continue;
        
        for (int j = 0; j < length; j++)
        {
            if (!pgiaArr[j])
            {
                if (choice.at(i) == guess.at(j))
                {
                    pgiaArr[j] = true;
                    pgiaCounter++;
                    break;
                }
            }
        }
    }

    return "" + to_string(bullCounter) + ',' + to_string(pgiaCounter);
}

// int main()
// {
//     cout << bullpgia::calculateBullAndPgia("1234", "4321") << endl;

//     return 0;
// }
