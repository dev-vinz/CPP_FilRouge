#ifndef WIZARD_HPP
#define WIZARD_HPP

#include <iostream>

#include "Hero.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Wizard : public Hero
    {
    protected:
        // Attributes
        int mana;

    public:
        // Constructors and destructor
        Wizard(int _strength = 0, int _agility = 0, int _intelligence = 0, double _hp = 0, string _name = "no_name", int _mana = 0);

        // Methods void
        void castSpell();

        // Override methods
        void interact(const Hero &) override;
        void show() const override;
    };
}

#endif