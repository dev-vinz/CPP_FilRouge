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
        int mana = 0;

    public:
        Wizard() = default;
        Wizard(string _name, int _agility, int _intelligence, int _strength, double _hp, int _mana, IObject *_pStuff);

        int getMana() const;

        void castSpell();

        void interact(const Hero &) override;
        void show() const override;
    };
}

#endif