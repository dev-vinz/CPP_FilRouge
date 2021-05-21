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
        Wizard() = delete;
        Wizard(string _name, int _agility, int _intelligence, int _strength, int _mana, double _hp, IObject *_pStuff, bool _isPlayer = false);
        virtual ~Wizard() override = default;

        int getMana() const;

        void castSpell();

        virtual void displayAttacks() const override;
        void interact(const Hero &) override;
        virtual void show() const override;
    };
}

#endif