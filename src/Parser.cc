#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>

#include "Utils.h"
#include "Parser.h"

using namespace std;
using namespace rle;

Board rle::parse(const char* fn) {
    ifstream f(fn);
    if (f.good()) {
        Board b = Board(0, 0, "unknown", "");
        string line;
        bool dimensionsGotten = false;
        bool forcedEOF = false;
		unsigned xpos = 0;
		unsigned ypos = 0;
        while (getline(f, line) && !forcedEOF) {
            // Remove empty lines
            if (line.empty()) continue;

            if (line[0] == '#') {
                // Line is a comment
                parseComment(b, line.substr(1, line.npos));
            } else if (!dimensionsGotten) {
                // Line is a dimension
                // Match with regex
                parseDimension(b, line);
                b.populate();
                dimensionsGotten = true;
            } else {
                // Line is the contents
				forcedEOF = parseLine(b, line, xpos, ypos);
            }
        }
        return b;
    } else {
        cerr << "Error: file not found" << endl;
        throw 0;
    }
}

bool rle::parseLine(Board& b, string line, unsigned& xpos, unsigned& ypos) {
	string quantity = "";
	for (auto c : line) {
		if (isdigit(c)) {
			quantity += c;
		} else if (c == 'b' || c == 'o') {
			// TODO Dead cell or Alive cell
			bool isAlive = c == 'o';
			unsigned amount = quantity.empty()? 1 : stoi(quantity);
			quantity = "";
			for (unsigned i = 0; i < amount; ++i) {
				b.set(xpos + i, ypos, isAlive);
			}
			xpos += amount;
		} else if (c == '$') {
			// End of line
			ypos++;
			xpos = 0;
		} else if (c == '!') {
			// End of file
			return true;
		} else {
			// TODO Handle other characters
		}
	}
	return false;
}

void rle::parseComment(Board& b, string line) {
	switch (line[0]) {
		case 'N':
			// Name of pattern
			b.setName(trim(line.substr(1, line.npos)));
			break;
		case 'O':
			// Says when and whom the file was created, usually produced by
			// XLife
			break;
		case 'c':
			// Indicates comment, but not recommended. Same as 'C'.
			cerr << "Warning: using 'c' for comments is not recommended." << endl;
		case 'C':
			// Indicates that a line of comment follows. A really common use
			// of # lines
			break;
		case 'P':
			// Same as R, produced by Life32, representing the top-left
			// corner of the pattern
		case 'R':
			// Gives coordinates of the top-left corner of pattern, usually
			// negative, with the intention of placing the center of the
			// pattern at the point of origin.
			break;
		case 'r':
			// Gives the rules for a pattern in the form of
			// '<survive>/<birth>' (e.g. 23/3 for Life). Usually present for
			// files created by XLife. Standard method is not in comments.
			break;
		default:
			cerr << "Warning: irregular comment: " << line << endl;
			break;
	}
}

void rle::parseDimension(Board& b, string line) {
	// Remove all spaces from line
	line.erase(remove(line.begin(), line.end(), ' '),
			line.end());
	// Iterate through every comma
	smatch m;
	int i;
	int curr = 0;
	do {
		i = line.find(',', curr);
		string s = i != line.npos ? line.substr(curr, i - curr) : line.substr(curr);

		if (regex_match(s, m, OBJEQ)) {
			if (m[1] == "x") {
				b.setW(stoi(m[2]));
			} else if (m[1] == "y") {
				b.setH(stoi(m[2]));
			} else if (m[1] == "rule") {
				b.setRule(m[2]);
			} else {
				throw std::runtime_error("Unknown dimension: " + s);
			}
		} else {
			throw std::runtime_error("Invalid formatting: " + s);
		}

		curr = i + 1;
	} while (i != line.npos);
}
