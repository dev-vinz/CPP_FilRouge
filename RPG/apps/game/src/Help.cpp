#include "..\include\Help.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Display the error message
     * @param _parameter The parameter
     */
    int displayError(string _parameter)
    {
        cerr << "  " << Color::lightRed("ERROR") << " : Parameter " << Color::grey(_parameter) << " incorrect" << endl;

        cout << endl
             << "  Available parameters are :" << endl
             << "     > --info\t\tDisplay the information message" << endl
             << "     > --start\t\tStart the game" << endl;

        exit(0);
    }

    /**
     * @brief Display the welcome message
     */
    int displayInfo()
    {
        system("CLS");

        cout << endl
             << "     __      __       .__                               " << endl
             << "    /  \\    /  \\ ____ |  |   ____  ____   _____   ____  " << endl
             << "    \\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\ " << endl
             << "     \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/ " << endl
             << "      \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >" << endl
             << "           \\/       \\/          \\/            \\/     \\/ " << endl
             << endl
             << endl
             << endl
             << "\tHello, and welcome to this RPG game" << endl
             << endl
             << "  This game was made as part of the C++ course, and is my personal project." << endl
             << "  It's a RPG game, which means that it's a Role Playing Game." << endl
             << endl
             << "  First you will choose a type of player between three (3) possibilities." << endl
             << "  You can be either a Warrior, a Wizard or a Necromancer, with diffrent abilities." << endl
             << "  Then you will face different opponents who can be an Inferi, a Medusa or a Vampire." << endl
             << endl
             << "  You will evolute in a map, where you can move your player, and fight the opponents." << endl
             << "  You win the game when all opponents are defeated." << endl
             << endl
             << "  To start the game, please type : .\\rpg.exe --start" << endl
             << endl
             << "  (C) 2021 Vincent Jeannin, ISC1c" << endl;

        return 0;
    }
}