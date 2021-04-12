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
        // Constructors and destructor
        Necromancer(int _strength = 0, int _agility = 0, int _intelligence = 0, double _hp = 0, string _name = "no_name", int _mana = 0);

        // Methods void
        void riseUndead();
    };
}

#endif