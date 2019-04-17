#pragma once
#include <string>
using std::string;

namespace bullpgia{

    class Guesser{
        protected:
            string s;
            int length;
        public:
            virtual string guess()=0;
            virtual void learn(string s){}
            virtual void startNewGame(uint length){}
    };
}