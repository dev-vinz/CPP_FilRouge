#include "..\include\Wizard.hpp"

namespace HE_Arc::RPG
{
    /**
     * Constructor with initialization of all parameters
     * @param _strength The strength
     * @param _agility The agility
     * @param _intelligence The intelligence
     * @param _hp The HP
     * @param _name The name
     * @param _mana The mana
     */
    Wizard::Wizard(int _strength, int _agility, int _intelligence, double _hp, string _name, int _mana) : Hero(_strength, _agility, _intelligence, _hp, _name, new Sword()), mana(_mana)
    {
    }

    /**
     * Cast a spell
     */
    void Wizard::castSpell()
    {
        cout << this->name << " cast : AVADA KEDAVRA !" << endl;
    }

    /**
     * Interact a wizard with an other Hero
     * @param otherHero The other hero
     */
    void Wizard::interact(const Hero &anotherHero)
    {
        cout << this->name << " sent a spell on " << anotherHero.getName() << endl;
    }

    /**
     * Show the different attributes of the wizard
     */
    void Wizard::show() const
    {
        cout << "\n=================\n"
             << "WIZARD : " << this->name
             << "\n=================\n"
             << "\nstrength : " << this->strength
             << "\nagility : " << this->getAgility()
             << "\nintelligence : " << this->intelligence
             << "\nHP : " << this->hp
             << "\nmana : " << this->mana
             << endl;
    }
}