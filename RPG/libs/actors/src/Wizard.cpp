#include "..\include\Wizard.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initialization of all parameters
     * @param _name The name
     * @param _agility The agility
     * @param _intelligence The intelligence
     * @param _strength The strength
     * @param _hp The HP
     * @param _mana The mana
     * @param _pStuff The stuff
     * @param _isPlayer Is it the player
     */
    Wizard::Wizard(string _name, int _agility, int _intelligence, int _strength, double _hp, int _mana, IObject *_pStuff, bool _isPlayer) : Hero(_name, _agility, _intelligence, _strength, _hp, _pStuff, _isPlayer), mana(_mana)
    {
    }

    /**
     * @brief Get the mana
     * @returns The mana
     */
    int Wizard::getMana() const
    {
        return this->mana;
    }

    /**
     * @brief Cast a spell
     */
    void Wizard::castSpell()
    {
        cout << this->name << " cast : AVADA KEDAVRA !" << endl;
    }

    /**
     * @brief Interact a wizard with an other Hero
     * @param otherHero The other hero
     */
    void Wizard::interact(const Hero &anotherHero)
    {
        cout << this->name << " sent a spell on " << anotherHero.getName() << endl;
    }

    /**
     * @brief Show the different attributes of the wizard
     */
    void Wizard::show() const
    {
        cout << "\n=================\n"
             << "WIZARD : " << this->getName()
             << "\n=================\n"
             << "\nAgility : " << this->getAgility()
             << "\nIntelligence : " << this->getIntelligence()
             << "\nStrength : " << this->getStrength()
             << "\nMana : " << this->getMana()
             << "\nHP : " << this->getHp()
             << "\nStuff : " << this->getStuff()->getName()
             << endl;
    }
}