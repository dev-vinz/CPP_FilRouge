#include "..\include\Vampire.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Constructor with initialization
     * @param _name The name
     * @param _agility The agility
     * @param _intelligence The intelligence
     * @param _strength The strength
     * @param _hp The HP
     */
    Vampire::Vampire(string _name, int _agility, int _intelligence, int _strength, double _hp) : Opponent(_name, _agility, _intelligence, _strength, _hp)
    {
    }

    /**
     * @brief Interact a vampire with an other Hero
     * @param _otherHero The other hero
     * @param _attack The attack
     */
    void Vampire::interact(Hero *_otherHero, Attack _attack)
    {
        switch (_attack)
        {
        case Attack::AOne:
            Logger::writeBattle(this->getName() + " choose Vampire::scare()");
            this->scare(_otherHero);
            break;
        case Attack::ATwo:
            Logger::writeBattle(this->getName() + " choose Vampire::sucks()");
            this->sucks(_otherHero);
            break;
        case Attack::AThree:
            Logger::writeBattle(this->getName() + " choose Vampire::batAttack()");
            this->batAttack(_otherHero);
            break;
        default:
            break;
            cout << "[ERROR : Vampire::interact] Unknown attack (attack = " << (char)_attack << ")" << endl;
            exit(-1);
        }
    }

    // =================================================
    // Private Methods
    // =================================================

    /**
     * @brief Send some bats to the hero
     * @param _hero The other hero
     */
    void Vampire::batAttack(Hero *_hero) const
    {
        RandomGenerator random;
        int vampireDamage = (this->getStrength() + this->getIntelligence()) * (this->getAgilityRatio() / 2);
        int nbSummoned = random.getRandomNumber(max(vampireDamage - 3, 1), vampireDamage + 3);

        // Among all summoned, a random number are getting away, they're free !
        int nbFree = random.getRandomNumber(nbSummoned / 3);
        int nbAttack = nbSummoned - nbFree;

        // Each bats makes 1.0 damage
        double batDamage = 1.0;

        double damage = nbAttack * batDamage;
        _hero->updateHp(-damage);

        cout << " " << this->getName() << " summons " << Color::grey(nbSummoned) << " bats, and " << Color::grey(nbAttack) << " atttack you" << endl
             << " You lost " << Color::red(damage) << " HP" << endl;
    }

    /**
     * @brief Scares the other hero
     * @param _hero The other hero
     */
    void Vampire::scare(Hero *_hero) const
    {
        RandomGenerator random;
        int stats = abs(_hero->getAgility() - _hero->getStrength()) / 2 * this->getAgilityRatio();
        int reduction = random.getRandomNumber(max(stats - 2, 1), stats + 2);

        _hero->updateAgility(-reduction);

        cout << " " << this->getName() << " scares you" << endl
             << " You lost " << Color::lightPurple(reduction) << " points of agility" << endl;
    }

    /**
     * @brief Sucks the other hero
     * @param _hero The other hero
     */
    void Vampire::sucks(Hero *_hero)
    {
        RandomGenerator random;

        // Default steal : 10
        // Multiplied by 2 times the ratio of agility
        double vampireDamage = 10 * (2 * this->getAgilityRatio());
        double damage = random.getRandomDouble(max(vampireDamage - 5, 1.0), vampireDamage + 5, 1);

        _hero->updateHp(-damage);

        // You gain half of the life stolen
        // ! An algorithm do gain other than 1/2
        double ratio = 1.0 / 2.0;
        double ownGained = damage * ratio;
        this->updateHp(ownGained);

        cout << " You get sucked by " << this->getName() << endl
             << " You lost " << fixed << setprecision(1) << Color::lightRed(damage) << " HP" << endl
             << " " << this->getName() << " recovered " << fixed << setprecision(1) << Color::lightGreen(ownGained) << " HP" << endl;
    }
}