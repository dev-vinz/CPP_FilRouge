#include "..\include\Game.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor per default
     * @brief All is chosen randomly
     */
    Game::Game()
    {
        this->currentMap = Map();
        this->player = new Wizard("Severus Rogue", 7, 10, 8, 150, 10, new Potion(900), true);

        // We fix 4% from the map' size as opponents
        int rndOpp = trunc(0.04 * this->currentMap.getWidth() * this->currentMap.getHeight());
        this->nbOpponents = rndOpp;

        this->setPositions();
    }

    /**
     * @brief Constructor with initialization
     * @param _width The map's width
     * @param _height The map's height
     * @param _nbOpponents The number of opponents
     */
    Game::Game(int _width, int _height, int _nbOpponents) : nbOpponents(_nbOpponents)
    {
        this->currentMap = Map(_width, _height);
        this->player = new Wizard("Ron", 7, 10, 8, 150, 10, new Potion(900));

        this->setPositions();
    }

    /**
     * @brief Destructor, delete the pointer on current Hero
     */
    Game::~Game()
    {
        if (this->player != nullptr)
        {
            delete this->player;
            this->player = nullptr;
        }
    }

    /**
     * @brief Get the current Hero
     * @returns The Hero
     */
    Hero *Game::getPlayer() const
    {
        return this->player;
    }

    /**
     * @brief Get the map
     * @returns The map
     */
    Map Game::getMap() const
    {
        return this->currentMap;
    }

    /**
     * @brief Display the game
     */
    void Game::display() const
    {
        this->currentMap.display(this->player);
    }

    // =============================================
    // Private Methods
    // =============================================

    /**
     * @brief Set the positions
     */
    void Game::setPositions()
    {
        srand(time(nullptr));
        int rndX = rand() % this->currentMap.getWidth();
        int rndY = rand() % this->currentMap.getHeight();

        this->player->setPosXY(rndX, rndY);

        this->currentMap.update(this->player);
    }
}