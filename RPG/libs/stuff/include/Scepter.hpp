#ifndef SCEPTER_HPP
#define SCEPTER_HPP

#include "IObject.hpp"

namespace HE_Arc::RPG
{
    class Scepter : public IObject
    {
    private:
        int power = 0;

    public:
        Scepter() = default;
        Scepter(int _power);
        Scepter(const Scepter &);
        virtual ~Scepter() = default;

        int getFeature() const override;

        string getName() const override;
    };
}

#endif