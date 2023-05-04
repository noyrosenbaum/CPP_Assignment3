#include <iostream>
#include <stdio.h>
#include "Fraction.hpp"

using namespace std;

using namespace ariel;

Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    denominator != 0 ? this->denominator = denominator : throw "Initialize 0 in denominator is an illegal action";
}

Fraction::Fraction(float num)
{
    this->numerator = int(num);
    this->denominator = 1;
}
int Fraction::getNum() const
{
    return numerator;
}
int Fraction::getDeno() const
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
const Fraction Fraction::operator+(const Fraction &other) const
{

    return Fraction(1, 1);
}
Fraction Fraction::operator+(const float &num) const
{
    return Fraction(1, 1);
}
Fraction operator+(const float &num, const Fraction &other)
{

    return Fraction(1, 1);
}
const Fraction Fraction::operator-(const Fraction &other) const
{

    return Fraction(1, 1);
}

Fraction operator-(const float &num, const Fraction &other)
{

    return Fraction(1, 1);
}
Fraction Fraction::operator-(const float &num) const
{
    return Fraction(1, 1);
}

const Fraction Fraction::operator/(const Fraction &other) const
{

    return Fraction(1, 1);
}
Fraction Fraction::operator/(const float &num) const
{
    return Fraction(1, 1);
}
Fraction operator/(const float &num, const Fraction &other)
{

    return Fraction(1, 1);
}

const Fraction Fraction::operator*(const Fraction &other) const
{

    return Fraction(1, 1);
}
Fraction Fraction::operator*(const float &num) const
{
    return Fraction(1, 1);
}
Fraction operator*(const float &num, const Fraction &other)
{

    return Fraction(1, 1);
}

bool operator==(const float &num, const Fraction &other)
{

    return true;
}
bool Fraction::operator==(const Fraction &other) const
{
    return true;
}
bool Fraction::operator==(const float &num) const
{

    return true;
}
bool operator>(const float &num, const Fraction &other)
{

    return true;
}
bool Fraction::operator>(const Fraction &other) const
{
    return true;
}
bool Fraction::operator>(const float &num) const
{

    return true;
}

bool operator<(const float &num, const Fraction &other)
{

    return true;
}
bool Fraction::operator<(const Fraction &other) const
{
    return true;
}
bool Fraction::operator<(const float &num) const
{

    return true;
}

bool operator>=(const float &num, const Fraction &other)
{

    return true;
}
bool Fraction::operator>=(const Fraction &other) const
{
    return true;
}
bool Fraction::operator>=(const float &num) const
{

    return true;
}

bool operator<=(const float &num, const Fraction &other)
{

    return true;
}
bool Fraction::operator<=(const Fraction &other) const
{
    return true;
}
bool Fraction::operator<=(const float &num) const
{

    return true;
}

Fraction &Fraction::operator++()
{

    return *this;
}

Fraction Fraction::operator++(int)
{

    return Fraction(1, 1);
}

Fraction &Fraction::operator--()
{

    return *this;
}

Fraction Fraction::operator--(int)
{

    return Fraction(1, 1);
}

istream &operator>>(istream &cin, Fraction &other)
{

    return cin;
}

ostream &operator<<(ostream &cout, const Fraction &other)
{

    return cout;
}