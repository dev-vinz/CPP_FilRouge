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
        Warrior() = delete;
        Warrior(string _name, int _agility, int _intelligence, int _strength, double _hp, IObject *_pStuff, bool _isPlayer = false);
        virtual ~Warrior() override = default;

        void displayAttacks() const override;
        void interact(Hero *, char _attack) override;
        void show() const override;
    };
}

#endif