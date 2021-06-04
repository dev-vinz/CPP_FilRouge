#include "..\include\Player.hpp"

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
    Player::Player(string _name, int _agility, int _intelligence, int _strength, double _hp, IObject *_pStuff) : Hero(_name, _agility, _intelligence, _strength, _hp, _pStuff, true)
    {
    }

    /**
     * @brief Use the object
     * @param _object The object
     */
    void Player::useObject(IObject *_object)
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
                cout << "[ERROR : Player::useObject] Unknown potion" << endl;
                exit(-1);
            }

            Logger::writeObjects(this->getName() + " drunk a " + ptrPotion->getName() + " with power of " + to_string(ptrPotion->getFeature()));
        }
        else
        {
            cout << "[WARNING : Player::userObject()] : Object is not a potion" << endl;
        }
    }
}