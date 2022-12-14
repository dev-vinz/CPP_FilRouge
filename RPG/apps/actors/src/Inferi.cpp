#include "..\include\Inferi.hpp"

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
    Inferi::Inferi(string _name, int _agility, int _intelligence, int _strength, double _hp) : Opponent(_name, _agility, _intelligence, _strength, _hp)
    {
    }

    /**
     * @brief Interact an inferi with an other Hero
     * @param _otherHero The other hero
     * @param _attack The attack
     */
    void Inferi::interact(Hero *_otherHero, Attack _attack)
    {
        switch (_attack)
        {
        case Attack::AOne:
            Logger::writeBattle(this->getName() + " choose Inferi::onslaught()");
            this->onslaught(_otherHero);
            break;
        case Attack::ATwo:
            Logger::writeBattle(this->getName() + " choose Inferi::immobilizes()");
            this->immobilizes(_otherHero);
            break;
        case Attack::AThree:
            Logger::writeBattle(this->getName() + " choose Inferi::blindly()");
            this->blindly(_otherHero);
            break;
        default:
            break;
            cout << "[ERROR : Inferi::interact] Unknown attack (attack = " << (char)_attack << ")" << endl;
            exit(-1);
        }
    }

    // =================================================
    // Private Methods
    // =================================================

    /**
     * @brief Blindly the hero
     * @param _hero The hero
     */
    void Inferi::blindly(Hero *_hero) const
    {
        int reduction = _hero->getAgility() * _hero->getIntelligenceRatio() * _hero->getStrengthRatio() * _hero->getAgilityRatio();

        _hero->updateAgility(-reduction);

        cout << " " << this->getName() << " blinded you" << endl
             << " You lost " << Color::lightPurple(reduction) << " of agility" << endl;
    }

    /**
     * @brief Immobilizes the hero
     * @param _hero The hero
     */
    void Inferi::immobilizes(Hero *_hero) const
    {
        int reduction = max(_hero->getStrength() / 2 * pow(_hero->getStrengthRatio(), 4), 1.0);

        if (Inferi::VJ_DEBUG_LOG)
        {
            cout << " Inferi::immobilizes()" << endl
                 << " Strength Ratio ^4 : " << pow(_hero->getStrengthRatio(), 4) << endl
                 << " Reduction : " << reduction << endl;
        }

        _hero->updateStrength(-reduction);

        cout << " " << this->getName() << " immobilizes you" << endl
             << " By dint of struggling, you lost " << Color::lightYellow(reduction) << " of strength" << endl;
    }

    /**
     * @brief Onslaught the hero
     * @param _hero The hero
     */
    void Inferi::onslaught(Hero *_hero) const
    {
        RandomGenerator random;

        int strength = this->getStrength() / 10;
        double damage = random.getRandomDouble(max(strength - 3, 1), min(strength + 3, MAX_STRENGTH), 1);

        _hero->updateHp(-damage);

        cout << " " << this->getName() << " rushed on you" << endl
             << " You lost " << fixed << setprecision(1) << Color::lightRed(damage) << " HP" << endl;
    }
}