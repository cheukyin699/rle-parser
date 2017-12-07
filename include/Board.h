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
            string origin;
            string rule;
            string comments;
            vector<bitstring> b;

        public:
            Board(unsigned, unsigned, string, string);

            void populate();

            unsigned getW() {return w;};
            unsigned getH() {return h;};
            string getName() {return name;};
            string getRule() {return rule;};
            string getComments() {return comments;};
            string getOrigin() {return origin;};
            string getBoard();

            void set(unsigned i, unsigned j, bool x) {b.at(j).at(i) = x;};
            bool get(unsigned i, unsigned j) {return b.at(j).at(i);};
            void setW(unsigned x) {w = x;};
            void setH(unsigned y) {h = y;};
            void setName(string n) {name = n;};
            void setRule(string r) {rule = r;};
            void setComments(string c) {comments = c;};
            void setOrigin(string o) {origin = o;};
    };
}

#endif
