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

        void dizzySpell(Hero *) const;
        void giantWave(Hero *) const;

    public:
        Wizard() = delete;
        Wizard(string _name, int _agility, int _intelligence, int _strength, int _mana, double _hp, IObject *_pStuff, bool _isPlayer = false);
        virtual ~Wizard() override = default;

        int getMana() const;

        void castSpell(Hero *) const;

        virtual void displayAttacks() const override;
        virtual void interact(Hero *, char _attack) override;
        virtual void show() const override;

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif