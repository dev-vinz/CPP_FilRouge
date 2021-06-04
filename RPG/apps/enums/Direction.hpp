#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include <iostream>

using namespace std;

namespace HE_Arc::RPG
{
    enum class Direction
    {
        Up = 'w',
        Left = 'a',
        Down = 's',
        Right = 'd',
        NotMove = 'n',
        QuitGame = 'q'
    };
}

#endif