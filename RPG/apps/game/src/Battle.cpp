#include "..\include\Battle.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initialization
     * @param _player The player
     * @param _opponent The opponent
     */
    Battle::Battle(Hero *_player, Hero *_opponent) : player(_player), opponent(_opponent)
    {
        Logger::writeBattle("Battle successfully created", _opponent->getName() + ".log");
    }

    /**
     * @brief Destructor
     */
    Battle::~Battle()
    {
        Logger::writeBattle("Battle is ended");
    }

    /**
    * @brief Fight and get the winner
    * @returns The winner
    */
    Hero *Battle::getWinner()
    {
        RandomGenerator random;

        cout << " ============================================" << endl
             << " ================ NEW BATTLE ================" << endl
             << " ============================================" << endl
             << " " << ConsoleController::getCenter(this->player->getName(), 45, '=') << endl
             << " ==================== VS ====================" << endl
             << " " << ConsoleController::getCenter(this->opponent->getName(), 45, '=') << endl
             << " ============================================" << endl;

        this->turn = Turn::TPlayer;

        while (!this->isOver)
        {
            this->nextTurn();
        }

        Hero *winner = nullptr;

        switch (this->winner)
        {
        case Turn::TNull:
            cout << "[ERROR : Battle::getWinner] Battle over and don't have a winner" << endl;
            exit(-1);
        case Turn::TPlayer:
            winner = this->player;
            break;
        case Turn::TOpponent:
            winner = this->opponent;
            break;
        case Turn::TNone:
            // Both are dead, return nullptr
            break;
        default:
            cout << "[ERROR : Battle::getWinner] Unknown state of winner" << endl;
            exit(-1);
        }

        return winner;
    }

    // =================================================
    // Private Methods
    // =================================================

    /**
     * @brief Check the number
     * @param _range The range of the array
     * @param _number The number
     * @returns True if it's correct
     */
    bool Battle::checkNumber(int _range, char _number) const
    {
        vector<char> tabNumbers;

        for (int k = 1; k <= _range; k++)
            tabNumbers.push_back(k + ASCII_ZERO);

        return ConsoleController::checkInput(tabNumbers, _number);
    }

    /**
     * @brief Check yes or no
     * @param _yn Yes or no
     * @returns True if it's correct
     */
    bool Battle::checkYesNo(char _yn) const
    {
        _yn = tolower(_yn, locale());
        char tabYesNo[] = {'y', 'n'};

        return ConsoleController::checkInput(tabYesNo, _yn);
    }

    /**
     * @brief Display the heroes' statistics
     */
    void Battle::display() const
    {
        this->player->showStatistics();
        this->opponent->showStatistics();
        cout << " ============================================" << endl;
    }

    /**
     * @brief Apply next turn
     */
    void Battle::nextTurn()
    {
        Logger::writeBattle("- - -");
        if (this->turn == Turn::TPlayer)
        {
            Logger::writeBattle("Player : " + this->player->getName() + "'s turn");
            this->playerTurn();
            this->turn = Turn::TOpponent;
        }
        else
        {
            Logger::writeBattle("Opponent : " + this->opponent->getName() + "'s turn");
            this->opponentTurn();
            this->turn = Turn::TPlayer;
        }

        Logger::writeBattle(this->player->getName() + " :\n\t\t\tHP = " + to_string(this->player->getHp()) + "\n\t\t\tAgility = " + to_string(this->player->getAgility()) + "\n\t\t\tStrength = " + to_string(this->player->getStrength()));
        Logger::writeBattle(this->opponent->getName() + " :\n\t\t\tHP = " + to_string(this->opponent->getHp()) + "\n\t\t\tAgility = " + to_string(this->opponent->getAgility()) + "\n\t\t\tStrength = " + to_string(this->opponent->getStrength()));
    }

    /**
     * @brief Player's turn
     */
    void Battle::playerTurn()
    {
        this->display();

        cout << " It's your turn, what do you want to do ?" << endl;

        char action;
        string _endLine;

        do
        {
            cout << " [1] Open backpack" << endl
                 << " [2] Fight" << endl
                 << " [3] Dodge next opponent's attack" << endl
                 << " [4] Concede battle" << endl
                 << " >>> ";

            cin >> action;
            getline(cin, _endLine);
        } while (!this->checkNumber(4, action));

        switch (action)
        {
        case '1':
            Logger::writeBattle(this->player->getName() + " opened his backpack");
            this->openBackPack();
            this->playerTurn();
            break;
        case '2':
            Logger::writeBattle(this->player->getName() + " choose to fight");
            this->fight(this->player, this->opponent);
            break;
        case '3':
            Logger::writeBattle(this->player->getName() + " prepared to dodge");
            this->prepareDodge(this->player);
            break;
        case '4':
            Logger::writeBattle(this->player->getName() + " has concede");
            this->concede();
            break;
        default:
            cout << "[ERROR : Battle::playerTurn] It misses a case in switch of actions (action = " << action << ")" << endl;
            exit(-1);
        }
    }

    /**
     * @brief Opponent's turn
     */
    void Battle::opponentTurn()
    {
        RandomGenerator random;
        char action = (char)(ASCII_ZERO + random.getRandomNumber(1, 4));

        switch (action)
        {
        case '1':
        case '2':
            Logger::writeBattle(this->opponent->getName() + " choose to fight");
            this->fight(this->opponent, this->player);
            break;
        case '3':
            Logger::writeBattle(this->opponent->getName() + " prepared to dodge");
            this->prepareDodge(this->opponent);
            break;
        default:
            cout << "[ERROR : Battle::opponentTurn] Problem with the random generator (action = " << action << ")" << endl;
            exit(-1);
        }
    }

    /**
     * @brief Concede the battle
     */
    void Battle::concede()
    {
        this->isOver = true;
        this->winner = Turn::TOpponent;

        // TODO Penalyse the hero for concede
    }

    /**
     * @brief Fight the two heroes
     * @param _attacker The attacker
     * @param _defender The defender
     */
    void Battle::fight(Hero *_attacker, Hero *_defender)
    {
        char attack;
        string _endLine;

        if (_attacker->getIsPlayer())
        {
            cout << " ============================================" << endl
                 << " Choose your attack :" << endl;

            do
            {
                _attacker->displayAttacks();

                cout << " >>> ";

                cin >> attack;
                getline(cin, _endLine);

            } while (!this->checkNumber(3, attack));
        }
        else
        {
            RandomGenerator random;

            attack = (char)(ASCII_ZERO + random.getRandomNumber(1, 4));
        }

        if (_attacker->getIsPlayer() && !Battle::VJ_DEBUG_LOG)
        {
            ConsoleController::displayLoading("Waiting for opponent", 2);
        }

        cout << " " << ConsoleController::getCenter(_attacker->getName(), 45, '=') << endl;

        if (!_defender->isDodging())
        {
            // _attacker attack
            _attacker->interact(_defender, (Attack)attack);
        }
        else
        {
            // _defender dodge the attack
            cout << " Oof, the attack missed " << _defender->getName() << endl;
            Logger::writeBattle(_defender->getName() + " dodged the attack");
        }

        // Now we check who is dead
        if (_attacker->isDead() && _defender->isDead())
        {
            this->isOver = true;
            this->winner = Turn::TNone;
            Logger::writeBattle("Nobody has won");
        }
        else if (_defender->isDead())
        {
            this->isOver = true;
            this->winner = (_attacker->getIsPlayer()) ? Turn::TPlayer : Turn::TOpponent;
            Logger::writeBattle((this->winner == Turn::TPlayer) ? "Player : " + this->player->getName() + " has won" : "Opponent : " + this->opponent->getName() + " has won");
        }
        else if (_attacker->isDead())
        {
            this->isOver = true;
            this->winner = (_defender->getIsPlayer()) ? Turn::TPlayer : Turn::TOpponent;
            Logger::writeBattle((this->winner == Turn::TPlayer) ? "Player : " + this->player->getName() + " has won" : "Opponent : " + this->opponent->getName() + " has won");
        }
    }

    /**
     * @brief Open the backpack
     */
    void Battle::openBackPack() const
    {
        ConsoleController::displayLoading("Opening backpack", 2);

        if (this->player->backPack.isNotEmpty())
        {
            string _endLine;
            char decision;

            cout << " ============================================" << endl
                 << " Here's what's on top of your backpack : " << this->player->backPack.top()->getName() << " with power of " << this->player->backPack.top()->getFeature() << endl
                 << " Do you want to use it ?" << endl;

            do
            {
                cout << " [Y] Yes" << endl
                     << " [N] No" << endl
                     << " >>> ";

                cin >> decision;
                getline(cin, _endLine);
            } while (!this->checkYesNo(decision));

            if (decision == 'y')
            {
                IObject *object = this->player->backPack.unPack();
                this->player->useObject(object);
            }
        }
        else
        {
            cout << " ============================================" << endl
                 << " Your backpack is empty, sorry" << endl
                 << " ============================================" << endl;
        }

        ConsoleController::displayLoading("Closing backpack", 2);
    }

    /**
     * @brief Prepare the hero to dodge next attack
     * @param _hero The hero
     */
    void Battle::prepareDodge(Hero *_hero) const
    {
        if (_hero->getIsPlayer() && !Battle::VJ_DEBUG_LOG)
        {
            ConsoleController::displayLoading("Waiting for opponent", 2);
        }

        cout << " " << ConsoleController::getCenter(_hero->getName(), 45, '=') << endl
             << " " << _hero->getName() << " is trying to dodge next attack" << endl;

        _hero->switchDodge();
    }
}