#ifndef IOBJECT_HPP
#define IOBJECT_HPP

#include <iostream>

using namespace std;

namespace HE_Arc::RPG
{
    class IObject
    {
    public:
        // Constructors and Destructor
        ~IObject() = default;

        // Int methods
        int virtual getFeature() const = 0;

        // String methods
        string virtual getName() const = 0;
    };
}

#endif