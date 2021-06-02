#include "..\include\Warrior.hpp"

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
     */
    Warrior::Warrior(string _name, int _agility, int _intelligence, int _strength, double _hp, IObject *_pStuff) : Player(_name, _agility, _intelligence, _strength, _hp, _pStuff)
    {
    }

    /**
     * @brief Display the warrior's attacks
     */
    void Warrior::displayAttacks() const
    {
        cout << " [1] Punch" << endl
             << " [2] Give a sword strike" << endl
             << " [3] Provokes an earthquake" << endl;
    }

    /**
     * @brief Interact a warrior with an other Hero
     * @param otherHero The other hero
     * @param _attack The attack
     */
    void Warrior::interact(Hero *otherHero, char _attack)
    {
        switch (_attack)
        {
        case '1':
            this->punch(otherHero);
            break;
        case '2':
            this->swordStrike(otherHero);
            break;
        case '3':
            this->earthQuake(otherHero);
            break;
        default:
            break;
            cout << "[ERROR : Warrior::interact()] : Unknown attack (attack = " << _attack << ")" << endl;
            exit(-1);
        }
    }

    /**
     * @brief Show the different attributes of the warrior
     */
    void Warrior::show() const
    {
        cout << "\n =================\n"
             << " WARRIOR : " << this->getName()
             << "\n =================\n"
             << "\n Agility : " << this->getAgility()
             << "\n Intelligence : " << this->getIntelligence()
             << "\n Strength : " << this->getStrength()
             << "\n Max HP : " << this->hp
             << "\n Current HP : " << this->getHp()
             << "\n Stuff : " << this->getStuff()->getName() << ", with a damage of " << this->getStuff()->getFeature()
             << endl;
    }

    // =================================================
    // Private Methods
    // =================================================

    /**
     * @brief Provokes an earthquake
     * @param _hero The other hero
     */
    void Warrior::earthQuake(Hero *_hero)
    {
        RandomGenerator random;

        // Default damage of earthquake : 15
        // Multiplied by 2 times the ratio of strength
        double warriorDamage = 15 * (2 * this->getStrengthRatio());
        double damage = random.getRandomDouble(max(warriorDamage - 5, 0.0), warriorDamage + 5, 1);

        _hero->updateHp(-damage);

        // You suffers 3/4 of the damage
        // TODO An algorithm to dodge it with intelligence and agility, or to receive less than 3/4
        double ratio = 3.0 / 4.0;
        double ownDamage = damage * ratio;
        this->updateHp(-ownDamage);

        cout << " You provoke an earthquake, and " << _hero->getName() << " lost " << fixed << setprecision(1) << damage << " HP" << endl
             << " Unfortunately you receive " << fixed << setprecision(2) << ratio * 100 << "\% of the damages, and lost " << fixed << setprecision(1) << ownDamage << " HP" << endl;
    }

    /**
     * @brief Punch an other hero
     * @param _hero The other hero
     */
    void Warrior::punch(Hero *_hero) const
    {
        RandomGenerator random;

        int strength = this->getStrength() / 10;
        double damage = random.getRandomDouble(max(strength - 3, 0), min(strength + 3, MAX_STRENGTH), 1);

        _hero->updateHp(-damage);

        cout << " You punch " << _hero->getName() << "'s face" << endl
             << " " << _hero->getName() << " lost " << fixed << setprecision(1) << damage << " HP" << endl;
    }

    /**
     * @brief Give a strike of sword
     * @param _hero The other hero
     */
    void Warrior::swordStrike(Hero *_hero) const
    {
        RandomGenerator random;

        // Sword damage, multiplied by the ratio of strength
        double warriorDamage = this->pStuff->getFeature() * this->getStrengthRatio();
        double damage = random.getRandomDouble(max(warriorDamage - 2, 0.0), warriorDamage + 2, 1);

        if (Warrior::VJ_DEBUG_LOG)
        {
            cout << " Sword's power : " << this->pStuff->getFeature() << endl
                 << " Strength : " << this->getStrength() << endl
                 << " random.getRandomDouble() : " << damage << endl;
        }

        _hero->updateHp(-damage);

        cout << " You give a strike of sword to " << _hero->getName() << endl
             << " " << _hero->getName() << " lost " << fixed << setprecision(1) << damage << " HP" << endl;
    }
}