#include "..\include\Potion.hpp"

namespace HE_Arc::RPG
{
    /**
     * Constructor with initializer
     * @param _power The power of the potion
     */
    Potion::Potion(int _power) : power(_power)
    {
    }

    /**
     * Constructor per copy
     * @param p The potion to copy
     */
    Potion::Potion(const Potion &p) : power(p.power)
    {
    }

    /**
     * Get the potion's power
     * @returns The power
     */
    int Potion::getFeature() const
    {
        return this->power;
    }

    /**
     * Get the name
     * @returns The name
     */
    string Potion::getName() const
    {
        return "Potion";
    }
}