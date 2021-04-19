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
        // Constructors and Destructor
        Necromancer(int _strength, int _agility, int _intelligence, double _hp, int _mana, string _name, IObject *_pStuff);

        // Void methods
        void riseUndead();
    };
}

#endif