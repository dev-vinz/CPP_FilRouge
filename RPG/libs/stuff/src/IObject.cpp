#include "..\include\IObject.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Get the position in X
     * @returns The X position
     */
    int IObject::getPosX() const
    {
        return this->posX;
    }

    /**
     * @brief Get the position in Y
     * @returns The Y position
     */
    int IObject::getPosY() const
    {
        return this->posY;
    }

    /**
     * @brief Set the position X and Y
     * @param _x The position
     * @param _y The position
     */
    void IObject::setPosXY(int _x, int _y)
    {
        this->posX = _x;
        this->posY = _y;
    }
}