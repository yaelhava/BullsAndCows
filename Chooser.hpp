#pragma once
#include <string>
using namespace std;

namespace bullpgia
{
    class Chooser
    {
    protected:
        string s;

    public:
        virtual string choose(uint length) = 0;
    };
} // namespace bullpgia