// By: Gonçalo Leão

#include "exercises.h"

double bisection(double x1, double x2, double err, double(*f)(double)) {
    // TODO
    return 0.0;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex5, testBisection) {
    ASSERT_NEAR(bisection(-2, 2, 0.0001, [](double x){return x;}), 0.0, 0.00001);
    ASSERT_NEAR(bisection(0, 2, 0.0001, [](double x){return cos(x);}), 1.57080078125, 0.00001);
}