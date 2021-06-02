#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>
#include <map>
#include <windows.h>

using namespace std;

namespace HE_Arc::RPG
{
    constexpr int DEFAULT_COLOR = 7;
    const map<string, int> COLOR_CODES = {
        {"black",            0},
        {"blue",             1},
        {"green",            2},
        {"aqua",             3},
        {"red",              4},
        {"purple",           5},
        {"yellow",           6},
        {"white",            7},
        {"grey",             8},
        {"light blue",       9},
        {"light green",     10},
        {"light aqua",      11},
        {"light red",       12},
        {"light purple",    13},
        {"light yellow",    14},
        {"bright white",    15}
    };

    class Color
    {
    private:
        string text;
        string color;
        int number;

        Color() = delete;
        Color(string _t, string _color) :   text(_t), color(_color), number(0)      {}
        Color(int _n, string _color) :      text(""), color(_color), number(_n)     {}

        friend ostream &operator<<(ostream &_os, const Color &_c)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_CODES.at(_c.color));

            if (_c.text != "")
            {
                _os << _c.text;
            }
            else
            {
                _os << _c.number;
            }

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT_COLOR);

            return _os;
        }

    public:
        static Color grey(string _t)                { return Color(_t, "grey");        }
        static Color grey(int _n)                   { return Color(_n, "grey");        }
        static Color lightGreen(string _t)          { return Color(_t, "light green"); }
        static Color lightGreen(int _n)             { return Color(_n, "light green"); }
        static Color lightRed(string _t)            { return Color(_t, "light red");   }
        static Color lightRed(int _n)               { return Color(_n, "light red");   }
        static Color lightPurple(string _t)         { return Color(_t, "light purple");}
        static Color lightPurple(int _n)            { return Color(_n, "light purple");}
        static Color lightYellow(string _t)         { return Color(_t, "light yellow");}
        static Color lightYellow(int _n)            { return Color(_n, "light yellow");}
    };
}

#endif