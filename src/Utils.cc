#include "Utils.h"
#include <string>
#include <regex>

using namespace std;

string rle::trim(string s) {
    return regex_replace(s, rle::EXCESS_WHITESPACE, "$1");
}
