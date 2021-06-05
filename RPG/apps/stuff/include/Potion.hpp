#ifndef POTION_HPP
#define POTION_HPP

#include <map>

#include "IObject.hpp"

#include "..\..\enums\TypePotion.hpp"

namespace HE_Arc::RPG
{
    class Potion : public IObject
    {
    private:
        int power = 0;
        TypePotion utility = TypePotion::Heal;

        map<char, string> enumToStr = {
            {'a', "Agility"},
            {'h', "Heal"},
            {'s', "Strength"}
        };

    public:
        Potion() = default;
        Potion(int _power, TypePotion _utility);
        Potion(const Potion &);
        virtual ~Potion() override = default;

        int getFeature() const override;
        TypePotion getUtility() const;

        string getName() const override;
    };
}

#endif