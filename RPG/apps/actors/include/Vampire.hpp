#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <iostream>

#include "Opponent.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Vampire : public Opponent
    {
    private:
        void batAttack(Hero *) const;
        void sucks(Hero *);
        void scare(Hero *) const;

    public:
        Vampire() = delete;
        Vampire(string _name, int _agility, int _intelligence, int _strength, double _hp);
        virtual ~Vampire() override = default;

        void interact(Hero *, Attack _attack) override;

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif