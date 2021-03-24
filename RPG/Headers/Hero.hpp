#ifndef HERO_H
#define HERO_H

#include <string.h>

#include "Sword.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Hero
    {
    private:
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
        Hero(int _strength, int _agility, int _intelligence, double _hp, string _name);
        Hero(const Hero &);
        ~Hero();

        // Methods int
        int getagility() const { return this->agility; }

        // Methods void
        void interact(const Hero &);
        void show();

        // Override operator
        Hero &operator=(const Hero &);
    };
}

#endif