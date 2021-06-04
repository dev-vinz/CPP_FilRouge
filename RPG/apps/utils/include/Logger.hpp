#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <windows.h>

#include <sys/stat.h>
#include <iomanip>

using namespace std;

namespace HE_Arc::RPG
{
    enum LoggerWho
    {
        LPlayer,
        LOpponent
    };

    class Logger
    {
    private:
        static bool isOk;
        static int nbBattles;

        const string DIR_LOG = "logs";
        static string pathBin;

        static string pathRoot;
        static string pathBattles;
        static string pathMovements;

        static string battleLogName;

        static bool exists(string _fullPath);

        static void createFile(string _path, string _fileName);
        static void writeLog(string _fullPath, string _nameFile, string _log);

    public:
        Logger();

        static bool isInitialized();
        static void writeBattle(string _log, string _fileName = "");
        static void writeGame(string);
        static void writeMovements(string _log, LoggerWho _who = LOpponent);
        static void writeObjects(string);
    };
}

#endif