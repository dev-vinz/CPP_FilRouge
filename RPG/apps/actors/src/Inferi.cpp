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
    void Inferi::interact(Hero *_otherHero, char _attack)
    {
        cout << "Hello everyone, I'm happy" << endl;
    }
}