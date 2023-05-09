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
    denominator != 0 ? this->denominator = denominator : throw invalid_argument("Initialize 0 in denominator is an illegal action");
    reduce();
}

Fraction::Fraction(float num)
{
    this->numerator = floor(num * 1000);
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
        throw invalid_argument("Initialize 0 in denominator is an illegal action");
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
    if (numerator < 0 && denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
    if (numerator > 0 && denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
}

// + operation
// if deno is negative and the num  is less than the difference between INT_MIN and newDeno,
// then the addition will also result in an integer overflow.
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
    Fraction temp(num);
    return *this + temp;
}
Fraction operator+(const float &num, const Fraction &other)
{

    Fraction temp(num);
    return other + temp;
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

    Fraction temp(num);
    return temp - other;
}
Fraction Fraction::operator-(const float &num) const
{
    Fraction temp(num);
    return *this - temp;
}
// / operation
const Fraction Fraction::operator/(const Fraction &other) const
{

    int newNum = (numerator * other.denominator);
    int newDeno = (denominator * other.numerator);
    if (other.denominator != 0)
    {
        // If one number is -1 and another is INT_MIN, multiplying them we get abs(INT_MIN) which is 1 higher than INT_MAX
        // If newDeno is
        if ((newNum == -1 && newDeno == INT_MIN))
        {
            throw overflow_error("An overflow error occured");
        }
        if ((newDeno == -1 && newNum == INT_MIN))
        {
            throw overflow_error("An onderflow error occured");
        }
        else
        {
            return Fraction(newNum, newDeno);
        }
    }
    throw invalid_argument("Initialize 0 in denominator is an illegal action");
}
Fraction Fraction::operator/(const float &num) const
{
    if (num == 0) 
    {
        throw invalid_argument("Initialize 0 in denominator is an illegal action");
        
    }
    Fraction temp(num);
    return *this / temp;
}
Fraction operator/(const float &num, const Fraction &other)
{
    // becomes denomerator
    if (other.numerator == 0)
    {
        throw invalid_argument("");
    }
    Fraction temp(num);
    return temp / other;
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
    Fraction temp(num);
    return *this * temp;
}
Fraction operator*(const float &num, const Fraction &other)
{

    Fraction temp(num);
    return other * temp;
}
// == operation
bool operator==(const float &num, const Fraction &other)
{
    Fraction temp(num);
    return temp == other;
}
bool Fraction::operator==(const Fraction &other) const
{
    return (numerator == other.numerator) && (denominator == other.denominator);
}
bool Fraction::operator==(const float &num) const
{

    Fraction temp(num);
    return *this == temp;
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
    Fraction temp(num);
    return (temp.numerator * other.denominator) > (temp.denominator * other.numerator);
}
bool Fraction::operator>(const Fraction &other) const
{
    return (numerator * other.denominator) > (denominator * other.numerator);
}
bool Fraction::operator>(const float &num) const
{
    Fraction temp(num);
    return *this > temp;
}
// < operation
bool operator<(const float &num, const Fraction &other)
{
    Fraction temp(num);
    return (temp.numerator * other.denominator) < (temp.denominator * other.numerator);
}
bool Fraction::operator<(const Fraction &other) const
{
    return (numerator * other.denominator) < (denominator * other.numerator);
}
bool Fraction::operator<(const float &num) const
{
    Fraction temp(num);
    return *this < temp;
}
// >= operation
bool operator>=(const float &num, const Fraction &other)
{
    return !(num < other);
}
bool Fraction::operator>=(const Fraction &other) const
{
    return !(*this < other);
}
bool Fraction::operator>=(const float &num) const
{
    Fraction temp(num);
    return *this >= temp;
}
// <= operation
bool operator<=(const float &num, const Fraction &other)
{
    return !(other < num);
}
bool Fraction::operator<=(const Fraction &other) const
{
    return !(*this > other);
}
bool Fraction::operator<=(const float &num) const
{
    Fraction temp(num);
    return *this <= temp;
}
// ++ operation
// overloads the pre-increment operator.
Fraction &Fraction::operator++()
{
    numerator += denominator;
    return *this;
}
// overloads the post-increment operator
Fraction Fraction::operator++(int)
{
    // copy
    Fraction temp(*this);
    ++(*this);
    return temp;
}
// -- operation
Fraction &Fraction::operator--()
{
    numerator -= denominator;
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
        throw invalid_argument("Initialize 0 in denominator is an illegal action");
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