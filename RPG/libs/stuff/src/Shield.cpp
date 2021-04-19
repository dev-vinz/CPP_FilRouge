#include "..\include\Shield.hpp"

namespace HE_Arc::RPG
{
    /**
     * Constructor with initialization
     * @param _solidity The solidity of the shield
     */
    Shield::Shield(int _solidity) : solidity(_solidity)
    {
    }

    /**
     * Constructor per copy
     * @param s The shield to copy
     */
    Shield::Shield(const Shield &s) : solidity(s.solidity)
    {
    }

    /**
     * Get the shields' solidity
     * @returns The solidity
     */
    int Shield::getFeature() const
    {
        return this->solidity;
    }

    /**
     * Get the name
     * @returns The name
     */
    string Shield::getName() const
    {
        return "Shield";
    }
}