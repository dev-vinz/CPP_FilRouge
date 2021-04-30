#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <map>

#include "..\..\actors\include\Hero.hpp"

using namespace std;

typedef array<int, 2> Coordinates;

namespace HE_Arc::RPG
{
    class Map
    {
    private:
        int width = 10;
        int height = 8;

        map<Hero *, Coordinates> positions;

    public:
        Map() = default;
        Map(int _width, int _height);
        ~Map();

        int getWidth() const;
        int getHeight() const;

        bool isCaseEmpty(int _x, int _y) const;

        void display(const Hero *) const;
        void update(Hero *);
    };
}

#endif