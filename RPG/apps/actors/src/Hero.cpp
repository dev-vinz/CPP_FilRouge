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
     * @brief Use the object
     * @param _object The object
     */
    void Hero::useObject(IObject *_object)
    {
        Potion *ptrPotion = dynamic_cast<Potion *>(_object);

        if (ptrPotion != nullptr)
        {
            switch (ptrPotion->getUtility())
            {
            case Agility:
                this->agility += ptrPotion->getFeature();
                break;
            case Heal:
                if (this->currentHp + ptrPotion->getFeature() > this->hp)
                {
                    this->currentHp = this->hp;
                }
                else
                {
                    this->currentHp += ptrPotion->getFeature();
                }
                break;
            case Strength:
                this->strength += ptrPotion->getFeature();
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