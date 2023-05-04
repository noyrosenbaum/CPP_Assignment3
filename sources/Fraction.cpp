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
    reduce();
}

Fraction::Fraction(float num)
{
    this->numerator = int(num * 1000);
    this->denominator = 1000;
    reduce();
}
// Getters
int Fraction::getNumerator() const
{
    return numerator;
}
int Fraction::getDenominator() const
{
    return denominator;
}
Fraction Fraction::getFraction()
{
    return Fraction(this->getNumerator(), this->getDenominator());
}
// Setters
void Fraction::setNum(int num)
{
    numerator = num;
}
void Fraction::setDeno(int deno)
{
    if (denominator == 0)
        throw "Initialize 0 in denominator is an illegal action";
    denominator = deno;
}
void Fraction::reduce()
{
    int num = numerator;
    int deno = denominator;
    // find GCD of these 2 numbers and keep devide them until you reach 1
    int result = min(abs(num), abs(deno)); // Find Minimum of a and b
    while (result > 1)
    {
        if (num % result == 0 && deno % result == 0)
        {
            break;
        }
        result--;
    }
    numerator /= result;
    denominator /= result;
}

// + operation
const Fraction Fraction::operator+(const Fraction &other) const
{
    int newNum = (numerator * other.denominator + denominator * other.numerator);
    int newDeno = (denominator * other.denominator);
    if ((newDeno > 0 && newNum > INT_MAX - newDeno) || (newDeno < 0 && newNum < INT_MIN - newDeno))
        throw overflow_error("An overflow error occured");
    else
    {
        return Fraction(newNum, newDeno);
    }
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

    int newNum = (numerator * other.denominator - denominator * other.numerator);
    int newDeno = (denominator * other.denominator);
    if ((newDeno < 0 && newNum > INT_MAX + newDeno) || (newDeno > 0 && newNum < INT_MIN + newDeno))
    {
        throw overflow_error("An overflow error occured");
    }
    else
    {
        return Fraction(newNum, newDeno);
    }
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

    int newNum = (numerator * other.denominator);
    int newDeno = (denominator * other.numerator);
    if (other.denominator != 0)
    {
        // There may be a need to check for -1 for two's complement machines.
        // If one number is -1 and another is INT_MIN, multiplying them we get abs(INT_MIN) which is 1 higher than INT_MAX
        if ((newNum == -1 && newDeno == INT_MIN) || (newDeno != 0 && newNum > INT_MAX / newDeno))
        {
            throw overflow_error("An overflow error occured");
        }
        if ((newDeno == -1 && newNum == INT_MIN) || (newDeno != 0 && newNum < INT_MIN / newDeno))
        {
            throw overflow_error("An onderflow error occured");
        }
        else
        {
            return Fraction(newNum, newDeno);
        }
    }
    throw "Initialize 0 in denominator is an illegal action";
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
    int newNum = (numerator * other.numerator);
    int newDeno = (denominator * other.denominator);
    // There may be a need to check for -1 for two's complement machines.
    // If one number is -1 and another is INT_MIN, multiplying them we get abs(INT_MIN) which is 1 higher than INT_MAX
    if ((newNum == -1 && newDeno == INT_MIN) || (newDeno != 0 && newNum > INT_MAX / newDeno))

        throw overflow_error("An overflow error occured");

    if ((newDeno == -1 && newNum == INT_MIN) || (newDeno != 0 && newNum < INT_MIN / newDeno))

        throw overflow_error("An onderflow error occured");

    else
    {
        return Fraction(newNum, newDeno);
    }
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
    return (numerator == other.numerator) && (denominator == other.denominator);
}
bool Fraction::operator==(const float &num) const
{

    return true;
}
// != operation
bool Fraction::operator!=(const Fraction &other) const
{
    return !(*this == other);
}
bool operator!=(const float &num, const Fraction &other)
{
    return !(num == other);
}
bool Fraction::operator!=(const float &num) const
{
    return !(*this == num);
}

// > operation
bool operator>(const float &num, const Fraction &other)
{

    return true;
}
bool Fraction::operator>(const Fraction &other) const
{
    return (numerator * other.denominator) > (denominator * other.numerator);
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
    return (numerator * other.denominator) < (denominator * other.numerator);
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
    return !(*this < other);
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
    return !(*this > other);
}
bool Fraction::operator<=(const float &num) const
{

    return true;
}
// ++ operation
Fraction &Fraction::operator++()
{
    (*this)++;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp(*this);
    ++(*this);
    return temp;
}
// -- operation
Fraction &Fraction::operator--()
{

    (*this)--;
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction temp(*this);
    --(*this);
    return temp;
}
// istream operation
istream &operator>>(istream &cin, Fraction &other)
{
    int numerator, denominator;
    cin >> numerator >> denominator;
    if (cin.fail())
        throw runtime_error("Invalid input");
    if (denominator == 0)
        throw "Initialize 0 in denominator is an illegal action";
    other.numerator = numerator;
    other.denominator = denominator;
    other.reduce();
    return cin;
}
// ostream operation
ostream &operator<<(ostream &cout, const Fraction &other)
{
    cout << other.getNumerator() << "/" << other.getDenominator();
    return cout;
}