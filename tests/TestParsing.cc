#include "attounit.h"
#include "Parser.h"
#include "Config.h"

#include <iostream>

using namespace std;

TEST_SUITE(Parsing);

BEFORE_EACH() {}
AFTER_EACH() {}

TEST_CASE(parses_file) {
    rle::Board b = rle::parse(SRCDIR "examples/normal1.rle");

    // Meta-data testing
    ASSERT_EQUAL(b.getName(), "Gosper glider gun");
    ASSERT_EQUAL(b.getW(), 36);
    ASSERT_EQUAL(b.getH(), 9);
    ASSERT_EQUAL(b.getRule(), "B3/S23");
    // Actual data testing
    const string CORRECT =
"                        X           \n"
"                      X X           \n"
"            XX      XX            XX\n"
"           X   X    XX            XX\n"
"XX        X     X   XX              \n"
"XX        X   X XX    X X           \n"
"          X     X       X           \n"
"           X   X                    \n"
"            XX                      \n";
    ASSERT_EQUAL(b.getBoard(), CORRECT);
}
