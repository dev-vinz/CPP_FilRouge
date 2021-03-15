#include <iostream>

#include "Sources/Hero.cpp"

using namespace std;
using namespace HE_Arc::RPG;

int main()
{
    Hero myHeroOne(10, 5, 1, 20, "Gimli");
    Hero myHeroTwo(2, 2, 10, 10, "Gandalf");

    myHeroOne.show();
    myHeroTwo.show();

    cout << endl;

    myHeroTwo.interact(myHeroOne);

    return 0;
}