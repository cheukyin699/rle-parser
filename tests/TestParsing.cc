#include "gtest/gtest.h"
#include "Parser.h"
#include "Config.h"

#define FN_CONCAT(a, b) (a b)

TEST(TestParsing, ParseNormalFile) {
    rle::Board b = rle::parse(FN_CONCAT(SRCDIR, "examples/normal1.rle"));

    // Meta-data testing
    ASSERT_EQ(b.getName(), "Gosper glider gun");
    ASSERT_EQ(b.getW(), 36);
    ASSERT_EQ(b.getH(), 9);
    ASSERT_EQ(b.getRule(), "B3/S23");
}
