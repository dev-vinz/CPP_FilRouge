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
        this->player = nullptr;

        // We fix 4% from the map' size as opponents
        int rndOpp = trunc(0.04 * this->currentMap.getWidth() * this->currentMap.getHeight());
        this->nbOpponents = rndOpp;
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
        this->player = nullptr;
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
     * @brief Get the map
     * @returns The map
     */
    Map Game::getMap() const
    {
        return this->currentMap;
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
     * @brief Choose the player between three
     * @param _name The player's name
     */
    void Game::choosePlayer(string _name)
    {
        Hero *choiceOne = new Warrior(_name, 1, 1, 10, 100, new Sword(50), true);
        Hero *choiceTwo = new Wizard(_name, 10, 10, 10, 8, 100, new Potion(900, Agility), true);
        Hero *choiceThree = new Necromancer(_name, 9, 9, 9, 9, 90, new Potion(10, Heal), true);

        vector<Hero *> heroesAvailable = {choiceOne, choiceTwo, choiceThree};

        int choice = -1;

        while (choice < 1 || choice > 3)
        {
            cout << "Please choose your type of hero with 1, 2 or 3 :" << endl
                 << "(1) Warrior" << endl
                 << "(2) Wizard" << endl
                 << "(3) Necromancer" << endl
                 << ">>> ";

            cin >> choice;
        }

        this->player = heroesAvailable.at(choice - 1);

        cout << "Here's your Hero : " << endl;
        this->player->show();

        this->setPositions();
    }

    /**
     * @brief Display the game
     */
    void Game::display() const
    {
        this->currentMap.display(*this->player, this->listOpponents);
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