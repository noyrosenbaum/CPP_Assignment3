#include "doctest.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "./sources/Fraction.hpp"
using namespace ariel;
using namespace std;

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
// TEST_CASE("Reduce functionality")
// {
//     Fraction reduced1 = Fraction(2, 4);
//     reduce(reduced1);
//     Fraction reduced2 = Fraction(3, 6);
//     reduce(reduced2);
//     CHECK_EQ(reduced1.getFraction(), Fraction(1, 2).getFraction());
//     CHECK_NE(reduced1.getFraction(), Fraction(2, 3).getFraction());
//     CHECK_EQ(reduced2.getFraction(), Fraction(1, 2).getFraction());
//     //     Fraction reduced1 = reduce(Fraction(2, 4));
//     //     Fraction reduced2 = reduce(Fraction(1.5));
//     //     CHECK_EQ(reduced1.getFraction(), Fraction(1, 2).getFraction());
//     //     CHECK_NE(reduced1.getFraction(), Fraction(2, 3).getFraction());
//     //     CHECK_EQ(reduced2.getFraction(), Fraction(3, 2).getFraction());
// }
TEST_CASE("Overload operators")
{
    Fraction f1(1, 4);
    Fraction f2(1, 2);
    Fraction f3(3, 4);
    Fraction f4(1, 4);
    Fraction f5(2, 4);
    float num = 1.25;
    SUBCASE("Addition")
    {
        CHECK_EQ(f1 + f2, f3);
        CHECK_EQ(f1 + f2, f2 + f1);
    }
    SUBCASE("Subtraction")
    {
        CHECK_EQ(f2 - f1, Fraction(1, 4));
        CHECK_THROWS(f2 - (Fraction(1, 0)));
    }
    SUBCASE("Devision")
    {
        CHECK_EQ(f2 / f1, Fraction(2, 1));
    }
    SUBCASE("Multipication")
    {
        CHECK_EQ(f1 * f2, Fraction(1, 8));
    }
    SUBCASE("Comparissions")
    {
        CHECK_EQ(f2, f5);
        CHECK_EQ(f1, f4);
        CHECK((f1 < f2) == true);
        CHECK((f1 > f2) == false);
    }
    SUBCASE("Unary operations by 1")
    {
        CHECK_EQ(++f1, Fraction(5, 4));
        CHECK_EQ(--f1, Fraction(1, 4));
    }
    SUBCASE("Streams")
    {
        ostringstream ss;
        istringstream is;
        ss << f1;
        CHECK_EQ(ss.str(), "1/4");

        is.str("3, 5");
        is >> f2;
        CHECK_EQ(f2.getFraction(), Fraction(3, 5).getFraction());
    }
}
