#include "..\include\Necromancer.hpp"

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
     */
    Necromancer::Necromancer(string _name, int _agility, int _intelligence, int _strength, int _mana, double _hp, IObject *_pStuff) : Wizard(_name, _agility, _intelligence, _strength, _mana, _hp, _pStuff)
    {
    }

    /**
     * @brief Rise undead
     * @param _hero The other hero
     */
    void Necromancer::riseUndead(Hero *_hero)
    {
        RandomGenerator random;

        // Scepter power, multiplied by the ratio of agility
        int necromancerDamage = this->pStuff->getFeature() * this->getAgilityRatio();
        int nbSummoned = random.getRandomNumber(max(necromancerDamage - 3, 0), necromancerDamage + 3);

        // Among all summoned, a random number are traitors and attack you
        int nbTraitors = random.getRandomNumber(nbSummoned / 2);
        int nbAttack = nbSummoned - nbTraitors;

        // Each summons makes 1.2 damage
        double summonDamage = 1.2;

        double damage = summonDamage * nbAttack;
        _hero->updateHp(-damage);

        if (Necromancer::VJ_DEBUG_LOG)
        {
            cout << " Scepter's power : " << this->pStuff->getFeature() << endl
                 << " Agility : " << this->getAgility() << endl
                 << " NecromancerDamage : " << necromancerDamage << endl
                 << " NbSummoned : " << nbSummoned << endl
                 << " NbTraitors : " << nbTraitors << endl;
        }

        cout << " You summons " << nbSummoned << " undead and " << nbAttack << " attack your opponent" << endl
             << " " << _hero->getName() << " lost " << fixed << setprecision(1) << damage << " HP" << endl;

        if (nbTraitors)
        {
            double ownDamage = summonDamage * nbTraitors;
            this->updateHp(-ownDamage);

            cout << endl
                 << " Unfortunately, " << nbTraitors << " of them are traitors, and attack you" << endl
                 << " You lost " << fixed << setprecision(1) << ownDamage << " HP" << endl;
        }
    }

    /**
     * @brief Display the necromancer's attacks
     */
    void Necromancer::displayAttacks() const
    {
        cout << " [1] Lifesteal" << endl
             << " [2] Sommon undead" << endl
             << " [3] Provokes a cataclysm" << endl;
    }

    /**
     * @brief Interact a necromancer with an other Hero
     * TODO Use mana to cast spells, otherwise a simple punch
     * @param otherHero The other hero
     * @param _attack The attack
     */
    void Necromancer::interact(Hero *otherHero, char _attack)
    {
        switch (_attack)
        {
        case '1':
            this->lifeSteal(otherHero);
            break;
        case '2':
            this->riseUndead(otherHero);
            break;
        case '3':
            this->cataclysm(otherHero);
            break;
        default:
            break;
            cout << "[ERROR : Necromancer::interact()] : Unknown attack (attack = " << _attack << ")" << endl;
            exit(-1);
        }
    }

    /**
     * @brief Show the different attributes of the necromancer
     */
    void Necromancer::show() const
    {
        cout << "\n =================\n"
             << " NECROMANCER : " << this->getName()
             << "\n =================\n"
             << "\n Agility : " << this->getAgility()
             << "\n Intelligence : " << this->getIntelligence()
             << "\n Strength : " << this->getStrength()
             // << "\n Mana : " << this->getMana()
             << "\n Max HP : " << this->hp
             << "\n Current HP : " << this->getHp()
             << "\n Stuff : " << this->getStuff()->getName() << ", with a power of " << this->getStuff()->getFeature()
             << endl;
    }

    // =============================================
    // Private Methods
    // =============================================

    /**
     * @brief Provokes a cataclysm
     * @param _hero The other hero
     */
    void Necromancer::cataclysm(Hero *_hero)
    {
        RandomGenerator random;

        // Default damage : 30
        // Multiplied by the ratio of agility
        double necromancerDamage = 30 * this->getAgilityRatio();
        double damage = random.getRandomDouble(max(necromancerDamage - 1, 0.0), necromancerDamage + 1, 1);

        _hero->updateHp(-damage);

        // You suffers half of the damage
        // TODO An algorithm to reduce damage in function of agility
        double ratio = 1.0 / 2.0;
        double ownDamage = damage * ratio;
        this->updateHp(-ownDamage);

        cout << " You provoke a cataclysm, and " << _hero->getName() << " lost " << fixed << setprecision(1) << damage << " HP" << endl
             << " Unfortunately you receive " << fixed << setprecision(2) << ratio * 100 << "\% of the damages, and lost " << fixed << setprecision(1) << ownDamage << " HP" << endl;
    }

    /**
     * @brief Steal your opponent's life and gains it
     * @param _hero The other hero
     */
    void Necromancer::lifeSteal(Hero *_hero)
    {
        RandomGenerator random;

        // Default steal : 10
        // Multiplied by 2 times the ratio of agility
        double necromancerDamage = 10 * (2 * this->getAgilityRatio());
        double damage = random.getRandomDouble(max(necromancerDamage - 5, 0.0), necromancerDamage + 5, 1);

        _hero->updateHp(-damage);

        // You gain half of the life stolen
        // ! An algorithm do gain other than 1/2
        double ratio = 1.0 / 2.0;
        double ownGained = damage * ratio;
        this->updateHp(ownGained);

        cout << " " << _hero->getName() << " lost " << fixed << setprecision(1) << damage << " HP" << endl
             << " You recovered " << fixed << setprecision(1) << ownGained << " HP" << endl;
    }
}