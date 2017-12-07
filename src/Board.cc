#include "Board.h"

#include <string>

using namespace rle;
using namespace std;

Board::Board(unsigned width, unsigned height, string n, string c)
    : w(width), h(height), name(n), comments(c) {
        populate();
}

void Board::populate() {
    for (unsigned y = 0; y < h; ++y) {
        b.push_back(bitstring(w, false));
    }
}

string Board::getBoard() {
    string output;
    // Extra due to new line at the ends
    output.reserve(getH() * getW() + getH());

    for (unsigned y = 0; y < getH(); y++) {
        for (unsigned x = 0; x < getW(); x++) {
            output.append(1, get(x, y)? 'X': ' ');
        }
        output.append(1, '\n');
    }

    return output;
}
