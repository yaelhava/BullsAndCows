#include <string>
#include "Guesser.hpp"
#include "calculate.hpp"
#include <list>
using namespace std;


namespace bullpgia{

    //this class represents a smart guesser that crack the code in 100 turns

    class SmartGuesser : public bullpgia::Guesser{

        private:
        list<string> list;              //will save all the options
        string currGuess;               //save the current guess

        public:
         string guess() override;
	     void learn(string s) override;
         void startNewGame(uint length) override;
    };
}