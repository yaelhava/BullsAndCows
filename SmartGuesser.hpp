#include <string>
#include "Guesser.hpp"
#include "calculate.hpp"

namespace bullpgia{

    class SmartGuesser : public bullpgia::Guesser{
         string guess() override;
	     void learn(string s) override;
         void startNewGame(uint length) override;
    };
}