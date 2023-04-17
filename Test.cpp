#include "doctest.h"
#include <iostream>
#include "./sources/Fraction.hpp"
using namespace ariel;

TEST_CASE("Initialize a fraction object")
{
    SUBCASE("Fraction with zero")
    {
        CHECK_NOTHROW(Fraction(0, 2)); // zero in num
        CHECK_THROWS(Fraction(2, 0));  // zero in deno
        CHECK_NOTHROW(Fraction(0));
    }
    SUBCASE("Fraction with integer")
    {
        CHECK_NOTHROW(Fraction(1.4));   // Random float number
        CHECK_NOTHROW(Fraction(1, 4));  // Frac that is reduced
        CHECK_NOTHROW(Fraction(4, 2));  // Num is bigger than deno - int result
        CHECK_NOTHROW(Fraction(4, 3));  // Num is bigger than deno - float result
        CHECK_NOTHROW(Fraction(-1, 1)); // Negative int in num
        CHECK_NOTHROW(Fraction(1, -1)); // Negative int in deno
        CHECK_THROWS(Fraction('a'));    // Not an integer
    }

    // Fraction zeroFl(0); // 0 as a float fraction
    // Fraction fracNoReduce(1, 4); // Frac that is reduced
    // Fraction fracWithReduce(2, 4); // Frac that is not reduced
}
TEST_CASE("Reduce functionality")
{
    Fraction reduced1 = reduce(Fraction(2, 4));
    Fraction reduced2 = reduce(Fraction(1.5));
    CHECK_EQ(reduced1.getFraction(), Fraction(1, 2).getFraction());
    CHECK_NE(reduced1.getFraction(), Fraction(2, 3).getFraction());
    CHECK_EQ(reduced2.getFraction(), Fraction(3, 2).getFraction());
}
TEST_CASE("Overload operators")
{
    SUBCASE("Addition")
    {
    }
    SUBCASE("Subtraction")
    {
    }
    SUBCASE("Devision")
    {
    }
    SUBCASE("Multipication")
    {
    }
    SUBCASE("Comparissions")
    {
    }
    SUBCASE("Unary operations by 1")
    {
    }
    SUBCASE("Streams")
    {
    }
}
