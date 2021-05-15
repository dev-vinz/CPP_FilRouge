#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

// Using API https://randommer.io/

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <stdlib.h>
#include <string>
#include <winsock2.h> // Sinon ça fout un warning bizarre (cpr)
#include <windows.h>

#include <cpr/cpr.h>

using namespace std;
using namespace nlohmann;

namespace HE_Arc::RPG
{
    class RandomGenerator
    {
    private:
        static string API_KEY;
        static const string BASE_URL;
        string projectPath;

    public:
        RandomGenerator();

        int getRandomNumber(unsigned int _max);
        int getRandomNumber(unsigned int _min, unsigned int _max);

        string getRandomName() const;
    };
}

#endif