#include <algorithm>
#include <iostream>
#include <list>

#include "apps\actors\include\Hero.hpp"
#include "apps\actors\include\Necromancer.hpp"
#include "apps\actors\include\Warrior.hpp"
#include "apps\actors\include\Wizard.hpp"

#include "apps\stuff\include\Potion.hpp"
#include "apps\stuff\include\Shield.hpp"
#include "apps\stuff\include\Sword.hpp"
// https://medium.com/swlh/c-project-structure-for-cmake-67d60135f6f5

using namespace std;
using namespace HE_Arc::RPG;

int oldMain()
{
    Wizard *myHeroOne = new Wizard("Voldemort", 7, 10, 8, 10, 150, new Potion(900, Strength));
    Warrior *myHeroTwo = new Warrior("Garrosh", 2, 0, 10, 200, new Shield(500));
    Necromancer *myHeroThree = new Necromancer("Gul'dan", 6, 10, 6, 8, 100, new Potion());
    Wizard *myHeroFour = new Wizard("Harry Potter", 10, 10, 10, 100, 5, new Potion(100, Agility));
    Warrior *myHeroFive = new Warrior("Arès", 100, 100, 100, 1000, new Sword(10000));

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

    myHeroOne->castSpell(myHeroTwo);
    myHeroTwo->interact(myHeroOne, Attack::AOne);
    myHeroThree->riseUndead(myHeroThree);

    cout << endl;

    myHeroFive->backPack.pack(new Sword());
    myHeroFive->backPack.pack(new Sword(1));
    myHeroFive->backPack.pack(new Sword(2));
    myHeroFive->backPack.pack(new Shield(3));
    myHeroFive->backPack.pack(new Shield(4));
    myHeroFive->backPack.pack(new Potion(5, Heal));
    myHeroFive->backPack.pack(new Potion(6, Heal));

    while (myHeroFive->backPack.isNotEmpty())
    {
        IObject *myItem = myHeroFive->backPack.unPack();
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