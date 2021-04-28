#include "..\include\Hero.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initialization of all parameters
     * @param _name The name
     * @param _agility The agility
     * @param _intelligence The intelligence
     * @param _strength The strength
     * @param _hp The HP
     * @param _pStuff The stuff
     */
    Hero::Hero(string _name, int _agility, int _intelligence, int _strength, double _hp, IObject *_pStuff) : name(_name), agility(_agility), intelligence(_intelligence), strength(_strength), hp(_hp), pStuff(_pStuff)
    {
    }

    /**
     * @brief Destructor, delete the pointer on stuff
     */
    Hero::~Hero()
    {
        delete this->pStuff;
        this->pStuff = nullptr;
    }

    /**
     * @brief Get the name
     * @returns The name
     */
    string Hero::getName() const
    {
        return this->name;
    }

    /**
     * @brief Get the agility
     * @returns The agility
     */
    int Hero::getAgility() const
    {
        return this->agility;
    }

    /**
     * @brief Get the intelligence
     * @returns The intelligence
     */
    int Hero::getIntelligence() const
    {
        return this->intelligence;
    }

    /**
     * @brief Get the strength
     * @returns The strength
     */
    int Hero::getStrength() const
    {
        return this->strength;
    }

    /**
     * @brief Get the HP
     * @returns The HP
     */
    double Hero::getHp() const
    {
        return this->hp;
    }

    /**
     * @brief Get the pointer on stuff
     * @returns The pointer
     */
    IObject *Hero::getStuff() const
    {
        return this->pStuff;
    }

    /**
     * @brief Show the different attributes of the hero
     */
    void Hero::show() const
    {
        cout << "\n=================\n"
             << "HERO : " << this->getName()
             << "\n=================\n"
             << "\nAgility : " << this->getAgility()
             << "\nIntelligence : " << this->getIntelligence()
             << "\nStrength : " << this->getStrength()
             << "\nHP : " << this->getHp()
             << "\nStuff : " << this->getStuff()->getName()
             << endl;
    }

    /**
     * @brief Override of operator <<
     * @param s The stream
     * @param h The hero
     * @returns The stream
     */
    ostream &operator<<(ostream &s, const Hero &h)
    {
        return s << "\n=================\n"
                 << "HERO : " << h.getName()
                 << "\n=================\n"
                 << "\nAgility : " << h.getAgility()
                 << "\nIntelligence : " << h.getIntelligence()
                 << "\nStrength : " << h.getStrength()
                 << "\nHP : " << h.getHp()
                 << "\nStuff : " << h.getStuff()->getName();
    }
}