#pragma once
#include <string>
using namespace std;

namespace bullpgia{

    class Chooser{
        protected:
            string s;
        public:
            virtual std::string choose(uint length)=0;
    };
}