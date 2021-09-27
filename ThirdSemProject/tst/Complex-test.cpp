#include <cmath>
#include "gtest/gtest.h"
#include "../include/Complex.h"


TEST(Complex, plusOperator) {
    EXPECT_EQ(Complex(1, 2) + Complex(0, 1), Complex(1, 3));
    EXPECT_EQ(Complex(0, 0) + Complex(0, 0), Complex(0, 0));
    EXPECT_EQ(Complex(1, -4) + Complex(1, 4), Complex(2, 0));
    EXPECT_EQ(Complex(1, 2) + Complex(-1, 2), Complex(0, 4));
}

TEST(Complex, minusOperator) {
    EXPECT_EQ(Complex(2, 2) - Complex(1, 2), Complex(1, 0));
    EXPECT_EQ(Complex(3, 4) - Complex(4, 3), Complex(-1, 1));
    EXPECT_EQ(Complex(1, 1) - Complex(0, 0), Complex(1, 1));
    EXPECT_EQ(Complex(0, 0) - Complex(0, 0), Complex(0, 0));
}

TEST(Complex, divOperator) {
    EXPECT_EQ(Complex(2, 2) / Complex(3, 1), Complex(0.8, 0.4));
    EXPECT_EQ(Complex(3, 5) / Complex(6, 10), Complex(0.5, 0));
}

TEST(Complex, mulOperator) {
    EXPECT_EQ(Complex(3, 5) * Complex(6, 10), Complex(-32, 60));
    EXPECT_EQ(Complex(0, 5) * Complex(4, 9), Complex(-45, 20));
    EXPECT_EQ(Complex(2, 0) * Complex(5, 0), Complex(10, 0));
}

TEST(Complex, getMod) {
    EXPECT_EQ(Complex(3, 4).getMod(), 5);
    EXPECT_EQ(Complex(5, 12).getMod(), 13);
}

TEST(Complex, getArg) {
    EXPECT_EQ(Complex(0, 4).getArg(), M_PI / 2);
    EXPECT_EQ(Complex(4, 0).getArg(), 0);
    EXPECT_EQ(Complex(2, 2).getArg(), M_PI / 4);
}
