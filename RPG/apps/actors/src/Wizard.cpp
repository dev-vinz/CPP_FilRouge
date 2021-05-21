#include "..\include\Wizard.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initialization of all parameters
     * @param _name The name
     * @param _agility The agility
     * @param _intelligence The intelligence
     * @param _strength The strength
     * @param _mana The mana
     * @param _hp The HP
     * @param _pStuff The stuff
     * @param _isPlayer Is it the player
     */
    Wizard::Wizard(string _name, int _agility, int _intelligence, int _strength, int _mana, double _hp, IObject *_pStuff, bool _isPlayer) : Hero(_name, _agility, _intelligence, _strength, _hp, _pStuff, _isPlayer), mana(_mana)
    {
        this->currentHp = _hp;
    }

    /**
     * @brief Get the mana
     * @returns The mana
     */
    int Wizard::getMana() const
    {
        return this->mana;
    }

    /**
     * @brief Cast a spell
     * @param _hero The other hero
     */
    void Wizard::castSpell(Hero *_hero)
    {
        RandomGenerator random;
        double damage = random.getRandomDouble(10, 16);

        _hero->setHp(_hero->getHp() - damage);

        cout << " You cast a fireball on " << _hero->getName() << endl
             << " " << _hero->getName() << " lost " << fixed << setprecision(1) << damage << " HP" << endl;
    }

    /**
     * @brief Display the wizard's attacks
     */
    void Wizard::displayAttacks() const
    {
        cout << " [1] Dizzy spell" << endl
             << " [2] Cast a fireball" << endl
             << " [3] Giant wave" << endl;
    }

    /**
     * @brief Interact a wizard with an other Hero
     * @param otherHero The other hero
     * @param _attack The attack
     */
    void Wizard::interact(Hero *anotherHero, char _attack)
    {
        switch (_attack)
        {
        case '1':
            this->dizzySpell(anotherHero);
            break;
        case '2':
            this->castSpell(anotherHero);
            break;
        case '3':
            this->giantWave(anotherHero);
            break;
        default:
            break;
            cout << "[ERROR : Wizard::interact()] : Unknown attack (attack = " << _attack << ")" << endl;
            exit(-1);
        }
    }

    /**
     * @brief Show the different attributes of the wizard
     */
    void Wizard::show() const
    {
        cout << "\n=================\n"
             << "WIZARD : " << this->getName()
             << "\n=================\n"
             << "\nAgility : " << this->getAgility()
             << "\nIntelligence : " << this->getIntelligence()
             << "\nStrength : " << this->getStrength()
             << "\nMana : " << this->getMana()
             << "\nHP : " << this->hp
             << "\nCurrent HP :" << this->getHp()
             << "\nStuff : " << this->getStuff()->getName()
             << endl;
    }

    // =============================================
    // Private Methods
    // =============================================

    /**
     * @brief Dizzy the other hero
     * @param _hero The other hero
     */
    void Wizard::dizzySpell(Hero *_hero)
    {
        _hero->setAgility(_hero->getAgility() - 5);

        if (_hero->getAgility() < 0)
            _hero->setAgility(0);

        cout << " " << _hero->getName() << "'s agility has been reduced to " << _hero->getAgility() << endl;
    }

    /**
     * @brief Create a giant wave
     * @param _hero The other hero
     */
    void Wizard::giantWave(Hero *_hero)
    {
        RandomGenerator random;
        double damage = random.getRandomDouble(13, 18);

        _hero->setHp(_hero->getHp() - damage);

        cout << " A giant wave arrives !" << endl
             << " " << _hero->getName() << " lost " << fixed << setprecision(1) << damage << " HP" << endl;
    }
}