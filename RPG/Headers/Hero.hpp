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
            int strength;
            int agility;
            int intelligence;
            double hp;
            string name;
            Sword sword;

        public:
            Hero();
            Hero(int _strength, int _agility, int _intelligence, double _hp, string _name);

            int getAgility() const;

            void interact(const Hero&);
            void show();
    };
}

#endif