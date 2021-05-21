#include "..\include\Sword.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initialization
     * @param _damage The damage made by the sword
     */
    Sword::Sword(int _damage) : damage(_damage)
    {
    }

    /**
     * @brief Constructor per copy
     * @param s The sword to copy
     */
    Sword::Sword(const Sword &s) : damage(s.damage)
    {
    }

    /**
     * @brief Get the sword's damage
     * @returns The damage
     */
    int Sword::getFeature() const
    {
        return this->damage;
    }

    /**
     * @brief Get the name
     * @returns The name
     */
    string Sword::getName() const
    {
        return "Sword";
    }
}