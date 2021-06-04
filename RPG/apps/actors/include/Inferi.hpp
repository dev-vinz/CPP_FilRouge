#ifndef INFERI_HPP
#define INFERI_HPP

#include <iostream>

#include "Opponent.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Inferi : public Opponent
    {
    private:
        void blindly(Hero *) const;
        void immobilizes(Hero *) const;
        void onslaught(Hero *) const;

    public:
        Inferi() = delete;
        Inferi(string _name, int _agility, int _intelligence, int _strength, double _hp);
        virtual ~Inferi() override = default;

        void interact(Hero *, Attack _attack) override;

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif