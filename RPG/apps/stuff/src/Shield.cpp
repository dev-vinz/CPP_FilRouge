#include "..\include\Shield.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initialization
     * @param _solidity The solidity of the shield
     */
    Shield::Shield(int _solidity) : solidity(_solidity)
    {
    }

    /**
     * @brief Constructor per copy
     * @param s The shield to copy
     */
    Shield::Shield(const Shield &s) : solidity(s.solidity)
    {
    }

    /**
     * @brief Reduce the solidity
     * @param _reduction The reduction
     * @returns The rest of damage
     */
    double Shield::reduceSolidity(double _reduction)
    {
        double newSolidity = this->solidity - _reduction;
        this->solidity = max(newSolidity, 0.0);

        return min(newSolidity, 0.0);
    }

    /**
     * @brief Get the shields' solidity
     * @returns The solidity
     */
    int Shield::getFeature() const
    {
        return this->solidity;
    }

    /**
     * @brief Get the name
     * @returns The name
     */
    string Shield::getName() const
    {
        return "Shield";
    }
}