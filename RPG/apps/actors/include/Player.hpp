#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include "Hero.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Player : public Hero
    {
    public:
        Player() = delete;
        Player(string _name, int _agility, int _intelligence, int _strength, double _hp, IObject *_pStuff);
        virtual ~Player() override = default;

        void useObject(IObject *) override;

        void virtual displayAttacks() const override = 0;
        void virtual interact(Hero *, char _attack) override = 0;
        void virtual show() const override = 0;

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif