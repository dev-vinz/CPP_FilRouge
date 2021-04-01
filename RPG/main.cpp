#include <iostream>

#include "libs\actors\include\Hero.hpp"
// https://medium.com/swlh/c-project-structure-for-cmake-67d60135f6f5

using namespace std;
using namespace HE_Arc::RPG;

int main()
{
    Hero myHeroOne = Hero(10, 5, 1, 20, "Voldemort", new Sword());
    Hero myHeroTwo(2, 2, 10, 10, "Gandalf", new Sword());
    Hero myHeroThree;

    cout << myHeroOne << endl;
    myHeroTwo.show();
    cout << myHeroThree << endl;

    cout << endl;

    myHeroTwo.interact(myHeroOne);

    return 0;
}