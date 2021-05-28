#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include <iostream>

#include "Player.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Warrior : public Player
    {
    private:
        void earthQuake(Hero *);
        void punch(Hero *) const;
        void swordStrike(Hero *) const;

    public:
        Warrior() = delete;
        Warrior(string _name, int _agility, int _intelligence, int _strength, double _hp, IObject *_pStuff);
        virtual ~Warrior() override = default;

        void displayAttacks() const override;
        void interact(Hero *, char _attack) override;
        void show() const override;

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif