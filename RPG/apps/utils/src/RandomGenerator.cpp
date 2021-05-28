#include "..\include\RandomGenerator.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Get a random number between 0 and _max not included
     * @param _max The maximum number
     */
    int RandomGenerator::getRandomNumber(unsigned int _max)
    {
        return this->getRandomNumber(0, _max);
    }

    /**
     * @brief Get a random number between _min and _max not included
     * @param _min The minimum number
     * @param _max The maximum number
     */
    int RandomGenerator::getRandomNumber(unsigned int _min, unsigned int _max)
    {
        if (_min > _max)
        {
            unsigned int temp = _min;
            _min = _max;
            _max = temp;
        }

        if (_min == _max)
            return _max;

        return rand() % (_max - _min) + _min;
    }

    /**
     * @brief Get a random float number between _min and _max not included
     * @param _min The minimum number
     * @param _max The maximum number
     * @param _nbRounded The number after the comma
     */
    double RandomGenerator::getRandomDouble(double _min, double _max, unsigned int _nbRounded)
    {
        int bigInt = this->getRandomNumber(_min * pow(10, _nbRounded), _max * pow(10, _nbRounded));
        return bigInt / ((double)pow(10, _nbRounded));
    }

    /**
     * @brief Get a random name made by the generator
     * @returns The random name
     */
    string RandomGenerator::getRandomName() const
    {
        vector<string> tabNames;

        for (auto &elem : ARRAY_RANDOM_NAMES)
            tabNames.push_back(elem);

        int index = rand() % tabNames.size();

        return tabNames.at(index);
    }
}