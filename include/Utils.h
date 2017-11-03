#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <regex>

using namespace std;

namespace rle {
    const regex EXCESS_WHITESPACE("^ +| +$|( ) +");
    string trim(string);
}

#endif
