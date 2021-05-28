#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "..\..\..\settings\Settings.hpp"

using namespace std;

namespace HE_Arc::RPG
{
    class RandomGenerator
    {
    public:
        RandomGenerator() = default;

        int getRandomNumber(unsigned int _max);
        int getRandomNumber(unsigned int _min, unsigned int _max);

        double getRandomDouble(double _min, double _max, unsigned int _nbRounded);

        string getRandomName() const;
    };
}

#endif