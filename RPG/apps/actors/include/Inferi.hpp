#ifndef INFERI_HPP
#define INFERI_HPP

#include <iostream>

#include "Opponent.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Inferi : public Opponent
    {
    public:
        Inferi() = delete;
        Inferi(string _name, int _agility, int _intelligence, int _strength, double _hp);
        virtual ~Inferi() override = default;

        void interact(Hero *, char _attack) override;

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif