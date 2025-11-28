#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;
class Complex 
{
private:
    double real_;
    double imag_;

public:
    //Constructors


    //Default constructor. Initializes to 0 + 0i.
    Complex();

    //Constructor for real part only. Initializes to real + 0i.
    //The value for the real part.
    explicit Complex(double real);

    //Full constructor. Initializes to real + imag*i.
    Complex(double real, double imag);

    //Getters

    //Returns the real component.
    double getReal() const { return real_; }

    //Returns the imaginary component.
    double getImag() const { return imag_; }

    //Operator Overloading

    Complex operator+(const Complex& other) const;

    Complex operator-(const Complex& other) const;

    Complex operator*(const Complex& other) const;

    Complex operator/(const Complex& other) const;

    //Stream Overloading (Friend function)

    friend ostream& operator<<(ostream& os, const Complex& c);
};
#endif