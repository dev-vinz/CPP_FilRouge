#ifndef CONSOLE_CONTROLLER_HPP
#define CONSOLE_CONTROLLER_HPP

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <unistd.h>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

namespace HE_Arc::RPG
{
    class ConsoleController
    {
    private:
        static const bool VJ_DISPLAY_LOADING = true;

    public:
        /**
        * @brief Checks the input
        * @ref https://stackoverflow.com/questions/19215027/check-if-element-found-in-array-c
        * @param _array The array of valid inputs
        * @param _char The char to check
        * @returns True if it's correct
        */
        template <typename A, typename V>
        static bool checkInput(A &&_array, V _value)
        {
            return find(begin(_array), end(_array), _value) != end(_array);
        }

        static string getCenter(string _text, int _length, char _decoration = ' ');

        static void displayLoading(string _text, unsigned int _duration);
    };
}

#endif