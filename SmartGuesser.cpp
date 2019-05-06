#include "SmartGuesser.hpp"
using std::string;
using namespace bullpgia;



                                    //pick the first string from the list
string SmartGuesser::guess()        
{
    currGuess = list.front();

    return currGuess;
}
                                    //compare the bull and pgia of the current string to the
                                    // bull and pgia of the strings in the list
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
                                                //build the list by the length
void SmartGuesser::startNewGame(uint length)
{
    this->length = length;

    if (!list.empty())
    {
        list.clear();
    }

    switch (length)
    {

    case 1:                                         //length = 1
        for (int i = 0; i < 10; i++)
        {
            list.push_back(to_string(i));
        }

        break;

    case 2:                                         //length = 2
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
    case 3:                                         //length = 3
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
    case 4:                                         //length = 4
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
