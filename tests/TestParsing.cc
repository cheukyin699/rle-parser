#include "gtest/gtest.h"
#include "Parser.h"
#include "Config.h"

#include <iostream>

#define FN_CONCAT(a, b) (a b)

using namespace std;

TEST(TestParsing, ParseNormalFile) {
    rle::Board b = rle::parse(FN_CONCAT(SRCDIR, "examples/normal1.rle"));

    // Meta-data testing
    ASSERT_EQ(b.getName(), "Gosper glider gun");
    ASSERT_EQ(b.getW(), 36);
    ASSERT_EQ(b.getH(), 9);
    ASSERT_EQ(b.getRule(), "B3/S23");
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
    ASSERT_EQ(b.getBoard(), CORRECT);
}
