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
    }

    /**
    * @brief Fight and get the winner
    * @returns The winner
    */
    Hero *Battle::getWinner()
    {
        if (!Battle::VJ_DEBUG_LOG)
            system("CLS");

        RandomGenerator random;

        cout << " ========================================" << endl
             << " ============== NEW BATTLE ==============" << endl
             << " ========================================" << endl
             << " " << ConsoleController::getCenter(this->player->getName(), 41, '=') << endl
             << " ================== VS ==================" << endl
             << " " << ConsoleController::getCenter(this->opponent->getName(), 41, '=') << endl
             << " ========================================" << endl;

        int whoStart = random.getRandomNumber(2);
        this->turn = (Turn)whoStart;

        while (!this->isOver)
        {
            this->nextTurn();
        }

        if (this->winner == Null)
        {
            cout << "[ERROR : Battle::getWinner()] : Battle over and don't have a winner" << endl;
            exit(-1);
        }

        return (this->winner == Player) ? this->player : this->opponent;
    }

    // =============================================
    // Private Methods
    // =============================================

    /**
     * @brief Check the number
     * @param _range The range of the array
     * @param _number The number
     * @returns True if it's correct
     */
    bool Battle::checkNumber(int _range, char _number) const
    {
        vector<char> tabNumbers;
        const int ASCII_ZERO = 48;

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
        cout << " ========================================" << endl;
    }

    /**
     * @brief Apply next turn
     */
    void Battle::nextTurn()
    {
        if (this->turn == Player)
        {
            this->playerTurn();
            this->turn = Opponent;
        }
        else
        {
            this->opponentTurn();
            this->turn = Player;
        }
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
            this->openBackPack();
            this->playerTurn();
            break;
        case '2':
            this->fight(this->player, this->opponent);
            break;
        case '3':
        case '4':
            break;
        default:
            cout << "[ERROR : Battle::playerTurn()] : It misses a case in switch of actions (action = " << action << ")" << endl;
            exit(-1);
        }

        this->isOver = true;
        this->winner = Player;
    }

    /**
     * @brief Opponent's turn
     */
    void Battle::opponentTurn()
    {
    }

    /**
     * @brief Fight the two heroes
     * @param _attacker The attacker
     * @param _defender The defender
     */
    void Battle::fight(Hero *_attacker, Hero *_defender) const
    {
        if (_attacker->getIsPlayer())
        {
            cout << " ========================================" << endl
                 << " Choose your attack :" << endl;
        }

        char attack;
        string _endLine;

        do
        {
            if (_attacker->getIsPlayer())
            {
                _attacker->displayAttacks();

                cout << " >>> ";

                cin >> attack;
                getline(cin, _endLine);
            }
        } while (!this->checkNumber(3, attack));

        cout << " ========================================" << endl;
        _attacker->interact(_defender, attack);
    }

    /**
     * @brief Open the backpack
     */
    void Battle::openBackPack() const
    {
        if (this->player->backPack.isNotEmpty())
        {
            string _endLine;
            char decision;

            cout << " ========================================" << endl
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
            cout << " ========================================" << endl
                 << " Your backpack is empty, sorry" << endl
                 << " ========================================" << endl;
        }
    }
}