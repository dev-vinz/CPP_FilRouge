#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

using namespace std;

namespace HE_Arc::RPG
{
    enum class Character
    {
        eWarrior = '1',
        eWizard = '2',
        eNecromancer = '3',

        eInferi = 0,
        eVampire = 1,
        eMedusa = 2
    };
}

#endif