#ifndef OPPONENT_HPP
#define OPPONENT_HPP

#include <iostream>

#include "Hero.hpp"

#include "..\..\stuff\include\Shield.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Opponent : public Hero
    {
    private:
        void useObject(IObject *) override          { cout << "[UNAUTHORIZED] Opponent::useObject()" << endl;          exit(-1); }
        void displayAttacks() const override        { cout << "[UNAUTHORIZED] Opponent::displayAttacks()" << endl;     exit(-1); }
        void show() const override                  { cout << "[UNAUTHORIZED] Opponent::show()" << endl;               exit(-1); }

    public:
        Opponent() = delete;
        Opponent(string _name, int _agility, int _intelligence, int _strength, double _hp);
        virtual ~Opponent() override = default;

        void virtual interact(Hero *, char _attack) override = 0;

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif