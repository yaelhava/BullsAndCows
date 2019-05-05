#include <string>
#include "Guesser.hpp"
#include "calculate.hpp"
#include <list>
using namespace std;


namespace bullpgia{

    class SmartGuesser : public bullpgia::Guesser{

        private:
        list<string> list;
        string currGuess;

        public:
         string guess() override;
	     void learn(string s) override;
         void startNewGame(uint length) override;
    };
}