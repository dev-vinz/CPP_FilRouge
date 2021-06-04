#ifndef WINNER_HPP
#define WINNER_HPP

#include <iostream>

using namespace std;

namespace HE_Arc::RPG
{
    enum class Winner
    {
        WNull,
        WPlayer,
        WOpponent,
        WQuit,
        WNone
    };
}

#endif