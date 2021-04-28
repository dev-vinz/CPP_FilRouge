#ifndef POTION_HPP
#define POTION_HPP

#include "IObject.hpp"

namespace HE_Arc::RPG
{
    class Potion : public IObject
    {
    private:
        int power = 0;

    public:
        Potion() = default;
        Potion(int _power);
        Potion(const Potion &);

        int getFeature() const override;

        string getName() const override;
    };
}

#endif