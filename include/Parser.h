#ifndef PARSER_H
#define PARSER_H

#include "Board.h"
#include <string>
#include <regex>

using namespace std;

namespace rle {
    const regex OBJEQ("([[:alpha:]]+)=(.+)");

    Board parse(const char*);

    void parseComment(Board&, string);
    void parseDimension(Board&, string);
}

#endif
