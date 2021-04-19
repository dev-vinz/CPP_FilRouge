#include <algorithm>
#include <iostream>
#include <list>

#include "libs\actors\include\Hero.hpp"
#include "libs\actors\include\Necromancer.hpp"
#include "libs\actors\include\Warrior.hpp"
#include "libs\actors\include\Wizard.hpp"

#include "libs\stuff\include\Potion.hpp"
#include "libs\stuff\include\Shield.hpp"
#include "libs\stuff\include\Sword.hpp"
// https://medium.com/swlh/c-project-structure-for-cmake-67d60135f6f5

using namespace std;
using namespace HE_Arc::RPG;

int main()
{
    Wizard *myHeroOne = new Wizard(7, 8, 10, 150, 10, "Voldemort", new Potion(900));
    Warrior *myHeroTwo = new Warrior(10, 2, 0, 200, "Garrosh", new Shield(500));
    Necromancer *myHeroThree = new Necromancer(6, 6, 10, 100, 8, "Gul'dan", new Potion());
    Wizard *myHeroFour = new Wizard(10, 10, 10, 100, 5, "Harry Potter", new Potion(100));
    Warrior *myHeroFive = new Warrior(100, 100, 100, 1000, "Arès", new Sword(10000));

    list<Hero *> myList;

    myList.push_back(myHeroOne);
    myList.push_back(myHeroTwo);
    myList.push_back(myHeroThree);
    myList.push_back(myHeroFour);
    myList.push_back(myHeroFive);

    for_each(myList.begin(), myList.end(), [](Hero *h) {
        h->show();
        cout << endl;
    });

    myHeroOne->castSpell();
    myHeroTwo->interact(*myHeroOne);
    myHeroThree->riseUndead();

    cout << endl;

    myHeroFive->backPack.pack(new Sword());
    myHeroFive->backPack.pack(new Sword(1));
    myHeroFive->backPack.pack(new Sword(2));
    myHeroFive->backPack.pack(new Shield(3));
    myHeroFive->backPack.pack(new Shield(4));
    myHeroFive->backPack.pack(new Potion(5));
    myHeroFive->backPack.pack(new Potion(6));

    for (int k = 0; k < 7; k++)
    {
        IObject* myItem = myHeroFive->backPack.unPack();
        cout << myItem->getName() << "\t" << myItem->getFeature() << endl;

        delete myItem;
        myItem = nullptr;
    }

    for_each(myList.begin(), myList.end(), [](Hero *h) {
        delete h;
        h = nullptr;
    });

    return 0;
}