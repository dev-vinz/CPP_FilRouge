#ifndef HERO_HPP
#define HERO_HPP

#include <iomanip>
#include <iostream>
#include <string.h>

#include "..\..\stuff\include\BackPack.hpp"
#include "..\..\stuff\include\IObject.hpp"
#include "..\..\stuff\include\Potion.hpp"

#include "..\..\utils\include\RandomGenerator.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Hero
    {
    protected:
        string name = "no_name";

        int agility = 0;
        int intelligence = 0;
        int strength = 0;

        double hp = 0;
        double currentHp = 0;

        IObject *pStuff = nullptr;

        bool isPlayer;

        int posX;
        int posY;

        friend ostream &operator<<(ostream &, const Hero &);

    public:
        Hero() = delete;
        Hero(string _name, int _agility, int _intelligence, int _strength, double _hp, IObject *_pStuff, bool _isPlayer = false);
        Hero(const Hero &) = delete;
        virtual ~Hero();

        BackPack backPack;

        string getName() const;
        int getAgility() const;
        int getIntelligence() const;
        int getStrength() const;
        double getHp() const;
        IObject *getStuff() const;
        bool getIsPlayer() const;

        int getPosX() const;
        int getPosY() const;

        void setAgility(int);
        void setHp(double);
        void setPosXY(int, int);

        void useObject(IObject *);

        void virtual displayAttacks() const = 0;
        void virtual interact(Hero *, char _attack) = 0;
        void virtual show() const = 0;
        void virtual showStatistics() const;

        Hero &operator=(const Hero &) = delete;
    };
}

#endif