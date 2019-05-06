#include "SmartGuesser.hpp"
using std::string;
using namespace bullpgia;

string SmartGuesser::guess()
{

    currGuess = list.front();

    return currGuess;
}

void SmartGuesser::learn(string s)
{

    for (auto itr = list.begin(); itr != list.end(); itr++)
    {
        if (s != calculateBullAndPgia(currGuess, *itr))
        {
            itr = list.erase(itr);
        }
    }
}

void SmartGuesser::startNewGame(uint length)
{
    this->length = length;

    if (!list.empty())
    {
        list.clear();
    }

    if (length < 5)
    {
        switch (length)
        {

        case 1:
            for (int i = 0; i < 10; i++)
            {
                list.push_back(to_string(i));
            }

            break;

        case 2:
            for (int i = 0; i < 100; i++)
            {
                if (i < 10)
                {
                    list.push_back('0' + to_string(i));
                }
                else
                {
                    list.push_back(to_string(i));
                }
            }
            break;
        case 3:
            for (int i = 0; i < 1000; i++)
            {
                if (i < 10)
                {
                    list.push_back("00" + to_string(i));
                }
                else if (i < 100)
                {
                    list.push_back('0' + to_string(i));
                }
                else
                {
                    list.push_back(to_string(i));
                }
            }
            break;
        case 4:
            for (int i = 0; i < 10000; i++)
            {
                if (i < 10)
                {
                    list.push_back("000" + to_string(i));
                }
                else if (i < 100)
                {
                    list.push_back("00" + to_string(i));
                }
                else if (i < 1000)
                {
                    list.push_back('0' + to_string(i));
                }
                else
                {
                    list.push_back(to_string(i));
                }
            }
            break;
        
        }
    }
    else{} //for length greater then 4
}
