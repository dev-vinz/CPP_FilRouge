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
        if (this->positions.size() > 0)
            this->positions.clear();
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

        for (auto item : this->positions)
        {
            if (item.second[0] == _x && item.second[1] == _y)
                isEmpty = false;
        }

        return isEmpty;
    }

    /**
     * @brief Display the map with all positions
     * @param player The hero
     */
    void Map::display(const Hero *player) const
    {
        cout << endl;

        for (int h = 0; h < this->height; h++)
        {

            for (int w = 0; w < this->width; w++)
            {
                cout << "+---";
            }

            cout << "+" << endl;

            for (int w = 0; w < this->width; w++)
            {
                if (player->getPosX() == w && player->getPosY() == h)
                {
                    cout << "| X ";
                }
                else
                {
                    cout << "|   ";
                }
            }

            cout << "|" << endl;
        }

        for (int w = 0; w < this->width; w++)
        {
            cout << "+---";
        }

        cout << "+" << endl
             << endl;
    }

    /**
     * @brief Update the dictionary of positions
     * @param player The Hero
     */
    void Map::update(Hero *player)
    {
        this->positions.clear();

        Coordinates pCoordinates = {player->getPosX(), player->getPosY()};
        this->positions.insert(make_pair(player, pCoordinates));

        cout << "Map::update()" << endl;
        for (auto &item : this->positions)
        {
            cout << item.first->getName() << " : " << item.second[0] << " ; " << item.second[1] << endl;
        }
    }
}