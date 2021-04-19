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
        int mana = 0;

    public:
        // Constructors and destructor
        Wizard() = default;
        Wizard(int _strength, int _agility, int _intelligence, double _hp, int _mana, string _name, IObject *_pStuff);

        // Methods void
        void castSpell();

        // Override methods
        void interact(const Hero &) override;
        void show() const override;
    };
}

#endif