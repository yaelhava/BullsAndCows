#include <string>
#include "Guesser.hpp"
#include "calculate.hpp"

namespace bullpgia
{

    class SmartGuesser : public bullpgia::Guesser
    {
        virtual string guess() override;
        virtual string learn(string s) override;
        virtual string startNewGame(int length) override;
    };
}