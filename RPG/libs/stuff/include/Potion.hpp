#ifndef POTION_HPP
#define POTION_HPP

#include "IObject.hpp"

namespace HE_Arc::RPG
{
    class Potion : public IObject
    {
    private:
        // Atributes
        int power = 0;

    public:
        // Constructors and Destructor
        Potion() = default;
        Potion(int _power);
        Potion(const Potion &);

        // Override int methods of Interface
        int getFeature() const override;

        // Override string methods of Interface
        string getName() const override;
    };
}

#endif