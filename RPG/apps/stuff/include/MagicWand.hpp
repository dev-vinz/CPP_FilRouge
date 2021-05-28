#ifndef MAGIC_WAND_HPP
#define MAGIC_WAND_HPP

#include "IObject.hpp"

namespace HE_Arc::RPG
{
    class MagicWand : public IObject
    {
    private:
        int power = 0;

    public:
        MagicWand() = default;
        MagicWand(int _power);
        MagicWand(const MagicWand &);
        virtual ~MagicWand() = default;

        int getFeature() const override;

        string getName() const override;
    };
}

#endif