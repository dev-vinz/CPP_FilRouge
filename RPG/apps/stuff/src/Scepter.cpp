#include "..\include\Scepter.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initializer
     * @param _power The power of the scepter
     */
    Scepter::Scepter(int _power) : power(_power)
    {
    }

    /**
     * @brief Constructor per copy
     * @param p The scepter to copy
     */
    Scepter::Scepter(const Scepter &_s) : power(_s.power)
    {
    }

    /**
     * @brief Get the scepter's power
     * @returns The power
     */
    int Scepter::getFeature() const
    {
        return this->power;
    }

    /**
     * @brief Get the name
     * @returns The name
     */
    string Scepter::getName() const
    {
        return "Scepter";
    }
}