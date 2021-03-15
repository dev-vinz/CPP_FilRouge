#include "../Headers/Sword.hpp"

namespace HE_Arc::RPG
{
    /**
     * Constructor with initialization
     * @param _damage The damage made by the sword
     */
    Sword::Sword(int _damage) : damage(_damage)
    {

    }

    /**
     * Get the damage of the sword
     */
    int Sword::getDamage() const
    {
        return this->damage;
    }
}