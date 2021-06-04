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
     */
    Wizard::Wizard(string _name, int _agility, int _intelligence, int _strength, int _mana, double _hp, IObject *_pStuff) : Player(_name, _agility, _intelligence, _strength, _hp, _pStuff), mana(_mana)
    {
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
    void Wizard::castSpell(Hero *_hero) const
    {
        RandomGenerator random;

        // Power of the magic wand, multiplied by the ratio of intelligence
        double stuffDamage = this->pStuff->getFeature() * this->getIntelligenceRatio();
        double damage = random.getRandomDouble(max(stuffDamage - 2, 1.0), stuffDamage + 2, 1);

        _hero->updateHp(-damage);

        cout << " You cast a fireball on " << _hero->getName() << endl
             << " " << _hero->getName() << " lost " << fixed << setprecision(1) << Color::lightRed(damage) << " HP" << endl;
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
     * TODO Use mana to cast spells, otherwise a simple punch
     * @param otherHero The other hero
     * @param _attack The attack
     */
    void Wizard::interact(Hero *anotherHero, char _attack)
    {
        switch (_attack)
        {
        case '1':
            Logger::writeBattle(this->getName() + " choose Wizard::dizzySpell()");
            this->dizzySpell(anotherHero);
            break;
        case '2':
            Logger::writeBattle(this->getName() + " choose Wizard::castSpell()");
            this->castSpell(anotherHero);
            break;
        case '3':
            Logger::writeBattle(this->getName() + " choose Wizard::giantWave()");
            this->giantWave(anotherHero);
            break;
        default:
            break;
            cout << "[ERROR : Wizard::interact] Unknown attack (attack = " << _attack << ")" << endl;
            exit(-1);
        }
    }

    /**
     * @brief Show the different attributes of the wizard
     */
    void Wizard::show() const
    {
        cout << "\n ============================================\n"
             << " WIZARD : " << this->getName()
             << "\n ============================================\n"
             << "\n Agility : " << this->getAgility()
             << "\n Intelligence : " << this->getIntelligence()
             << "\n Strength : " << this->getStrength()
             // << " \nMana : " << this->getMana()
             << "\n Max HP : " << this->hp
             << "\n Current HP : " << this->getHp()
             << "\n Stuff : " << this->getStuff()->getName() << ", with a power of " << this->getStuff()->getFeature()
             << endl;
    }

    // =================================================
    // Private Methods
    // =================================================

    /**
     * @brief Dizzy the other hero
     * @param _hero The other hero
     */
    void Wizard::dizzySpell(Hero *_hero) const
    {
        // The third of the magic wand's power, multiplied by the ratio of intelligence
        int reduction = (this->pStuff->getFeature() / 3.0) * this->getIntelligenceRatio();
        int fromAgility = _hero->getAgility();

        _hero->updateAgility(-reduction);

        if (Wizard::VJ_DEBUG_LOG)
        {
            cout << " Magic Wand's power : " << this->pStuff->getFeature() << endl
                 << " Strength : " << this->getStrength() << endl
                 << " Reduction : " << reduction << endl;
        }

        cout << " " << _hero->getName() << " has been stunned, and its agility has been reduced from " << Color::lightPurple(fromAgility) << " to " << Color::lightPurple(_hero->getAgility()) << endl;
    }

    /**
     * @brief Create a giant wave
     * @param _hero The other hero
     */
    void Wizard::giantWave(Hero *_hero) const
    {
        RandomGenerator random;

        // The double of magic wand's power, multiplied by the ratio of agility
        double wizardDamage = (this->pStuff->getFeature() * 2) * this->getAgilityRatio();
        double damage = random.getRandomDouble(max(wizardDamage - 3, 1.0), wizardDamage + 3, 1);

        _hero->updateHp(-damage);

        cout << " A giant wave arrives !" << endl
             << " " << _hero->getName() << " lost " << fixed << setprecision(1) << Color::lightRed(damage) << " HP" << endl;
    }
}