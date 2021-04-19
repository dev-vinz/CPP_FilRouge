#include "..\include\Hero.hpp"

namespace HE_Arc::RPG
{
    /**
     * Constructor with initialization of all parameters
     * @param _strength The strength
     * @param _agility The agility
     * @param _intelligence The intelligence
     * @param _hp The HP
     * @param _name The name
     * @param _pStuff The stuff
     */
    Hero::Hero(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pStuff) : strength(_strength), agility(_agility), intelligence(_intelligence), hp(_hp), name(_name), pStuff(_pStuff)
    {
    }

    /**
     * Destructor
     */
    Hero::~Hero()
    {
        delete this->pStuff;
        this->pStuff = nullptr;
    }

    /**
     * Show the different attributes of the hero
     */
    void Hero::show() const
    {
        cout << "\n=================\n"
             << "HERO : " << this->getName()
             << "\n=================\n"
             << "\nstrength : " << this->getStrength()
             << "\nagility : " << this->getAgility()
             << "\nintelligence : " << this->getIntelligence()
             << "\nHP : " << this->getHp()
             << "\nStuff : " << this->getStuff()->getName()
             << endl;
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