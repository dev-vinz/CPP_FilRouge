#include "..\include\Necromancer.hpp"

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
    Necromancer::Necromancer(int _strength, int _agility, int _intelligence, double _hp, int _mana, string _name, IObject *_pStuff) : Wizard(_strength, _agility, _intelligence, _hp, _mana, _name, _pStuff)
    {
    }

    /**
     * Rise undead
     */
    void Necromancer::riseUndead()
    {
        cout << this->name << " rise undead" << endl;
    }
}