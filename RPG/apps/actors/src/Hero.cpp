#include "..\include\Hero.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initialization of all parameters
     * @param _name The name
     * @param _agility The agility
     * @param _intelligence The intelligence
     * @param _strength The strength
     * @param _hp The HP
     * @param _pStuff The stuff
     * @param _isPlayer Is it the player
     */
    Hero::Hero(string _name, int _agility, int _intelligence, int _strength, double _hp, IObject *_pStuff, bool _isPlayer) : name(_name), agility(_agility), intelligence(_intelligence), strength(_strength), hp(_hp), currentHp(_hp), pStuff(_pStuff), isPlayer(_isPlayer)
    {
    }

    /**
     * @brief Destructor, delete the pointer on stuff
     */
    Hero::~Hero()
    {
        if (this->pStuff != nullptr)
        {
            delete this->pStuff;
            this->pStuff = nullptr;
        }
    }

    /**
     * @brief Get the name
     * @returns The name
     */
    string Hero::getName() const
    {
        return this->name;
    }

    /**
     * @brief Get the agility
     * @returns The agility
     */
    int Hero::getAgility() const
    {
        return this->agility;
    }

    /**
     * @brief Get the intelligence
     * @returns The intelligence
     */
    int Hero::getIntelligence() const
    {
        return this->intelligence;
    }

    /**
     * @brief Get the strength
     * @returns The strength
     */
    int Hero::getStrength() const
    {
        return this->strength;
    }

    /**
     * @brief Get the HP
     * @returns The HP
     */
    double Hero::getHp() const
    {
        return this->currentHp;
    }

    /**
     * @brief Get the pointer on stuff
     * @returns The pointer
     */
    IObject *Hero::getStuff() const
    {
        return this->pStuff;
    }

    /**
     * @brief Check if this object is the player
     * @returns True if it is
     */
    bool Hero::getIsPlayer() const
    {
        return this->isPlayer;
    }

    /**
     * @brief Get the position in X
     * @returns The X position
     */
    int Hero::getPosX() const
    {
        return this->posX;
    }

    /**
     * @brief Get the position in Y
     * @returns The Y position
     */
    int Hero::getPosY() const
    {
        return this->posY;
    }

    /**
     * @brief Get the ratio of agility
     * @returns The ratio
     */
    double Hero::getAgilityRatio() const
    {
        return (double)this->getAgility() / MAX_AGILITY;
    }

    /**
     * @brief Get the ratio of intelligence
     * @returns The ratio
     */
    double Hero::getIntelligenceRatio() const
    {
        return (double)this->getIntelligence() / MAX_INTELLIGENCE;
    }

    /**
     * @brief Get the ratio of strength
     * @returns The ratio
     */
    double Hero::getStrengthRatio() const
    {
        return (double)this->getStrength() / MAX_STRENGTH;
    }

    /**
     * @brief Set the agility
     * @param _agility The agility
     */
    void Hero::setAgility(int _agility)
    {
        this->agility = _agility;
    }

    /**
     * @brief Set the current HP
     * @param _hp The hp
     */
    void Hero::setHp(double _hp)
    {
        this->currentHp = _hp;
    }

    /**
     * @brief Set the position X and Y
     * @param _x The position
     * @param _y The position
     */
    void Hero::setPosXY(int _x, int _y)
    {
        this->posX = _x;
        this->posY = _y;
    }

    /**
     * @brief Get and set Agility : New Agility = Agility + _update
     * @param _update The modification to do
     */
    void Hero::updateAgility(int _update)
    {
        this->agility = max(min(this->agility + _update, MAX_AGILITY), 0);
    }

    /**
     * @brief Get and set HP : New HP = HP + _update
     * @param _update The modification to do
     */
    void Hero::updateHp(double _update)
    {
        this->currentHp = min(this->currentHp + _update, this->hp);
    }

    /**
     * @brief Get and set Strength : New Strength = Strength + _update
     * @param _update The modification to do
     */
    void Hero::updateStrength(int _update)
    {
        this->strength = max(min(this->strength + _update, MAX_STRENGTH), 0);
    }

    /**
     * @brief Use the object
     * @param _object The object
     */
    void Hero::useObject(IObject *_object)
    {
        Potion *ptrPotion = dynamic_cast<Potion *>(_object);

        if (ptrPotion != nullptr)
        {
            int power = ptrPotion->getFeature();
            switch (ptrPotion->getUtility())
            {
            case Agility:
                this->updateAgility(power);
                break;
            case Heal:
                this->updateHp(power);
                break;
            case Strength:
                this->updateStrength(power);
                break;
            default:
                cout << "[ERROR : Hero::useObject()] : Unknown potion" << endl;
                exit(-1);
            }
        }
        else
        {
            cout << "[WARNING : Hero::userObject()] : Object is not a potion" << endl;
        }
    }

    /**
     * @brief Show the battle statistics
     */
    void Hero::showStatistics() const
    {
        cout << " ========================================" << endl
             << "                        HP : " << fixed << setprecision(1) << this->getHp() << endl
             << "    " << left << setfill(' ') << setw(20) << this->getName() << "Strength : " << fixed << setprecision(1) << this->getStrength() << endl
             << "                        Agility : " << fixed << setprecision(1) << this->getAgility() << endl
             << " ========================================" << endl;
    }

    /**
     * @brief Override of operator <<
     * @param s The stream
     * @param h The hero
     * @returns The stream
     */
    ostream &operator<<(ostream &s, const Hero &h)
    {
        return s << "\n =================\n"
                 << " HERO : " << h.getName()
                 << "\n =================\n"
                 << "\n Agility : " << h.getAgility()
                 << "\n Intelligence : " << h.getIntelligence()
                 << "\n Strength : " << h.getStrength()
                 << "\n HP : " << h.getHp()
                 << "\n Stuff : " << h.getStuff()->getName();
    }
}