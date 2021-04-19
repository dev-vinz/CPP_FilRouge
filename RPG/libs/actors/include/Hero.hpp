#ifndef HERO_HPP
#define HERO_HPP

#include <iostream>
#include <string.h>

#include "..\..\stuff\include\IObject.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Hero
    {
    protected:
        // Attributes
        int strength = 0;
        int agility = 0;
        int intelligence = 0;

        double hp = 0;

        string name = "no_name";

        IObject *pStuff = nullptr;

        // Friend methods
        friend ostream &operator<<(ostream &, const Hero &);

    public:
        // Constructors and Destructor
        Hero() = default;
        Hero(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pStuff);
        Hero(const Hero &) = delete;
        virtual ~Hero();

        // Getters
        int getAgility() const { return this->agility; }
        string getName() const { return this->name; }

        // Methods virtual
        void virtual interact(const Hero &) = 0;
        void virtual show() const;

        // Override operator
        Hero &operator=(const Hero &) = delete;
    };
}

#endif