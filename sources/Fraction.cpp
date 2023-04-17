#include "Fraction.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;
namespace ariel
{
    Fraction::Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        denominator != 0 ? this->denominator = denominator : throw "Initialize 0 in denominator is an illegal action";
    }
    Fraction::Fraction(float num)
    {
        
    }
    int Fraction::getNum()
    {
        return numerator;
    }
    int Fraction::getDeno()
    {
        return denominator;
    }
    Fraction Fraction::getFraction()
    {
        return Fraction(this->getNum(), this->getDeno());
    }
    void Fraction::setNum(int num)
    {
        this->numerator = num;
    }
    void Fraction::setDeno(int deno)
    {
        this->denominator = deno;
    }
    void reduce(Fraction &frac)
    {
        int num = frac.getNum();
        int deno = frac.getDeno();
        // find GCD of these 2 numbers and keep devide them until you reach 1
        int result = min(num, deno); // Find Minimum of a and b
        while (result > 1)
        {
            if (num % result == 0 && deno % result == 0)
            {
                break;
            }
            result--;
        }
        num /= result;
        deno /= result;
        frac.setNum(num);
        frac.setDeno(deno);

    }
}