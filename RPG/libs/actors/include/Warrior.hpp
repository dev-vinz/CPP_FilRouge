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
        Warrior(string _name, int _agility, int _intelligence, int _strength, double _hp, IObject *_pStuff);

        void interact(const Hero &) override;
    };
}

#endif