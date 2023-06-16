#include "gtest/gtest.h"

long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

TEST(LoadTest, SimpleFunctionTest) {
    EXPECT_EQ(factorial(1), 1);
    EXPECT_EQ(factorial(4), 24);
    EXPECT_EQ(factorial(10), 3628800);
}