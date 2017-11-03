#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>

using namespace std;

typedef vector<bool> bitstring;

namespace rle {
    class Board {
        private:
            unsigned w;
            unsigned h;
            string name;
            string rule;
            vector<bitstring> b;

        public:
            Board(unsigned, unsigned, string);

            unsigned getW() {return w;};
            unsigned getH() {return h;};
            string getName() {return name;};
            string getRule() {return rule;};
            void setW(unsigned x) {w = x;};
            void setH(unsigned y) {h = y;};
            void setName(string n) {name = n;};
            void setRule(string r) {rule = r;};

            void set(unsigned i, unsigned j, bool x) {b[j][i] = x;};
            bool get(unsigned i, unsigned j) {return b[j][i];};
    };
}

#endif
