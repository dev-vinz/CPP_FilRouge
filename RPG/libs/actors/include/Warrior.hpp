#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include <iostream>

#include "Hero.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Warrior : public Hero
    {
    public:
        // Constructors and Destructor
        Warrior(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pStuff);

        // Override methods
        void interact(const Hero &) override;
    };
}

#endif