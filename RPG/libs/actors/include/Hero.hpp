#ifndef HERO_HPP
#define HERO_HPP

#include <iostream>
#include <string.h>

#include "..\..\stuff\include\BackPack.hpp"
#include "..\..\stuff\include\IObject.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Hero
    {
    protected:
        int agility = 0;
        int intelligence = 0;
        int strength = 0;

        double hp = 0;

        string name = "no_name";

        IObject *pStuff = nullptr;

        friend ostream &operator<<(ostream &, const Hero &);

    public:
        Hero() = default;
        Hero(string _name, int _agility, int _intelligence, int _strength, double _hp, IObject *_pStuff);
        Hero(const Hero &) = delete;
        virtual ~Hero();

        BackPack backPack;

        string getName() const;
        int getAgility() const;
        int getIntelligence() const;
        int getStrength() const;
        double getHp() const;
        IObject *getStuff() const;

        void virtual interact(const Hero &) = 0;
        void virtual show() const;

        Hero &operator=(const Hero &) = delete;
    };
}

#endif