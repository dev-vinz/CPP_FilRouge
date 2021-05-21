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
     * @brief Gets what is on top
     * @returns The object
     */
    IObject *BackPack::top() const
    {
        return this->mStack.empty() ? nullptr : this->mStack.top();
    }

    /**
     * @brief Unpack an object
     * @returns The object
     */
    IObject *BackPack::unPack()
    {
        if (this->mStack.empty())
            return nullptr;

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

    /**
     * @brief Show the backpack - only in debug mode
     * @param _isDebug True if we're in debug mode
     */
    void BackPack::show(bool _isDebug)
    {
        if (not _isDebug)
            return;

        if (this->mStack.empty())
            return;

        IObject *top = this->mStack.top();
        this->mStack.pop();

        cout << "x " << top->getName() << endl;

        this->show(_isDebug);

        this->mStack.push(top);
    }
}