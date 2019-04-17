#pragma once
#include <string>
using namespace std;

namespace bullpgia{
    class Guesser{
        protected:
            int length;
            std::string s;

        public:
		    virtual string guess() = 0;
            virtual string learn(string s);
            virtual string startNewGame(int length);

    };
}