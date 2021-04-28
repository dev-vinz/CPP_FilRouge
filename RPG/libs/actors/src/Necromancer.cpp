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
     */
    Necromancer::Necromancer(string _name, int _agility, int _intelligence, int _strength, int _mana, double _hp, IObject *_pStuff) : Wizard(_name, _agility, _intelligence, _strength, _mana, _hp, _pStuff)
    {
    }

    /**
     * @brief Rise undead
     */
    void Necromancer::riseUndead()
    {
        cout << this->name << " rise undead" << endl;
    }
}