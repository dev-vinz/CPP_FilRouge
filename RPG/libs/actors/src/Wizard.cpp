#include "..\include\Wizard.hpp"

namespace HE_Arc::RPG
{
    /**
     * Constructor with initialization of all parameters
     * @param _strength The strength
     * @param _agility The agility
     * @param _intelligence The intelligence
     * @param _hp The HP
     * @param _mana The mana
     * @param _name The name
     * @param _pStuff The stuff
     */
    Wizard::Wizard(int _strength, int _agility, int _intelligence, double _hp, int _mana, string _name, IObject *_pStuff) : Hero(_strength, _agility, _intelligence, _hp, _name, _pStuff), mana(_mana)
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
             << "\nStuff : " << this->pStuff->getName()
             << endl;
    }
}