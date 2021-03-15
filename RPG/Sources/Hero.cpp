#include <iostream>

#include "../Headers/Hero.hpp"

namespace HE_Arc::RPG
{
    /**
     * Default constructor for the hero
     */
    Hero::Hero() :
        strength(0), agility(0), intelligence(0), hp(0), name("no_name")
    {

    }

    /**
     * Constructor with initialization of all parameters
     * @param _strength The strength
     * @param _agility The agility
     * @param _intelligence The intelligence
     * @param _hp The HP
     * @param _name The name
     */
    Hero::Hero(int _strength, int _agility, int _intelligence, double _hp, std::string _name) :
        strength(_strength), agility(_agility), intelligence(_intelligence), hp(_hp), name(_name)
    {

    }

    /**
     * Get the agility
     * @returns The agility
     */
    int Hero::getAgility() const
    {
        return this->agility;
    }

    /**
     * Make two heroes interact
     * @param otherHero The other hero
     */
    void Hero::interact(const Hero& otherHero)
    {
        std::cout << "Hello valiant " << otherHero.name << " ! I'm " << this->name << endl;
    }

    /**
     * Show the different attributes of the hero
     */
    void Hero::show()
    {
        std::cout << "\n=================\n"
                  << "HERO : " << this->name
                  << "\n=================\n"
                  << "\nStrength : " << this->strength
                  << "\nAgility : " << this->getAgility()
                  << "\nIntelligence : " << this->intelligence
                  << "\nHP : " << this->hp
                  << endl;
    }
}