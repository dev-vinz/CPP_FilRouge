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
        stack<IObject *> mStack;

    public:
        BackPack() = default;
        ~BackPack() = default;

        bool isNotEmpty() const;

        int getSize() const;

        IObject *unPack();

        void pack(IObject *);
        void show(bool);
    };
}

#endif