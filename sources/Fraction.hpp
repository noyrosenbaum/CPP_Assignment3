#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <functional>
#include <cmath>
#include <math.h>
#include <limits.h>
using namespace std;
namespace ariel
{
}

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator);
    Fraction(float num);
    Fraction();
    int getNum() const;
    int getDeno() const;
    Fraction getFraction();
    void reduce(Fraction &frac);
    void setNum(int num);
    void setDeno(int deno);
    /* + */
    const Fraction operator+(const Fraction &other) const;
    Fraction operator+(const float& other) const;
    friend Fraction operator+(const float &num, const Fraction &other);
    /* - */
    const Fraction operator-(const Fraction &other) const;
    Fraction operator-(const float& other) const;
    friend Fraction operator-(const float &num, const Fraction &other);
    /* / */
    const Fraction operator/(const Fraction &other) const;
    Fraction operator/(const float& other) const;
    friend Fraction operator/(const float &num, const Fraction &other);
    /* * */
    const Fraction operator*(const Fraction &other)const;
    Fraction operator*(const float& other) const;
    friend Fraction operator*(const float &num, const Fraction &other);
    /* comparassions */
    friend bool operator==( const float &num, const Fraction &other);
    bool operator==(const float &num)const;
    bool operator==(const Fraction& other) const;
    bool operator != (const Fraction& other) const;
    friend bool operator != (const float &num, const Fraction &other);
    bool operator != (const float &num) const;
    friend bool operator>(const float &num, const Fraction &other);
    bool operator>(const float &num)const;
    bool operator>(const Fraction& other) const;
    friend bool operator<( const float &num, const Fraction &other);
    bool operator<(const float &num)const;
    bool operator<(const Fraction& other) const;
    friend bool operator>=( const float &num, const Fraction &other);
    bool operator>=(const float &num)const;
    bool operator>=(const Fraction& other) const;
    friend bool operator<=(const float &num, const Fraction &other);
    bool operator<=(const float &num)const;
    bool operator<=(const Fraction& other) const;
    /* increament/decreament by 1 */
    Fraction &operator++();
    Fraction operator++(int);
    Fraction &operator--();
    Fraction operator--(int);
    /* streams */
    friend istream &operator>>(istream &cin, Fraction &other);
    friend ostream &operator<<(ostream &cout, const Fraction &other);
};
