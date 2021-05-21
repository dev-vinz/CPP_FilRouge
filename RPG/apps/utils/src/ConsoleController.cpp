#include "..\include\ConsoleController.hpp"

namespace HE_Arc::RPG
{
    /**
     * @brief Get a text in the center
     * @param _text The text to print
     * @param _length The length authorized
     * @param _decoration The decoration - Per default a space
     */
    string ConsoleController::getCenter(string _text, int _length, char _decoration)
    {
        int lenText = _text.size() + 2; // 2 for counting spaces

        if (lenText >= _length)
            return _text;

        int nbDecoration = (_length - lenText) / 2;

        string myResult = "";

        for (int k = 0; k < nbDecoration; k++)
        {
            myResult += _decoration;
        }

        myResult += " " + _text + " ";

        for (int k = myResult.size(); k < _length - 1; k++)
        {
            myResult += _decoration;
        }

        return myResult;
    }
}