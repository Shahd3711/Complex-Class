#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
using namespace std;

class Complex{
private:
    double real_;
    double imag_;

public:
    Complex();
    explicit Complex(double real);
    Complex(double real,double imag);

    double getReal()const{return real_;}
    double getImag()const{return imag_;}

    // Binary Arithmetic Operators
    Complex operator+(const Complex&other)const;
    Complex operator-(const Complex&other)const;
    Complex operator*(const Complex&other)const;
    Complex operator/(const Complex&other)const;
    Complex operator%(const Complex&other)const;

    // Unary Sign Operators
    Complex operator+() const; 
    Complex operator-() const; 

    // Compound Assignment Operators
    Complex&operator+=(const Complex&other);
    Complex&operator-=(const Complex&other);
    Complex&operator*=(const Complex&other);
    Complex&operator/=(const Complex&other);
    Complex&operator%=(const Complex&other);

    // Comparison Operators
    bool operator==(const Complex&other)const;
    bool operator!=(const Complex&other)const;

    // Unary Increment/Decrement Operators
    Complex&operator++();
    Complex operator++(int);
    Complex&operator--();
    Complex operator--(int);
    
    // Logical Operators
    bool operator!() const;
    bool operator&&(const Complex& other) const;
    bool operator||(const Complex& other) const;
    
    // Casting Operators
    operator double() const;
    operator int() const;
    operator float() const;
    operator long long() const;
    operator char() const;

    double modulus()const;
    double argument()const;
    double cos_approx(double angle)const;
    double sin_approx(double angle)const;
    Complex manual_sqrt()const;
    Complex manual_cbrt()const;
    Complex modulus_rem(const Complex&other)const;
    Complex manual_pow(int p)const;

    double&operator[](int idx);

    friend ostream&operator<<(ostream&os,const Complex&c);
};
#endif
