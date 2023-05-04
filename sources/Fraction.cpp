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
// // Copy constructor
// Fraction::Fraction(const Fraction &other)
// {
//     this->numerator = other.numerator;
//     this->denominator = other.denominator;
// }
Fraction::Fraction(float num)
{
    this->numerator = int(num);
    this->denominator = int(num);
    // int integer = static_cast<int>(floor(num));
    // int decimal = static_cast<int>(floor(num * 1000)) % 1000;
    // float a = integer + static_cast<float>(decimal) / 1000;
    // cout << fixed << setprecision(3);
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
    // int newNumerator = numerator * other.denominator + other.numerator * denominator;
    // int newDenominator = denominator * other.denominator;
    // Fraction result(newNumerator, newDenominator);
    // reduce(result);
    // return result;
    return Fraction(1, 1);
}
Fraction Fraction::operator+(const float &num) const
{
    return Fraction(1, 1);
}
Fraction operator+(const float &num, const Fraction &other)
{
    // Fraction temp(num);
    // return other + temp;
    return Fraction(1, 1);
}
const Fraction Fraction::operator-(const Fraction &other) const
{
    // int newNumerator = numerator * other.denominator - other.numerator * denominator;
    // int newDenominator = denominator * other.denominator;
    // Fraction result(newNumerator, newDenominator);
    // reduce(result);
    // return result;
    return Fraction(1, 1);
}

Fraction operator-(const float &num, const Fraction &other)
{
    // Fraction temp(num);
    // return other - temp;
    return Fraction(1, 1);
}
Fraction Fraction::operator-(const float &num) const
{
    return Fraction(1, 1);
}

const Fraction Fraction::operator/(const Fraction &other) const
{
    // int newNumerator = numerator * other.denominator;
    // int newDenominator = denominator * other.numerator;
    // Fraction result(newNumerator, newDenominator);
    // reduce(result);
    // return result;
    return Fraction(1, 1);
}
Fraction Fraction::operator/(const float &num) const
 {
    return Fraction(1, 1);
 }
Fraction operator/(const float &num, const Fraction &other)
{
    // Fraction temp(num);
    // return other / temp;
    return Fraction(1, 1);
}

const Fraction Fraction::operator*(const Fraction &other) const
{
    // int newNumerator = numerator * other.numerator;
    // int newDenominator = denominator * other.denominator;
    // Fraction result(newNumerator, newDenominator);
    // reduce(result);
    // return result;
    return Fraction(1, 1);
}
Fraction Fraction::operator*(const float &num)const
{
    return Fraction(1, 1);
}
Fraction operator*(const float &num, const Fraction &other)
{
    // Fraction temp(num);
    // return other * temp;
    return Fraction(1, 1);
}

bool operator==(const float &num, const Fraction &other)
{
    // Fraction temp(num);
    // return other == temp;
    return true;
}
bool Fraction::operator==(const Fraction& other) const 
{
    return true;
}
bool Fraction::operator==(const float &num) const
{
    // Fraction temp(num);
    // reduce(*this);
    // reduce(temp);
    // return (numerator == temp.numerator) && (denominator == temp.denominator);
    return true;
}
bool operator>(const float &num, const Fraction &other)
{
    // Fraction temp(num);
    // return other > temp;
    return true;
}
bool Fraction::operator>(const Fraction& other) const
{
    return true;
}
bool Fraction::operator>(const float &num) const
{
    // Fraction temp(num);
    // float f1 = static_cast<float>(numerator) / static_cast<float>(denominator);
    // float f2 = static_cast<float>(temp.numerator) / static_cast<float>(temp.denominator);
    // return f1 > f2;
    return true;
}

bool operator<(const float &num, const Fraction &other)
{
    // Fraction temp(num);
    // return other < temp;
    return true;
}
bool Fraction::operator<(const Fraction& other) const
{
    return true;
}
bool Fraction::operator<(const float &num) const
{
    // Fraction temp(num);
    // float f1 = static_cast<float>(numerator) / static_cast<float>(denominator);
    // float f2 = static_cast<float>(temp.numerator) / static_cast<float>(temp.denominator);
    // return f1 < f2;
    return true;
}

bool operator>=(const float &num, const Fraction &other)
{
    // Fraction temp(num);
    // return other >= temp;
    return true;
}
bool Fraction::operator>=(const Fraction& other) const
{
    return true;
}
bool Fraction::operator>=(const float &num) const
{
    // Fraction temp(num);
    // float f1 = static_cast<float>(numerator) / static_cast<float>(denominator);
    // float f2 = static_cast<float>(temp.numerator) / static_cast<float>(temp.denominator);
    // return f1 >= f2;
    return true;
}

bool operator<=(const float &num, const Fraction &other)
{
    // Fraction temp(num);
    // return other <= temp;
    return true;
}
bool Fraction::operator<=(const Fraction& other) const
{
    return true;
}
bool Fraction::operator<=(const float &num) const
{
    // Fraction temp(num);
    // float f1 = static_cast<float>(numerator) / static_cast<float>(denominator);
    // float f2 = static_cast<float>(temp.numerator) / static_cast<float>(temp.denominator);
    // return f1 <= f2;
    return true;
}

Fraction &Fraction::operator++()
{
    // numerator += denominator;
    // return *this;
    return *this;
}

Fraction Fraction::operator++(int)
{
    // Fraction temp(*this);
    // numerator += denominator;
    // return temp;
    return Fraction(1,1);
}

Fraction &Fraction::operator--()
{
    // numerator -= denominator;
    // return *this;
    return *this;
}

Fraction Fraction::operator--(int)
{
    // Fraction temp(*this);
    // numerator -= denominator;
    // return temp;
    return Fraction(1,1);
}

istream &operator>>(istream &cin, Fraction &other)
{
    // char ch;
    // cin >> other.getNum() >> ch >> other.getDeno();
    return cin;
}

ostream &operator<<(ostream &cout, const Fraction &other)
{
    // cout << other.getNum() << "/" << other.getDeno();
    return cout;
}