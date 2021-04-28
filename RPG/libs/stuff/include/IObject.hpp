#ifndef IOBJECT_HPP
#define IOBJECT_HPP

#include <iostream>

using namespace std;

namespace HE_Arc::RPG
{
    class IObject
    {
    public:
        ~IObject() = default;

        int virtual getFeature() const = 0;

        string virtual getName() const = 0;
    };
}

#endif