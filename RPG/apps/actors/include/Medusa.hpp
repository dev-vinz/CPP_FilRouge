#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include <iostream>

#include "Opponent.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Medusa : public Opponent
    {
    private:
        void petrification(Hero *) const;
        void seduce(Hero *) const;
        void snakeAttack(Hero *) const;

    public:
        Medusa() = delete;
        Medusa(string _name, int _agility, int _intelligence, int _strength, double _hp);
        virtual ~Medusa() override = default;

        void interact(Hero *, Attack _attack) override;

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif