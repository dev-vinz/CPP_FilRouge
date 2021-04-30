#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <cmath>
#include <ctime>
#include <list>

#include "Map.hpp"

#include "..\..\actors\include\Hero.hpp"
#include "..\..\actors\include\Necromancer.hpp"
#include "..\..\actors\include\Warrior.hpp"
#include "..\..\actors\include\Wizard.hpp"

#include "..\..\stuff\include\Potion.hpp"
#include "..\..\stuff\include\Shield.hpp"
#include "..\..\stuff\include\Sword.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Game
    {
    private:
        Map currentMap;
        int nbOpponents;

        Hero *player;
        list<Hero *> listOpponents;

        void setPositions();

    public:
        Game();
        Game(int _width, int _height, int _nbOpponents);
        ~Game();

        Hero *getPlayer() const;

        Map getMap() const;

        void display() const;
    };
}

#endif
