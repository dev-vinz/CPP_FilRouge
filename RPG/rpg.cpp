#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <stdlib.h>

#include "libs\game\include\Game.hpp"

using namespace std;
using namespace HE_Arc::RPG;

/*
    === IDEAS ===

    1) Choose between 3 heroes at the start of the game
    2) Commands to control the hero, like status, attack, dodge, block etc
*/

int main()
{
    Game myGame(10, 9, 3);

    string name;
    cout << "What's your name ? " << endl
         << ">>> ";

    getline(cin, name);

    myGame.choosePlayer(name);
    myGame.initialize();

    myGame.play();

    return 0;
}