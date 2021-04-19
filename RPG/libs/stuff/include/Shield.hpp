#ifndef SHIELD_HPP
#define SHIELD_HPP

#include "IObject.hpp"

namespace HE_Arc::RPG
{
    class Shield : public IObject
    {
    private:
        // Atributes
        int solidity = 0;

    public:
        // Constructors and Destructor
        Shield() = default;
        Shield(int _solidity);
        Shield(const Shield &);

        // Override int methods of Interface
        int getFeature() const override;

        // Override string methods of Interface
        string getName() const override;
    };
}

#endif