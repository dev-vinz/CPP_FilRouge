#ifndef TURN_HPP
#define TURN_HPP

#include <iostream>

using namespace std;

namespace HE_Arc::RPG
{
    enum class Turn
    {
        TNull = 'l',
        TPlayer = 'p',
        TOpponent = 'o',
        TNone = 'n'
    };
}

#endif