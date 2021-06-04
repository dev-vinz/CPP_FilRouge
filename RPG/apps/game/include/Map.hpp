#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <map>
#include <vector>

#include "..\..\actors\include\Hero.hpp"

#include "..\..\enums\WhatMap.hpp"

#include "..\..\stuff\include\Potion.hpp"

using namespace std;

typedef array<int, 2> Coordinates;

namespace HE_Arc::RPG
{
    class Map
    {
    private:
        int width = 10;
        int height = 8;

        map<Hero *, Coordinates> heroPositions;
        map<Potion *, Coordinates> potionPositions;

    public:
        Map() = default;
        Map(int _width, int _height);
        ~Map();

        int getWidth() const;
        int getHeight() const;

        bool isCaseEmpty(int _x, int _y) const;
        bool isOpponentNear(int _x, int _y) const;

        Hero *getOpponentNear(int _x, int _y) const;
        Hero *whoIs(int _x, int _y) const;

        Potion *whichIs(int _x, int _y) const;

        void display(const Hero &, const vector<Hero *>, const vector<Potion *>) const;
        void update(vector<Potion *>);
        void update(vector<Hero *>);

        WhatMap whatIs(int _x, int _y) const;

        static const bool VJ_DEBUG_LOG = false;
    };
}

#endif