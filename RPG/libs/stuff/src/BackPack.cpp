#include "..\include\BackPack.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Check if the backpack is filled
     * @returns True if it is
     */
    bool BackPack::isNotEmpty() const
    {
        return not this->mStack.empty();
    }

    /**
     * @brief Get the size of the backpack
     * @returns The size
     */
    int BackPack::getSize() const
    {
        return this->mStack.size();
    }

    /**
     * @brief Unpack an object
     * @returns The object
     */
    IObject *BackPack::unPack()
    {
        IObject *topStack = this->mStack.top();
        this->mStack.pop();

        return topStack;
    }

    /**
     * @brief Pack an object in the backpack
     * @param _pObject The object
     */
    void BackPack::pack(IObject *_pObject)
    {
        this->mStack.push(_pObject);
    }
}