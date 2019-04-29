#include "calculate.hpp"

using std::string;


string bullpgia::calculateBullAndPgia(string choice, string guess)
{
    int bullCounter = 0, pgiaCounter = 0, length = choice.size();
    bool bullArr[length], pgiaArr[length];

    for(int i = 0; i < length; i++){
        if(choice.at(i) == guess.at(i)){
            bullArr[i] = true;
            bullCounter++;
        }
    }

    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            if(!bullArr[i] && !pgiaArr[j]){
                if(choice.at(i) == guess.at(j)){
                    pgiaArr[j] = true;
                    pgiaCounter++;
                }
            }
        }
    }

    return "" + to_string(bullCounter) + ',' + to_string(pgiaCounter);
}
