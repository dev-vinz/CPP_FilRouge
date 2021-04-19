#include "..\include\BackPack.hpp"

namespace HE_Arc::RPG
{
    /**
     * Check if the backpack is filled
     * @returns True if it is
     */
    bool BackPack::isNotEmpty() const
    {
        return not this->mStack.empty();
    }

    /**
     * Pack an object in the backpack
     * @param _pObject The object
     */
    void BackPack::pack(IObject *_pObject)
    {
        this->mStack.push(_pObject);
    }

    /**
     * Unpack an object
     * @returns The object
     */
    IObject *BackPack::unPack()
    {
        IObject* topStack = this->mStack.top();
        this->mStack.pop();

        return topStack;
    }
}