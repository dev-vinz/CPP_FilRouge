#ifndef GAME_HPP
#define GAME_HPP

#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <unistd.h>
#include <vector>
#include <winsock2.h> // Sinon ça fout un warning bizarre (cpr)
#include <windows.h>

#include "Map.hpp"

#include "..\..\actors\include\Hero.hpp"
#include "..\..\actors\include\Necromancer.hpp"
#include "..\..\actors\include\Warrior.hpp"
#include "..\..\actors\include\Wizard.hpp"

#include "..\..\stuff\include\Potion.hpp"
#include "..\..\stuff\include\Shield.hpp"
#include "..\..\stuff\include\Sword.hpp"

#include "..\..\utils\include\RandomGenerator.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Game
    {
    private:
        Map currentMap;
        int nbOpponents;
        int nbPotions;

        bool isPlaying = false;

        Hero *player;
        vector<Hero *> listOpponents;
        vector<Potion *> listPotions;

        bool checkAction(char _action);
        bool checkFight(char _fight);
        bool checkMovement(char _movement, Hero *);

        void applyMovements(char _movement);
        void catchPotion(int _x, int _y);
        void display() const;
        void setPositions();

    public:
        Game();
        Game(int _width, int _height, int _nbOpponents);
        ~Game();

        Map getMap() const;
        vector<Hero *> getOpponents() const;

        void choosePlayer(string _name);
        void initialize();
        void play();

        static const bool VJ_DEBUG_LOG = true;
    };
}

#endif
