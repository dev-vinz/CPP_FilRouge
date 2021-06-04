#include "..\include\Medusa.hpp"

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
    Medusa::Medusa(string _name, int _agility, int _intelligence, int _strength, double _hp) : Opponent(_name, _agility, _intelligence, _strength, _hp)
    {
    }

    /**
     * @brief Interact a Medusa with an other Hero
     * @param _otherHero The other hero
     * @param _attack The attack
     */
    void Medusa::interact(Hero *_otherHero, char _attack)
    {
        switch (_attack)
        {
        case '1':
            this->snakeAttack(_otherHero);
            break;
        case '2':
            this->seduce(_otherHero);
            break;
        case '3':
            this->petrification(_otherHero);
            break;
        default:
            break;
            cout << "[ERROR : Medusa::interact()] : Unknown attack (attack = " << _attack << ")" << endl;
            exit(-1);
        }
    }

    // =================================================
    // Private Methods
    // =================================================

    /**
     * @brief Petrifies the hero
     * @param _hero The other hero
     */
    void Medusa::petrification(Hero *_hero) const
    {
        RandomGenerator random;
        double power = this->getIntelligenceRatio() * this->getStrength();

        int reductionAgility = power / 4;
        int reductionStrength = power / 4;
        double reductionHp = power / 3;

        _hero->updateAgility(-reductionAgility);
        _hero->updateStrength(-reductionStrength);
        _hero->updateHp(-reductionHp);

        cout << " You have been petrified by " << this->getName() << "'s look" << endl
             << " You lost " << endl
             << "   - " << Color::lightPurple(reductionAgility) << " points of agility" << endl
             << "   - " << Color::lightYellow(reductionStrength) << " points of strength" << endl
             << "   - " << fixed << setprecision(1) << Color::lightRed(reductionHp) << " HP" << endl;
    }

    /**
     * @brief Seduces the hero
     * @param _hero The other hero
     */
    void Medusa::seduce(Hero *_hero) const
    {
        RandomGenerator random;

        int medusaSeduction = this->getIntelligenceRatio() / 2;
        int reduction = random.getRandomNumber(max(medusaSeduction - 3, 1), medusaSeduction + 3);

        _hero->updateAgility(-reduction);

        cout << " " << this->getName() << " seduced you" << endl
             << " You lost " << Color::lightPurple(reduction) << " points of agility" << endl;
    }

    /**
     * @brief Attacks with snakes
     * @param _hero The other hero
     */
    void Medusa::snakeAttack(Hero *_hero) const
    {
        RandomGenerator random;

        int strength = this->getStrength() / 5;
        double damage = random.getRandomDouble(max(strength - 3, 1), min(strength + 3, MAX_STRENGTH), 1);

        _hero->updateHp(-damage);

        cout << " " << this->getName() << " used snake to attack you" << endl
             << " You lost " << fixed << setprecision(1) << Color::lightRed(damage) << " HP" << endl;
    }
}