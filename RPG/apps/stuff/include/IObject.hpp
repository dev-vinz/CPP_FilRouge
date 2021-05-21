#ifndef IOBJECT_HPP
#define IOBJECT_HPP

#include <iostream>

using namespace std;

namespace HE_Arc::RPG
{
    class IObject
    {
    protected:
        int posX;
        int posY;

    public:
        virtual ~IObject() = default;

        int virtual getFeature() const = 0;
        int getPosX() const;
        int getPosY() const;

        void setPosXY(int _x, int _y);

        string virtual getName() const = 0;
    };
}

#endif