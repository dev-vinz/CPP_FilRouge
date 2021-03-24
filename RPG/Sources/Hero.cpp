#include <iostream>

#include "../Headers/Hero.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    /**
     * Default constructor
     */
    Hero::Hero() : strength(0), agility(0), intelligence(0), hp(0), name("no_name")
    {
        this->sword = new Sword;
        this->sword = nullptr;
    }

    /**
     * Constructor with initialization of all parameters
     * @param _strength The strength
     * @param _agility The agility
     * @param _intelligence The intelligence
     * @param _hp The HP
     * @param _name The name
     */
    Hero::Hero(int _strength, int _agility, int _intelligence, double _hp, std::string _name) : strength(_strength), agility(_agility), intelligence(_intelligence), hp(_hp), name(_name)
    {
        this->sword = new Sword;
        this->sword = nullptr;
    }

    /**
     * Constructor per copy
     * @param h The hero to copy
     */
    Hero::Hero(const Hero &h) : strength(h.strength), agility(h.agility), intelligence(h.intelligence), hp(h.hp), name(h.name)
    {
        this->sword = new Sword(*h.sword);
    }

    /**
     * Destructor
     */
    Hero::~Hero()
    {
        delete this->sword;
        this->sword = nullptr;
    }

    /**
     * Make two heroes interact each other
     * @param otherHero The other hero
     */
    void Hero::interact(const Hero &otherHero)
    {
        std::cout << "Hello valiant " << otherHero.name << " ! I'm " << this->name << endl;
    }

    /**
     * Show the different attributes of the hero
     */
    void Hero::show()
    {
        cout << "\n=================\n"
             << "HERO : " << this->name
             << "\n=================\n"
             << "\nstrength : " << this->strength
             << "\nagility : " << this->getagility()
             << "\nintelligence : " << this->intelligence
             << "\nHP : " << this->hp
             << endl;
    }

    /**
     * Override of operator =
     * @param h The hero
     * @returns The hero copied
     */
    Hero &Hero::operator=(const Hero &h)
    {
        this->strength = h.strength;
        this->agility = h.agility;
        this->intelligence = h.intelligence;
        this->hp = h.hp;
        this->name = h.name;
        this->sword = new Sword(*h.sword);

        return *this;
    }

    /**
     * Override of operator <<
     * @param s The stream
     * @param h The hero
     * @returns The stream
     */
    ostream &operator<<(ostream &s, const Hero &h)
    {
        return s << "\n=================\n"
                 << "HERO : " << h.name
                 << "\n=================\n"
                 << "\nstrength : " << h.strength
                 << "\nagility : " << h.getagility()
                 << "\nintelligence : " << h.intelligence
                 << "\nHP : " << h.hp;
    }
}