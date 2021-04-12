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
        // Constructors and destructor
        Warrior(int _strength = 0, int _agility = 0, int _intelligence = 0, double _hp = 0, string _name = "no_name");

        // Override methods
        void interact(const Hero &) override;
    };
}

#endif