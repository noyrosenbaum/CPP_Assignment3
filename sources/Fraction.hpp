#pragma once

#include <string>

using namespace std;
namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int numerator, int denominator);
        int getNum();
        int getDeno();
        Fraction reduce(Fraction fraction);
        void setNum(int num);
        void setDeno(int deno);
    };
};