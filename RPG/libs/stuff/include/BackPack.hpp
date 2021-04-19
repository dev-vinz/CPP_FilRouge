#ifndef BACKPACK_HPP
#define BACKPACK_HPP

#include <iostream>
#include <stack>

#include "IObject.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class BackPack
    {
    private:
        // Attributes
        stack<IObject *> mStack;

    public:
        // Constructors and Destructor
        BackPack() = default;
        ~BackPack() = default;

        // Bool methods
        bool isNotEmpty() const;

        // Void methods
        void pack(IObject *);

        // IObject methods
        IObject *unPack();
    };
}

#endif