#include <iostream>

#include "Headers/Hero.hpp"

using namespace std;
using namespace HE_Arc::RPG;

int main()
{
    Hero myHeroOne(10, 5, 1, 20, "Voldemort");
    Hero myHeroTwo(2, 2, 10, 10, "Gandalf");
    Hero myHeroThree;

    cout << myHeroOne << endl;
    myHeroTwo.show();
    cout << myHeroThree << endl;

    cout << endl;

    myHeroTwo.interact(myHeroOne);

    return 0;
}