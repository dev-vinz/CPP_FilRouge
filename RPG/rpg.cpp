#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <stdlib.h>

#include "apps\game\include\Game.hpp"
#include "apps\game\include\Help.hpp"

#include "apps\utils\include\Logger.hpp"

using namespace std;
using namespace HE_Arc::RPG;

//* https://stackoverflow.com/questions/32203610/how-to-integrate-uml-diagrams-into-gitlab-or-github

int main(int argc, char *argv[])
{
    if (argc <= 1)
        return displayInfo();

    string command = argv[1];

    if (command == "--info")
        return displayInfo();

    if (command != "--start")
        return displayError(command);

    Logger myLog;

    ConsoleController::displayLoading("Here we go !", 5);

    Game myGame(10, 9, 3);

    string name;
    cout << " What's your name ? " << endl
         << " >>> ";

    getline(cin, name);

    myGame.choosePlayer(name);
    myGame.initialize();

    myGame.play();

    myGame.end();

    return 0;
}