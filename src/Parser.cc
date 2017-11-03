#include "Utils.h"
#include "Parser.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;
using namespace rle;

Board rle::parse(const char* fn) {
    ifstream f(fn);
    if (f.good()) {
        Board b = Board(0, 0, "unknown");
        string line;
        bool dimensionsGotten = false;
        while (getline(f, line)) {
            // Remove empty lines
            if (line.empty()) continue;

            if (line[0] == '#') {
                // Line is a comment
                parseComment(b, line.substr(1, line.npos));
            } else if (!dimensionsGotten) {
                // Line is a dimension
                // Match with regex
                parseDimension(b, line);
                dimensionsGotten = true;
            } else {
                // Line is the contents
                // TODO
            }
        }
        return b;
    } else {
        cerr << "Error: file not found" << endl;
        throw 0;
    }
}

void rle::parseComment(Board& b, string line) {
    try {
        switch (line[0]) {
            case 'N':
                b.setName(rle::trim(line.substr(1, line.npos)));
                break;
            case 'O':
                break;
            default:
                break;
        }
    } catch (exception ex) {
        // TODO
    }
}

void rle::parseDimension(Board& b, string line) {
    // Remove all spaces from line
    line.erase(remove(line.begin(), line.end(), ' '),
               line.end());
    // Iterate through every comma
    smatch m;
    for (int i = line.find(',');
            i != line.npos;
            line.erase(0, i+1), i = line.find(',')) {
        string s = line.substr(0, i);

        if (regex_match(s, m, OBJEQ)) {
            if (m[1] == "x") {
                b.setW(stoi(m[2]));
            } else if (m[1] == "y") {
                b.setH(stoi(m[2]));
            } else {
                // TODO
            }
        } else {
            // TODO
        }
    }

    // If there is still something left (rule)
    if (!line.empty() && regex_match(line, m, OBJEQ)) {
        if (m[1] == "rule") {
            b.setRule(m[2]);
        } else {
            // TODO
        }
    } else {
        // TODO
    }
}
