#ifndef SWORD_HPP
#define SWORD_HPP

#include "IObject.hpp"

namespace HE_Arc::RPG
{
    class Sword : public IObject
    {
    private:
        // Atributes
        int damage = 0;

    public:
        // Constructors and Destructor
        Sword() = default;
        Sword(int _damage);
        Sword(const Sword &);

        // Override int methods of Interface
        int getFeature() const override;

        // Override string methods of Interface
        string getName() const override;
    };
}

#endif