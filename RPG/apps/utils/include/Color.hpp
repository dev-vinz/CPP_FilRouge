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

    template <typename T>
    class ColorItem
    {
    private:
        T thing;
        string color;

        template <typename U>
        friend ostream &operator<<(ostream &, const ColorItem<U> &);

    public:
        ColorItem(T _t, string _color) : thing(_t), color(_color) {}
    };

    template <typename T>
    ostream &operator<<(ostream &_os, const ColorItem<T> &_ci)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_CODES.at(_ci.color));

        _os << _ci.thing;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT_COLOR);

        return _os;
    }

    namespace Color
    {
        template <typename T> ColorItem<T> black(T _t)          { return ColorItem<T>(_t, "black");          }
        template <typename T> ColorItem<T> blue(T _t)           { return ColorItem<T>(_t, "blue");           }
        template <typename T> ColorItem<T> green(T _t)          { return ColorItem<T>(_t, "green");          }
        template <typename T> ColorItem<T> aqua(T _t)           { return ColorItem<T>(_t, "aqua");           }
        template <typename T> ColorItem<T> red(T _t)            { return ColorItem<T>(_t, "red");            }
        template <typename T> ColorItem<T> purple(T _t)         { return ColorItem<T>(_t, "purple");         }
        template <typename T> ColorItem<T> yellow(T _t)         { return ColorItem<T>(_t, "yellow");         }
        template <typename T> ColorItem<T> white(T _t)          { return ColorItem<T>(_t, "white");          }
        template <typename T> ColorItem<T> grey(T _t)           { return ColorItem<T>(_t, "grey");           }
        template <typename T> ColorItem<T> lightBlue(T _t)      { return ColorItem<T>(_t, "light blue");     }
        template <typename T> ColorItem<T> lightGreen(T _t)     { return ColorItem<T>(_t, "light green");    }
        template <typename T> ColorItem<T> lightAqua(T _t)      { return ColorItem<T>(_t, "light aqua");     }
        template <typename T> ColorItem<T> lightRed(T _t)       { return ColorItem<T>(_t, "light red");      }
        template <typename T> ColorItem<T> lightPurple(T _t)    { return ColorItem<T>(_t, "light purple");   }
        template <typename T> ColorItem<T> lightYellow(T _t)    { return ColorItem<T>(_t, "yellow light");   }
        template <typename T> ColorItem<T> brightWhite(T _t)    { return ColorItem<T>(_t, "bright white");   }
    }
}

#endif