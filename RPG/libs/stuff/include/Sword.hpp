#ifndef SWORD_HPP
#define SWORD_HPP

#include "IObject.hpp"

namespace HE_Arc::RPG
{
    class Sword : public IObject
    {
    private:
        int damage = 0;

    public:
        Sword() = default;
        Sword(int _damage);
        Sword(const Sword &);

        int getFeature() const override;

        string getName() const override;
    };
}

#endif