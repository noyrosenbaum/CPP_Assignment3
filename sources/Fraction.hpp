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
        float num;
        void reduce(Fraction &frac);

    public:
        Fraction(int numerator, int denominator);
        Fraction(float num);
        int getNum();
        int getDeno();
        Fraction getFraction();
        void setNum(int num);
        void setDeno(int deno);
        /* + */
        Fraction operator+(const Fraction &fraction1);
        friend Fraction operator+(const Fraction &fraction1, const float &num);
        /* - */
        Fraction operator-(const Fraction &fraction1);
        friend Fraction operator-(const Fraction &fraction1, const float &num);
        /* / */
        Fraction operator/(const Fraction &fraction1);
        friend Fraction operator/(const Fraction &fraction1, const float &num);
        /* * */
        Fraction operator*(const Fraction &fraction1);
        friend Fraction operator*(const Fraction &fraction1, const float &num);
        /* comparassions */
        friend bool operator==(const Fraction &fraction1, const float &num);
        bool operator==(const float &num);
        friend bool operator>(const Fraction &fraction1, const float &num);
        bool operator>(const float &num);
        friend bool operator<(const Fraction &fraction1, const float &num);
        bool operator<(const float &num);
        friend bool operator>=(const Fraction &fraction1, const float &num);
        bool operator>=(const float &num);
        friend bool operator<=(const Fraction &fraction1, const float &num);
        bool operator<=(const float &num);
        /* increament/decreament by 1 */
        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);
        /* streams */
        friend istream& operator>>(istream& cin, const Fraction &fraction1);
        friend ostream& operator<<(ostream& cout, const Fraction &fraction1);
    };
};