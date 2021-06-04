#ifndef HERO_HPP
#define HERO_HPP

#include <iomanip>
#include <iostream>

#include "..\..\stuff\include\BackPack.hpp"
#include "..\..\stuff\include\IObject.hpp"
#include "..\..\stuff\include\Potion.hpp"
#include "..\..\stuff\include\Shield.hpp"

#include "..\..\utils\include\Color.hpp"
#include "..\..\utils\include\Logger.hpp"
#include "..\..\utils\include\RandomGenerator.hpp"

#include "..\..\..\settings\Settings.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class Hero
    {
    protected:
        string name = "no_name";

        int agility = 0;        // Purple
        int intelligence = 0;
        int strength = 0;       // Yellow

        double hp = 0;
        double currentHp = 0;   // Red

        IObject *pStuff = nullptr;

        bool isPlayer;
        bool dodgeNext = false;

        int posX;
        int posY;

        friend ostream &operator<<(ostream &, const Hero &);

    public:
        Hero() = delete;
        Hero(string _name, int _agility, int _intelligence, int _strength, double _hp, IObject *_pStuff, bool _isPlayer);
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

        double getAgilityRatio() const;
        double getIntelligenceRatio() const;
        double getStrengthRatio() const;

        void setAgility(int);
        void setHp(double);
        void setPosXY(int, int);
        void switchDodge();

        void updateAgility(int);
        void updateHp(double);
        void updateStrength(int);

        bool isDodging();
        bool isDead() const;

        void virtual useObject(IObject *) = 0;

        void virtual displayAttacks() const = 0;
        void virtual interact(Hero *, char _attack) = 0;
        void virtual show() const = 0;
        void virtual showStatistics() const;

        Hero &operator=(const Hero &) = delete;

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif