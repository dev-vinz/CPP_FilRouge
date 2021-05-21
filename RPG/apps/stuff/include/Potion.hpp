#ifndef POTION_HPP
#define POTION_HPP

#include "IObject.hpp"

namespace HE_Arc::RPG
{
    enum Type
    {
        Agility = 0,
        Heal = 1,
        Strength = 2
    };

    class Potion : public IObject
    {
    private:
        int power = 0;
        Type utility = Heal;

        string enumToStr[3] = {"Agility", "Heal", "Strength"};

    public:
        Potion() = default;
        Potion(int _power, Type _utility);
        Potion(const Potion &);
        virtual ~Potion() override = default;

        int getFeature() const override;
        Type getUtility() const;

        string getName() const override;
    };
}

#endif