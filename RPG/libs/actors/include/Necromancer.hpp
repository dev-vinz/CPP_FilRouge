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
        Necromancer(string _name, int _agility, int _intelligence, int _strength, int _mana, double _hp, IObject *_pStuff);

        void riseUndead();
    };
}

#endif