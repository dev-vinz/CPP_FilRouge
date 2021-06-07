#ifndef GAME_HPP
#define GAME_HPP

#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <windows.h>

#include "Battle.hpp"
#include "Map.hpp"

#include "..\..\actors\include\Hero.hpp"
#include "..\..\actors\include\Inferi.hpp"
#include "..\..\actors\include\Medusa.hpp"
#include "..\..\actors\include\Necromancer.hpp"
#include "..\..\actors\include\Vampire.hpp"
#include "..\..\actors\include\Warrior.hpp"
#include "..\..\actors\include\Wizard.hpp"

#include "..\..\enums\Character.hpp"
#include "..\..\enums\Direction.hpp"
#include "..\..\enums\Winner.hpp"

#include "..\..\stuff\include\MagicWand.hpp"
#include "..\..\stuff\include\Potion.hpp"
#include "..\..\stuff\include\Scepter.hpp"
#include "..\..\stuff\include\Shield.hpp"
#include "..\..\stuff\include\Sword.hpp"

#include "..\..\utils\include\ConsoleController.hpp"
#include "..\..\utils\include\Logger.hpp"
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

        Winner gWinner = Winner::WNull;

        bool checkFight(char _fight) const;
        bool checkMovement(Direction _movement, Hero *) const;

        void applyFight(char _fight, Hero *);
        void applyMovements(Direction _movement);
        void catchPotion(int _x, int _y);
        void display() const;
        void setPositions();

    public:
        Game();
        Game(int _width, int _height, int _nbOpponents);
        virtual ~Game();

        Map getMap() const;
        vector<Hero *> getOpponents() const;

        void choosePlayer(string _name);
        void end() const;
        void initialize();
        void play();

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif
