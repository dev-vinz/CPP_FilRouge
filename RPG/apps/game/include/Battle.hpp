#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <iomanip>
#include <iostream>

#include "..\..\actors\include\Hero.hpp"

#include "..\..\utils\include\ConsoleController.hpp"
#include "..\..\utils\include\RandomGenerator.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    enum Turn
    {
        Null = -1,
        Player = 0,
        Opponent = 1
    };

    class Battle
    {
    private:
        bool isOver = false;

        Hero *player;
        Hero *opponent;

        Turn turn = Player;
        Turn winner = Null;

        bool checkNumber(int _range, char _number) const;
        bool checkYesNo(char _yn) const;

        void display() const;
        void nextTurn();
        void playerTurn();
        void opponentTurn();

        void fight(Hero *, Hero *) const;
        void openBackPack() const;

    public:
        Battle() = delete;
        Battle(Hero *, Hero *);

        Hero *getWinner();

        static const bool VJ_DEBUG_LOG = true;
    };
}

#endif