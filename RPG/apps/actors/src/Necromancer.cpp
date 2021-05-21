#include "..\include\Necromancer.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initialization of all parameters
     * @param _name The name
     * @param _agility The agility
     * @param _intelligence The intelligence
     * @param _strength The strength
     * @param _mana The mana
     * @param _hp The HP
     * @param _pStuff The stuff
     * @param _isPlayer Is it the player
     */
    Necromancer::Necromancer(string _name, int _agility, int _intelligence, int _strength, int _mana, double _hp, IObject *_pStuff, bool _isPlayer) : Wizard(_name, _agility, _intelligence, _strength, _mana, _hp, _pStuff, _isPlayer)
    {
        this->currentHp = _hp;
    }

    /**
     * @brief Rise undead
     */
    void Necromancer::riseUndead()
    {
        cout << this->name << " rise undead" << endl;
    }

    /**
     * @brief Display the necromancer's attacks
     */
    void Necromancer::displayAttacks() const
    {
    }

    /**
     * @brief Show the different attributes of the necromancer
     */
    void Necromancer::show() const
    {
        cout << "\n=================\n"
             << "NECROMANCER : " << this->getName()
             << "\n=================\n"
             << "\nAgility : " << this->getAgility()
             << "\nIntelligence : " << this->getIntelligence()
             << "\nStrength : " << this->getStrength()
             << "\nMana : " << this->getMana()
             << "\nHP : " << this->hp
             << "\nCurrent HP :" << this->getHp()
             << "\nStuff : " << this->getStuff()->getName()
             << endl;
    }
}