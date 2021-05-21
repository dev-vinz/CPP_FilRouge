#include "..\include\Potion.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initializer
     * @param _power The power of the potion
     */
    Potion::Potion(int _power, Type _utility) : power(_power), utility(_utility)
    {
    }

    /**
     * @brief Constructor per copy
     * @param p The potion to copy
     */
    Potion::Potion(const Potion &p) : power(p.power)
    {
    }

    /**
     * @brief Get the potion's power
     * @returns The power
     */
    int Potion::getFeature() const
    {
        return this->power;
    }

    /**
     * @brief Get the potion's utility
     * @returns The utility
     */
    Type Potion::getUtility() const
    {
        return this->utility;
    }

    /**
     * @brief Get the name
     * @returns The name
     */
    string Potion::getName() const
    {
        return "Potion of " + this->enumToStr[this->utility];
    }
}