#include "..\include\Opponent.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initialization of all parameters
     * @param _name The name
     * @param _agility The agility
     * @param _intelligence The intelligence
     * @param _strength The strength
     * @param _hp The HP
     */
    Opponent::Opponent(string _name, int _agility, int _intelligence, int _strength, double _hp) : Hero(_name, _agility, _intelligence, _strength, _hp, nullptr, false)
    {
        this->pStuff = new Shield(0);
    }
}