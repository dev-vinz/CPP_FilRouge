#ifndef NECROMANCER_HPP
#define NECROMANCER_HPP

#include <iostream>

#include "Wizard.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Necromancer : public Wizard
    {
    public:
        Necromancer() = delete;
        Necromancer(string _name, int _agility, int _intelligence, int _strength, int _mana, double _hp, IObject *_pStuff, bool _isPlayer = false);
        virtual ~Necromancer() override = default;

        void riseUndead();

        void displayAttacks() const override;
        void show() const override;
    };
}

#endif