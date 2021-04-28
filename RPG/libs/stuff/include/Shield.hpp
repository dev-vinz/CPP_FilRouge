#ifndef SHIELD_HPP
#define SHIELD_HPP

#include "IObject.hpp"

namespace HE_Arc::RPG
{
    class Shield : public IObject
    {
    private:
        int solidity = 0;

    public:
        Shield() = default;
        Shield(int _solidity);
        Shield(const Shield &);

        int getFeature() const override;

        string getName() const override;
    };
}

#endif