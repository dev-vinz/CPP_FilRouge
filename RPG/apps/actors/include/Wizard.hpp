#ifndef WIZARD_HPP
#define WIZARD_HPP

#include <iostream>

#include "Player.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Wizard : public Player
    {
    protected:
        int mana = 0;

        void dizzySpell(Hero *) const;
        void giantWave(Hero *) const;

    public:
        Wizard() = delete;
        Wizard(string _name, int _agility, int _intelligence, int _strength, int _mana, double _hp, IObject *_pStuff);
        virtual ~Wizard() override = default;

        int getMana() const;

        void castSpell(Hero *) const;

        virtual void displayAttacks() const override;
        virtual void interact(Hero *, Attack _attack) override;
        virtual void show() const override;

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif