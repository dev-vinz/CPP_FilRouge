#include "../Headers/Sword.hpp"

namespace HE_Arc::RPG
{
    /**
     * Default constructor
     */
    Sword::Sword() : damage(0)
    {
    }

    /**
     * Constructor with initialization
     * @param _damage The damage made by the sword
     */
    Sword::Sword(int _damage) : damage(_damage)
    {
    }

    /**
     * Constructor per copy
     * @param s The sword to copy
     */
    Sword::Sword(const Sword &s) : damage(s.damage)
    {
    }
}