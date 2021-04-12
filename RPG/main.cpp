#include <iostream>

#include "libs\actors\include\Hero.hpp"
#include "libs\actors\include\Necromancer.hpp"
#include "libs\actors\include\Warrior.hpp"
#include "libs\actors\include\Wizard.hpp"
// https://medium.com/swlh/c-project-structure-for-cmake-67d60135f6f5

using namespace std;
using namespace HE_Arc::RPG;

int main()
{
    Wizard myHeroOne(7, 8, 10, 150, "Voldemort", 10);
    Warrior myHeroTwo(10, 2, 0, 200, "Garrosh");
    Necromancer myHeroThree(6, 6, 10, 100, "Gul'dan", 8);
    Wizard myHeroFour;

    myHeroOne.show();
    cout << myHeroTwo << endl;
    myHeroThree.show();
    cout << myHeroFour << endl;

    cout << endl;

    myHeroOne.castSpell();
    myHeroTwo.interact(myHeroOne);
    myHeroThree.riseUndead();

    return 0;
}