#include "..\include\Game.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor per default
     * @brief All is chosen randomly
     */
    Game::Game()
    {
        system("CLS");

        this->currentMap = Map();
        this->player = nullptr;

        // We fix 4% from the map' size as opponents
        int rndOpp = trunc(0.04 * this->currentMap.getWidth() * this->currentMap.getHeight());
        this->nbOpponents = rndOpp;
        this->nbPotions = rndOpp + 1;
    }

    /**
     * @brief Constructor with initialization
     * @param _width The map's width
     * @param _height The map's height
     * @param _nbOpponents The number of opponents
     */
    Game::Game(int _width, int _height, int _nbOpponents) : nbOpponents(_nbOpponents), nbPotions(_nbOpponents + 1)
    {
        system("CLS");

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
     * @brief Get the list of opponents
     * @returns The opponents
     */
    vector<Hero *> Game::getOpponents() const
    {
        return this->listOpponents;
    }

    /**
     * @brief Choose the player between three
     * @param _name The player's name
     */
    void Game::choosePlayer(string _name)
    {
        int choice = -1;

        while (choice < 1 || choice > 3)
        {
            cin.clear();
            cout << " Please choose your type of hero with 1, 2 or 3 :" << endl
                 << " (1) Warrior" << endl
                 << " (2) Wizard" << endl
                 << " (3) Necromancer" << endl
                 << " >>> ";

            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice)
        {
        case 1:
            this->player = new Warrior(_name, 1, 1, 10, 100, new Sword(50), true);
            break;
        case 2:
            this->player = new Wizard(_name, 10, 10, 10, 8, 100, new Potion(900, Agility), true);
            break;
        case 3:
            this->player = new Necromancer(_name, 9, 9, 9, 9, 90, new Potion(10, Heal), true);
            break;
        default:
            cout << "[ERROR] Houston we have a problem, choice can be only 1 2 or 3 (choice = " << choice << ")" << endl;
            exit(-1);
        }

        if (not Game::VJ_DEBUG_LOG)
            system("CLS");

        cout << " Here's your Hero : " << endl;
        this->player->show();

        cout << endl;

        if (not Game::VJ_DEBUG_LOG)
        {
            char waiting[] = {'/', '-', '\\', '|'};

            for (int t = 25; t > 0; t--)
            {
                usleep(200000);
                cout << "\r  " << waiting[t % 4] << " Loading ...\r";
            }

            system("CLS");
        }
    }

    /**
     * @brief Initialize the game, the opponents, the potions
     */
    void Game::initialize()
    {
        RandomGenerator random;

        for (int k = 0; k < this->nbOpponents; k++)
        {
            this->listOpponents.push_back(new Warrior(random.getRandomName(), k, k, k, k, new Shield(0)));
        }

        int start = random.getRandomNumber(3);
        for (int k = 0; k < this->nbPotions; k++)
        {
            Type _type = (Type)((start + k) % 3);
            this->listPotions.push_back(new Potion(10, _type));
        }

        this->setPositions();
    }

    /**
     * @brief Play the game
     */
    void Game::play()
    {
        this->isPlaying = true;

        while (this->isPlaying)
        {
            this->display();

            if (this->currentMap.isOpponentNear(this->player->getPosX(), this->player->getPosY()))
            {
                Hero *opponent = this->currentMap.getOpponentNear(this->player->getPosX(), this->player->getPosY());

                cout << " There's an opponent nearly !" << endl
                     << " Do you want to fight " << opponent->getName() << " ?" << endl;

                char fight;
                do
                {
                    cout << " [Y] Yes, sure !" << endl
                         << " [N] No thank's" << endl
                         << " >>> ";

                    cin >> fight;
                    string _endLine;
                    getline(cin, _endLine);

                    fight = tolower(fight, locale());
                } while (!this->checkFight(fight));

                this->display();
            }

            char movement;
            do
            {
                cout << " Choose your movement (w, a, s, d, n, q) : ";
                cin >> movement;
                string _endLine;
                getline(cin, _endLine);

                movement = tolower(movement, locale());
            } while (not this->checkMovement(movement, this->player));

            this->applyMovements(movement);

            cout << endl
                 << "===========================================================================================" << endl;
        }
    }

    // =============================================
    // Private Methods
    // =============================================

    /**
     * @brief Checks the next player's action
     * @param _action The action
     * @returns True if the check is correct
     */
    bool Game::checkAction(char _action)
    {
        return true;
    }

    /**
     * @brief Checks if the player wants to fight or not
     * @param _fight Yes or no
     * @returns True if the check is correct
     */
    bool Game::checkFight(char _fight)
    {
        char tabFight[] = {'y', 'n'};
        char *exceptedLastIndex = find(begin(tabFight), end(tabFight), _fight);

        // If the element is not found, std::find returns the end of the range (last indice of tabFight)
        if (exceptedLastIndex == end(tabFight))
            return false;

        return true;
    }

    /**
     * @brief Checks the next hero's movement
     * @param _movement The movement
     * @param _hero The hero
     * @returns True if the check is correct
     */
    bool Game::checkMovement(char _movement, Hero *_hero)
    {
        char tabMovements[] = {'w', 'a', 's', 'd', 'n', 'q'};

        char *exceptedLastIndex = find(begin(tabMovements), end(tabMovements), _movement);

        // If the element is not found, std::find returns the end of the range (last indice of tabMovements)
        if (exceptedLastIndex == end(tabMovements))
            return false;

        int posX = _hero->getPosX();
        int posY = _hero->getPosY();

        switch (_movement)
        {
        case 'w':
            posY--;
            break;
        case 'a':
            posX--;
            break;
        case 's':
            posY++;
            break;
        case 'd':
            posX++;
            break;
        case 'n':
        case 'q':
            return true;
        default:
            cout << "[ERROR : CheckMovement] Houston we have a problem, there's another movement detected (_movement = " << _movement << ")" << endl;
            exit(-1);
        }

        if (not this->currentMap.isCaseEmpty(posX, posY) && this->currentMap.whatIs(posX, posY) == _Hero)
        {
            if (_hero->getIsPlayer())
            {
                cout << " The case (" << posX << "; " << posY << ") is busy by " << this->currentMap.whoIs(posX, posY)->getName() << endl;
            }

            return false;
        }

        if (posY == this->currentMap.getHeight() || posY < 0 || posX == this->currentMap.getWidth() || posX < 0)
        {
            if (_hero->getIsPlayer())
            {
                cout << " You're not in the map anymore with this movement" << endl;
            }

            return false;
        }

        if (this->currentMap.whatIs(posX, posY) == _Potion && not _hero->getIsPlayer())
        {
            return false;
        }

        return true;
    }

    /**
     * @brief Apply the player and opponents movements
     * @param _movement The player's movement
     */
    void Game::applyMovements(char _movement)
    {
        vector<Hero *> listHeroes;
        vector<Potion *> listPotions;

        int posX = this->player->getPosX();
        int posY = this->player->getPosY();

        switch (_movement)
        {
        case 'w':
            posY--;
            break;
        case 'a':
            posX--;
            break;
        case 's':
            posY++;
            break;
        case 'd':
            posX++;
            break;
        case 'n':
            break;
        case 'q':
            this->isPlaying = false;
            return;
        default:
            cout << "[ERROR : applyMovements] Houston we have a problem, there's another movement detected (_movement = " << _movement << ")" << endl;
            exit(-1);
        }

        this->player->setPosXY(posX, posY);
        listHeroes.push_back(this->player);

        if (this->currentMap.whatIs(posX, posY) == _Potion)
            this->catchPotion(posX, posY);

        RandomGenerator random;

        for (Hero *opp : this->listOpponents)
        {
            int count = 0;
            bool isMovementCorrect = false;
            int rndNb;

            this->currentMap.update(listHeroes);

            do
            {
                do
                {
                    rndNb = random.getRandomNumber(5);

                    posX = opp->getPosX();
                    posY = opp->getPosY();

                    count++;

                    switch (rndNb)
                    {
                    case 0:
                        isMovementCorrect = this->checkMovement('w', opp);
                        break;
                    case 1:
                        isMovementCorrect = this->checkMovement('a', opp);
                        break;
                    case 2:
                        isMovementCorrect = this->checkMovement('s', opp);
                        break;
                    case 3:
                        isMovementCorrect = this->checkMovement('d', opp);
                        break;
                    case 4:
                        isMovementCorrect = this->checkMovement('n', opp);
                        break;
                    default:
                        cout << "[ERROR : applyMovements] Problem with getRandomNumber(int _max) = " << rndNb << endl;
                        exit(-1);
                    }
                } while (!isMovementCorrect);

                switch (rndNb)
                {
                case 0:
                    posY--;
                    break;
                case 1:
                    posX--;
                    break;
                case 2:
                    posY++;
                    break;
                case 3:
                    posX++;
                    break;
                case 4:
                    break;
                default:
                    cout << "[ERROR : applyMovements] Forgot a case in second switch (rndNb = " << rndNb << ")" << endl;
                    exit(-1);
                }

                opp->setPosXY(posX, posY);
            } while (!this->currentMap.isCaseEmpty(posX, posY));

            listHeroes.push_back(opp);
        }

        this->currentMap.update(listHeroes);
        this->currentMap.update(this->listPotions);
    }

    /**
     * @brief Catch a potion and add it to the backpack
     * @param _x The position X
     * @param _y The position Y
     */
    void Game::catchPotion(int _x, int _y)
    {
        Potion *anyPotion = this->currentMap.whichIs(_x, _y);

        if (anyPotion == nullptr)
        {
            cout << "[ERROR : catchPotion] Potion = nullptr" << endl;
            exit(-1);
        }

        vector<Potion *>::iterator iterator = find(this->listPotions.begin(), this->listPotions.end(), anyPotion);
        int index = -1;

        if (iterator != this->listPotions.end())
        {
            index = iterator - this->listPotions.begin();
        }
        else
        {
            cout << "[ERROR : catchPotion] Potion isn't in list anymore";
            exit(-1);
        }

        if (Game::VJ_DEBUG_LOG)
        {
            cout << "BackPack Before :" << endl;
            this->player->backPack.show(Game::VJ_DEBUG_LOG);

            cout << endl
                 << "List of Potion Before :" << endl;

            for (auto &item : this->listPotions)
            {
                cout << item->getName() << endl;
            }

            cout << endl
                 << "Index : " << index << endl;
        }

        this->listPotions.erase(this->listPotions.begin() + index);
        this->player->backPack.pack(anyPotion);

        if (Game::VJ_DEBUG_LOG)
        {
            cout << endl
                 << "List of Potion After :" << endl;

            for (auto &item : this->listPotions)
            {
                cout << item->getName() << endl;
            }

            cout << endl
                 << "BackPack After :" << endl;
            this->player->backPack.show(Game::VJ_DEBUG_LOG);
        }
    }

    /**
     * @brief Display the game
     */
    void Game::display() const
    {
        if (not Game::VJ_DEBUG_LOG)
            system("CLS");

        this->currentMap.display(*this->player, this->listOpponents, this->listPotions);

        int width = this->currentMap.getWidth() * 4 + 1;
        int middle = width / 2;

        cout << " ";

        for (int k = 0; k < width; k++)
            cout << "=";

        cout << endl
             << " ";

        for (int k = 0; k < middle - 7; k++)
            cout << "=";

        cout << " INSTRUCTIONS ";

        for (int k = middle + 7; k < width; k++)
            cout << "=";

        cout << endl
             << "           w (up)" << endl
             << " a (left)  s (down)  d (right)" << endl
             << endl
             << " Not moving : n" << endl
             << " Quit the game : q" << endl;

        cout << " ";

        for (int k = 0; k < width; k++)
            cout << "=";

        cout << endl;
    }

    /**
     * @brief Set the positions
     */
    void Game::setPositions()
    {
        RandomGenerator random;

        int rndX = random.getRandomNumber(this->currentMap.getWidth());
        int rndY = random.getRandomNumber(this->currentMap.getHeight());

        vector<Hero *> listHeroes;
        vector<Potion *> listPotions;

        this->player->setPosXY(rndX, rndY);
        listHeroes.push_back(this->player);

        for (Hero *opp : this->listOpponents)
        {
            this->currentMap.update(listHeroes);

            do
            {
                rndX = random.getRandomNumber(this->currentMap.getWidth());
                rndY = random.getRandomNumber(this->currentMap.getHeight());

                opp->setPosXY(rndX, rndY);
            } while (!this->currentMap.isCaseEmpty(rndX, rndY));

            listHeroes.push_back(opp);
        }

        this->currentMap.update(listHeroes);

        for (Potion *potion : this->listPotions)
        {
            this->currentMap.update(listPotions);

            do
            {
                rndX = random.getRandomNumber(this->currentMap.getWidth());
                rndY = random.getRandomNumber(this->currentMap.getHeight());

                potion->setPosXY(rndX, rndY);
            } while (!this->currentMap.isCaseEmpty(rndX, rndY));

            listPotions.push_back(potion);
        }
        this->currentMap.update(listPotions);
    }
}