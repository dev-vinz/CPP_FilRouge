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

    /**
     * @brief Display a loading screen
     * @param _text The text to show
     * @param _duration The duration in seconds
     */
    void ConsoleController::displayLoading(string _text, unsigned int _duration)
    {
        char waiting[] = {'/', '-', '\\', '|'};
        int nbLoop = _duration * 5;

        cout << endl;

        for (int t = nbLoop; t > 0; t--)
        {
            usleep(200000);
            cout << "\r  " << waiting[t % 4] << " " << _text << " ...\r";
        }

        system("CLS");
    }
}