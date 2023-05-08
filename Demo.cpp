#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;

int main() {
    // Default constructor
    Fraction frac1;
    cout << "Default constructor: " << frac1 << endl;

    // Constructor with parameters
    Fraction frac2(3, 5);
    cout << "Constructor with parameters: " << frac2 << endl;

    // Constructor with float
    Fraction frac3(0.6);
    cout << "Constructor with float: " << frac3 << endl;

    // Getters
    cout << "Numerator: " << frac2.getNumerator() << ", Denominator: " << frac2.getDenominator() << endl;

    // Setters
    frac1.setNum(2);
    frac1.setDeno(4);
    cout << "After setting numerator and denominator: " << frac1 << endl;

    // Arithmetic operations
    Fraction frac4(1, 4);
    cout << "Addition: " << frac2 << " + " << frac4 << " = " << (frac2 + frac4) << endl;
    cout << "Subtraction: " << frac2 << " - " << frac4 << " = " << (frac2 - frac4) << endl;
    cout << "Multiplication: " << frac2 << " * " << frac4 << " = " << (frac2 * frac4) << endl;
    cout << "Division: " << frac2 << " / " << frac4 << " = " << (frac2 / frac4) << endl;

    // Comparison operations
    cout << "Equality: " << frac2 << " == " << frac4 << " -> " << (frac2 == frac4) << endl;
    cout << "Inequality: " << frac2 << " != " << frac4 << " -> " << (frac2 != frac4) << endl;
    cout << "Greater than: " << frac2 << " > " << frac4 << " -> " << (frac2 > frac4) << endl;
    cout << "Less than: " << frac2 << " < " << frac4 << " -> " << (frac2 < frac4) << endl;
    cout << "Greater than or equal to: " << frac2 << " >= " << frac4 << " -> " << (frac2 >= frac4) << endl;
    cout << "Less than or equal to: " << frac2 << " <= " << frac4 << " -> " << (frac2 <= frac4) << endl;

    // Increment and decrement
    cout << "Pre-increment: ++" << frac2 << " = ";
    ++frac2;
    cout << frac2 << endl;

    cout << "Post-increment: " << frac2 << "++ = ";
    frac2++;
    cout << frac2 << endl;

    cout << "Pre-decrement: --" << frac2 << " = ";
    --frac2;
    cout << frac2 << endl;

    cout << "Post-decrement: " << frac2 << "-- = ";
    frac2--;
    cout << frac2 << endl;

    // Input and output
    Fraction inputFrac;
    cout << "Enter a fraction: <numerator> <denominator> \n";
    cin >> inputFrac;
    cout << "You entered: " << inputFrac << endl;

    return 0;
}