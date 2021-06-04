#ifndef NECROMANCER_HPP
#define NECROMANCER_HPP

#include <iostream>

#include "Wizard.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Necromancer : public Wizard
    {
    private:
        void cataclysm(Hero *);
        void lifeSteal(Hero *);

    public:
        Necromancer() = delete;
        Necromancer(string _name, int _agility, int _intelligence, int _strength, int _mana, double _hp, IObject *_pStuff);
        virtual ~Necromancer() override = default;

        void riseUndead(Hero *);

        void displayAttacks() const override;
        void interact(Hero *, Attack _attack) override;
        void show() const override;

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif