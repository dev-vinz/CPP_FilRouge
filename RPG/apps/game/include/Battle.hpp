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
        TNull = -1,
        TPlayer = 0,
        TOpponent = 1,
        TNone = 2
    };

    class Battle
    {
    private:
        bool isOver = false;

        Hero *player;
        Hero *opponent;

        Turn turn = Turn::TPlayer;
        Turn winner = Turn::TNull;

        bool checkNumber(int _range, char _number) const;
        bool checkYesNo(char _yn) const;

        void display() const;
        void nextTurn();
        void playerTurn();
        void opponentTurn();

        void concede();
        void fight(Hero *, Hero *);
        void openBackPack() const;
        void prepareDodge(Hero *) const;

    public:
        Battle() = delete;
        Battle(Hero *, Hero *);

        Hero *getWinner();

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif