#include "..\include\Map.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initialization
     * @param _width The map's width
     * @param _height The map's height
     */
    Map::Map(int _width, int _height) : width(_width), height(_height)
    {
    }

    /**
     * @brief Destructor, clear the map of positions
     */
    Map::~Map()
    {
        if (this->heroPositions.size() > 0)
            this->heroPositions.clear();

        if (this->potionPositions.size() > 0)
            this->potionPositions.clear();
    }

    /**
     * @brief Get the map's width
     * @returns The width
     */
    int Map::getWidth() const
    {
        return this->width;
    }

    /**
     * @brief Get the map's height
     * @returns The height
     */
    int Map::getHeight() const
    {
        return this->height;
    }

    /**
     * @brief Check if the case is empty
     * @param _x The position X
     * @param _y The position Y
     * @returns True if it is
     */
    bool Map::isCaseEmpty(int _x, int _y) const
    {
        bool isEmpty = true;

        for (auto &item : this->heroPositions)
        {
            if (item.second[0] == _x && item.second[1] == _y)
                isEmpty = false;
        }

        for (auto &item : this->potionPositions)
        {
            if (item.second[0] == _x && item.second[1] == _y)
                isEmpty = false;
        }

        return isEmpty;
    }

    /**
     * @brief Tell which hero is in this case
     * @param _x The position X
     * @param _y The position Y
     * @returns The hero, or nullptr
     */
    Hero *Map::whoIs(int _x, int _y) const
    {
        Hero *hero = nullptr;

        for (auto &item : this->heroPositions)
        {
            if (item.second[0] == _x && item.second[1] == _y)
                hero = item.first;
        }

        return hero;
    }

    /**
     * @brief Display the map with all positions
     * @param player The hero
     * @param opponents The opponents
     */
    void Map::display(const Hero &player, const vector<Hero *> opponents, const vector<Potion *> potions) const
    {
        cout << endl;

        int _middle = this->height / 2;

        for (int h = 0; h < this->height; h++)
        {

            cout << " ";

            for (int w = 0; w < this->width; w++)
            {
                cout << "+---";
            }

            cout << "+" << endl;

            cout << " ";

            for (int w = 0; w < this->width; w++)
            {
                if (player.getPosX() == w && player.getPosY() == h)
                {
                    cout << "| X ";
                }
                else
                {
                    bool isOpp = false;
                    bool isPotion = false;
                    for (auto &opp : opponents)
                    {
                        if (opp->getPosX() == w && opp->getPosY() == h)
                        {
                            isOpp = true;
                            cout << "| O ";
                        }
                    }

                    for (auto &potion : potions)
                    {
                        if (potion->getPosX() == w && potion->getPosY() == h)
                        {
                            isPotion = true;
                            switch (potion->getUtility())
                            {
                            case Agility:
                                cout << "| A ";
                                break;
                            case Heal:
                                cout << "| H ";
                                break;
                            case Strength:
                                cout << "| S ";
                                break;
                            default:
                                cout << "| ? ";
                                break;
                            }
                        }
                    }

                    if (!isOpp & !isPotion)
                        cout << "|   ";
                }
            }

            cout << "|";

            if (h == _middle - 2)
                cout << "\tX : Player";
            if (h == _middle - 1)
                cout << "\tO : Opponent";
            if (h == _middle)
                cout << "\tA : Potion of Agility";
            if (h == _middle + 1)
                cout << "\tH : Potion of Heal";
            if (h == _middle + 2)
                cout << "\tS : Potion of Strength";

            cout << endl;
        }

        cout << " ";

        for (int w = 0; w < this->width; w++)
        {
            cout << "+---";
        }

        cout << "+" << endl
             << endl;
    }

    /**
     * @brief Update the dictionary of positions of potions
     * @param _potions The potions
     */
    void Map::update(vector<Potion *> _potions)
    {
        this->potionPositions.clear();

        for (Potion *potion : _potions)
        {
            Coordinates pCoordinates = {potion->getPosX(), potion->getPosY()};
            this->potionPositions.insert(make_pair(potion, pCoordinates));
        }

        if (Map::VJ_DEBUG_LOG)
        {
            cout << endl
                 << "=============" << endl
                 << "Map::update(Potion)" << endl;

            for (auto &item : this->potionPositions)
            {
                cout << item.first->getName() << " : " << item.second[0] << " ; " << item.second[1] << endl;
            }

            cout << "=============" << endl;
        }
    }

    /**
     * @brief Update the dictionary of positions of heroes
     * @param _heroes The Heroes
     */
    void Map::update(vector<Hero *> _heroes)
    {
        this->heroPositions.clear();

        for (Hero *hero : _heroes)
        {
            Coordinates hCoordinates = {hero->getPosX(), hero->getPosY()};
            this->heroPositions.insert(make_pair(hero, hCoordinates));
        }

        if (Map::VJ_DEBUG_LOG)
        {
            cout << endl
                 << "=============" << endl
                 << "Map::update(Hero)" << endl;

            for (auto &item : this->heroPositions)
            {
                cout << item.first->getName() << " : " << item.second[0] << " ; " << item.second[1] << endl;
            }

            cout << "=============" << endl;
        }
    }

    /**
     * @brief Check what is in the case specified
     * @param _x The position X
     * @param _y The position Y
     * @returns A Hero, a potion or nothing
     */
    What Map::whatIs(int _x, int _y) const
    {
        What _what = _None;

        // Search for Hero
        for (auto &item : this->heroPositions)
        {
            if (item.second[0] == _x && item.second[1] == _y)
                _what = _Hero;
        }

        // Search for Potion
        for (auto &item : this->potionPositions)
        {
            if (item.second[0] == _x && item.second[0] == _y)
                _what = _Potion;
        }

        return _what;
    }
}