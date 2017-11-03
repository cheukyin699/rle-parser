#include "Board.h"

using namespace rle;

Board::Board(unsigned width, unsigned height, string n)
    : w(width), h(height), name(n) {
        for (unsigned y = 0; y < height; ++y) {
            b.push_back(bitstring(w));
        }
}
