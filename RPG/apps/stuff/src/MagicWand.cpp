#include "..\include\MagicWand.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initializer
     * @param _power The power of the magic wand
     */
    MagicWand::MagicWand(int _power) : power(_power)
    {
    }

    /**
     * @brief Constructor per copy
     * @param p The magic wand to copy
     */
    MagicWand::MagicWand(const MagicWand &_mw) : power(_mw.power)
    {
    }

    /**
     * @brief Get the magic wand's power
     * @returns The power
     */
    int MagicWand::getFeature() const
    {
        return this->power;
    }

    /**
     * @brief Get the name
     * @returns The name
     */
    string MagicWand::getName() const
    {
        return "Magic Wand";
    }
}