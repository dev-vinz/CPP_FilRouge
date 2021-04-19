#include "..\include\Warrior.hpp"

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
    Warrior::Warrior(int _strength, int _agility, int _intelligence, double _hp, string _name, IObject *_pStuff) : Hero(_strength, _agility, _intelligence, _hp, _name, _pStuff)
    {
    }

    /**
     * Interact a warrior with an other Hero
     * @param otherHero The other hero
     */
    void Warrior::interact(const Hero & otherHero)
    {
        cout << this->name << " punch " << otherHero.getName() << "'s face" << endl;
    }
}