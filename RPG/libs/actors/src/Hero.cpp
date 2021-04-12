#include "..\include\Hero.hpp"

namespace HE_Arc::RPG
{
    /**
     * Default constructor
     */
    Hero::Hero() : strength(0), agility(0), intelligence(0), hp(0), name("no_name"), sword(new Sword())
    {
    }

    /**
     * Constructor with initialization of all parameters
     * @param _strength The strength
     * @param _agility The agility
     * @param _intelligence The intelligence
     * @param _hp The HP
     * @param _name The name
     * @param _sword The sword
     */
    Hero::Hero(int _strength, int _agility, int _intelligence, double _hp, string _name, Sword *_sword) : strength(_strength), agility(_agility), intelligence(_intelligence), hp(_hp), name(_name), sword(_sword)
    {
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
     * Show the different attributes of the hero
     */
    void Hero::show() const
    {
        cout << "\n=================\n"
             << "HERO : " << this->name
             << "\n=================\n"
             << "\nstrength : " << this->strength
             << "\nagility : " << this->getAgility()
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
                 << "\nagility : " << h.getAgility()
                 << "\nintelligence : " << h.intelligence
                 << "\nHP : " << h.hp;
    }
}