#include "..\include\Warrior.hpp"

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
     * @param _isPlayer Is it the player
     */
    Warrior::Warrior(string _name, int _agility, int _intelligence, int _strength, double _hp, IObject *_pStuff, bool _isPlayer) : Hero(_name, _agility, _intelligence, _strength, _hp, _pStuff, _isPlayer)
    {
        this->currentHp = _hp;
    }

    /**
     * @brief Interact a warrior with an other Hero
     * @param otherHero The other hero
     */
    void Warrior::interact(const Hero &otherHero)
    {
        cout << this->name << " punch " << otherHero.getName() << "'s face" << endl;
    }

    /**
     * @brief Show the different attributes of the warrior
     */
    void Warrior::show() const
    {
        cout << "\n=================\n"
             << "WARRIOR : " << this->getName()
             << "\n=================\n"
             << "\nAgility : " << this->getAgility()
             << "\nIntelligence : " << this->getIntelligence()
             << "\nStrength : " << this->getStrength()
             << "\nHP : " << this->hp
             << "\nCurrent HP :" << this->getHp()
             << "\nStuff : " << this->getStuff()->getName()
             << endl;
    }
}