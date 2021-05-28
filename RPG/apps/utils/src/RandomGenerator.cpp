#include "..\include\RandomGenerator.hpp"

namespace HE_Arc::RPG
{
    string RandomGenerator::API_KEY;
    const string RandomGenerator::BASE_URL = "https://randommer.io/api";

    /**
     * @brief Constructor, initialize the API key
     */
    RandomGenerator::RandomGenerator()
    {
        // Get the .exe path
        char buffer[MAX_PATH] = "";
        GetModuleFileNameA(NULL, buffer, MAX_PATH);

        string exePath(buffer);
        size_t iBin = exePath.find_last_of("/\\");

        // Get back of one folder - bin folder
        string binPath = exePath.substr(0, iBin);
        size_t iProject = binPath.find_last_of("/\\");

        // Get back of one folder - RPF folder
        string projectPath = binPath.substr(0, iProject);

        this->projectPath = projectPath;

        // Read and save the key in RandomGenerator::API_KEY
        ifstream myKeys(projectPath + "\\settings\\Keys.json");
        json jsonKey;

        myKeys >> jsonKey;
        myKeys.close();

        string key = jsonKey["GeneratorApiKey"];

        RandomGenerator::API_KEY = key;

        // Randomized
        srand(time(nullptr));
    }

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
        const string nameUrl = RandomGenerator::BASE_URL + "/Name?nameType=firstname&quantity=1";

        ifstream myKeys(this->projectPath + "\\settings\\Data.json");
        json jsonKey;

        myKeys >> jsonKey;
        myKeys.close();

        vector<string> tabNames;

        for (auto &elem : jsonKey["RandomNames"])
            tabNames.push_back(elem);

        int index = rand() % tabNames.size();

        return tabNames.at(index);
    }
}