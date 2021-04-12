#ifndef HERO_HPP
#define HERO_HPP

#include <iostream>
#include <string.h>

#include "..\..\weapons\include\Sword.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Hero
    {
    protected:
        // Attributes
        int strength;
        int agility;
        int intelligence;

        double hp;

        string name;

        Sword *sword;

        // Friend methods
        friend ostream &operator<<(ostream &, const Hero &);

    public:
        // Constructors and Destructor
        Hero();
        Hero(int _strength, int _agility, int _intelligence, double _hp, string _name, Sword *_sword);
        Hero(const Hero &);
        ~Hero();

        // Getters
        int getAgility() const { return this->agility; }
        string getName() const { return this->name; }

        // Methods virtual
        void virtual interact(const Hero &) = 0;
        void virtual show() const;

        // Override operator
        Hero &operator=(const Hero &);
    };
}

#endif