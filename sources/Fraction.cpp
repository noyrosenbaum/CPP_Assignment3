#include "Fraction.hpp"

using namespace std;

using namespace ariel;

// Default constructor
Fraction::Fraction()
{
    this->numerator = 0;
    this->denominator = 1;
}
// Constructor with paramaters
Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    denominator != 0 ? this->denominator = denominator : throw "Initialize 0 in denominator is an illegal action";
    reduce(*this);
}
Fraction::Fraction(float num)
{
    this->numerator = int(num * 1000);
    this->denominator = 1000;
    reduce(*this);
}
// Getters
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
// Setters
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

// + operation
const Fraction Fraction::operator+(const Fraction &other) const
{
    int newNum = (this->numerator * other.getDeno() + this->denominator * other.getNum());
    int newDeno = (this->denominator * other.getDeno());
    if (newDeno > 0 && newNum > INT_MAX - newDeno)
    {
        // `newNum + newDeno` would overflow
    }
    if (newDeno < 0 && newNum < INT_MIN - newDeno) // `newNum + newDeno` would underflow
        return Fraction(newNum, newDeno);
}
Fraction Fraction::operator+(const float &num) const
{
    return Fraction(1, 1);
}
Fraction operator+(const float &num, const Fraction &other)
{

    return Fraction(1, 1);
}
// - operation
const Fraction Fraction::operator-(const Fraction &other) const
{

    int newNum = (this->numerator * other.getDeno() - this->denominator * other.getNum());
    int newDeno = (this->denominator * other.getDeno());
    if (newDeno < 0 && newNum > INT_MAX + newDeno)
    {
        // `newNum - newDeno` would overflow
    }
    if (newDeno > 0 && newNum < INT_MIN + newDeno) // `newNum - newDeno` would underflow
}

Fraction operator-(const float &num, const Fraction &other)
{

    return Fraction(1, 1);
}
Fraction Fraction::operator-(const float &num) const
{
    return Fraction(1, 1);
}
// / operation
const Fraction Fraction::operator/(const Fraction &other) const
{

    int newNum = (this->numerator * other.getDeno());
    int newDeno = (this->denominator * other.getNum());
    // There may be a need to check for -1 for two's complement machines.
    // If one number is -1 and another is INT_MIN, multiplying them we get abs(INT_MIN) which is 1 higher than INT_MAX
    if (newNum == -1 && newDeno == INT_MIN)     // `newNuma * x` can overflow
        if (newDeno == -1 && newNum == INT_MIN) // `newNum * x` (or `newNum / x`) can overflow
            // general case
            if (newDeno != 0 && newNum > INT_MAX / newDeno)     // `newNum * x` would overflow
                if (newDeno != 0 && newNum < INT_MIN / newDeno) // `newNum * x` would underflow
}
Fraction Fraction::operator/(const float &num) const
{
    return Fraction(1, 1);
}
Fraction operator/(const float &num, const Fraction &other)
{

    return Fraction(1, 1);
}
// * operation
const Fraction Fraction::operator*(const Fraction &other) const
{
    int newNum = (this->numerator * other.getNum());
    int newDeno = (this->denominator * other.getDeno());
    // There may be a need to check for -1 for two's complement machines.
    // If one number is -1 and another is INT_MIN, multiplying them we get abs(INT_MIN) which is 1 higher than INT_MAX
    if (newNum == -1 && newDeno == INT_MIN)     // `newNuma * x` can overflow
        if (newDeno == -1 && newNum == INT_MIN) // `newNum * x` (or `newNum / x`) can overflow
            // general case
            if (newDeno != 0 && newNum > INT_MAX / newDeno)     // `newNum * x` would overflow
                if (newDeno != 0 && newNum < INT_MIN / newDeno) // `newNum * x` would underflow
}
Fraction Fraction::operator*(const float &num) const
{
    return Fraction(1, 1);
}
Fraction operator*(const float &num, const Fraction &other)
{

    return Fraction(1, 1);
}
// == operation
bool operator==(const float &num, const Fraction &other)
{

    return true;
}
bool Fraction::operator==(const Fraction &other) const
{
    return (this->getNum() == other.getNum()) && (this->getDeno() == other.getDeno()); 
}
bool Fraction::operator==(const float &num) const
{

    return true;
}
// > operation
bool operator>(const float &num, const Fraction &other)
{

    return true;
}
bool Fraction::operator>(const Fraction &other) const
{
    return 
}
bool Fraction::operator>(const float &num) const
{

    return true;
}
// < operation
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
// >= operation
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
// <= operation
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
// ++ operation
Fraction &Fraction::operator++()
{

    return *this;
}

Fraction Fraction::operator++(int)
{

    return Fraction(1, 1);
}
// -- operation
Fraction &Fraction::operator--()
{

    return *this;
}

Fraction Fraction::operator--(int)
{

    return Fraction(1, 1);
}
// istream operation
istream &operator>>(istream &cin, Fraction &other)
{

    return cin;
}
// ostream operation
ostream &operator<<(ostream &cout, const Fraction &other)
{

    return cout;
}