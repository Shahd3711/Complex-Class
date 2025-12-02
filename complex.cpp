#include"Complex.h"
#include<cmath>
#include<iostream>
using namespace std;

Complex::Complex():real_(0.0),imag_(0.0){}
Complex::Complex(double real):real_(real),imag_(0.0){}
Complex::Complex(double real,double imag):real_(real),imag_(imag){}

// Binary Arithmetic Operators
Complex Complex::operator+(const Complex&other)const{
    return Complex(real_+other.real_,imag_+other.imag_);
}
Complex Complex::operator-(const Complex&other)const{
    return Complex(real_-other.real_,imag_-other.imag_);
}
Complex Complex::operator*(const Complex&other)const{
    return Complex(real_*other.real_-imag_*other.imag_,
                   real_*other.imag_+imag_*other.real_);
}
Complex Complex::operator/(const Complex&other)const{
    double d=other.real_*other.real_+other.imag_*other.imag_;
    if(d==0){
        cerr<<"Error:Division by zero complex number."<<endl;
        return Complex(0.0,0.0);
    }
    return Complex((real_*other.real_+imag_*other.imag_)/d,
                   (imag_*other.real_-real_*other.imag_)/d);
}
Complex Complex::operator%(const Complex&other)const{
    double a=modulus();
    double b=other.modulus();
    if(b==0.0){
        cerr<<"Error:Modulus remainder by zero."<<endl;
        return Complex(0,0);
    }
    double q=(int)(a/b);
    double r=a-(q*b);
    return Complex(r,0);
}

// Unary Sign Operators
Complex Complex::operator+() const{
    return *this;
}
Complex Complex::operator-() const{
    return Complex(-real_, -imag_);
}

// Compound Assignment Operators
Complex&Complex::operator+=(const Complex&other){
    real_+=other.real_;
    imag_+=other.imag_;
    return*this;
}
Complex&Complex::operator-=(const Complex&other){
    real_-=other.real_;
    imag_-=other.imag_;
    return*this;
}
Complex&Complex::operator*=(const Complex&other){
    double r=real_*other.real_-imag_*other.imag_;
    double i=real_*other.imag_+imag_*other.real_;
    real_=r;
    imag_=i;
    return*this;
}
Complex&Complex::operator/=(const Complex&other){
    double d=other.real_*other.real_+other.imag_*other.imag_;
    if(d==0){
        cerr<<"Error:Division by zero complex number in /=."<<endl;
        return*this;
    }
    double r=(real_*other.real_+imag_*other.imag_)/d;
    double i=(imag_*other.real_-real_*other.imag_)/d;
    real_=r;
    imag_=i;
    return*this;
}
Complex&Complex::operator%=(const Complex&other){
    Complex result=*this%other;
    real_=result.real_;
    imag_=result.imag_;
    return*this;
}

// Comparison Operators
bool Complex::operator==(const Complex&other)const{
    return real_==other.real_&&imag_==other.imag_;
}
bool Complex::operator!=(const Complex&other)const{
    return!(*this==other);
}

// Unary Increment/Decrement Operators
Complex&Complex::operator++(){
    real_+=1.0;
    return*this;
}
Complex Complex::operator++(int){
    Complex temp=*this;
    real_+=1.0;
    return temp;
}
Complex&Complex::operator--(){
    real_-=1.0;
    return*this;
}
Complex Complex::operator--(int){
    Complex temp=*this;
    real_-=1.0;
    return temp;
}

// Logical Operators
bool Complex::operator!() const{
    return modulus() == 0.0;
}
bool Complex::operator&&(const Complex& other) const{
    return modulus() != 0.0 && other.modulus() != 0.0;
}
bool Complex::operator||(const Complex& other) const{
    return modulus() != 0.0 || other.modulus() != 0.0;
}

// Casting Operators
Complex::operator double() const {
    return real_;
}
Complex::operator int() const {
    return (int)real_;
}
Complex::operator float() const {
    return (float)real_;
}
Complex::operator long long() const {
    return (long long)real_;
}
Complex::operator char() const {
    return (char)real_;
}

// Utility and Manual Functions
double Complex::modulus()const{
    return sqrt(real_*real_+imag_*imag_);
}
double Complex::argument()const{
    return atan2(imag_,real_);
}
double Complex::cos_approx(double angle)const{
    return cos(angle);
}
double Complex::sin_approx(double angle)const{
    return sin(angle);
}
Complex Complex::manual_sqrt()const{
    double r=modulus();
    double theta=argument();
    double nr=sqrt(r);
    double half_theta=theta/2;
    return Complex(nr*cos_approx(half_theta),nr*sin_approx(half_theta));
}
Complex Complex::manual_cbrt()const{
    double r=modulus();
    double theta=argument();
    double nr=cbrt(r);
    double third_theta=theta/3;
    return Complex(nr*cos_approx(third_theta),nr*sin_approx(third_theta));
}
Complex Complex::modulus_rem(const Complex&other)const{
    double a=modulus();
    double b=other.modulus();
    if(b==0.0){
        cerr<<"Error:Modulus remainder by zero complex number."<<endl;
        return Complex(0,0);
    }
    double q=(int)(a/b);
    double r=a-(q*b);
    return Complex(r,0);
}
Complex Complex::manual_pow(int p)const{
    Complex base=*this;
    Complex res(1,0);
    int exp=p;
    if(exp<0){
        exp=-exp;
        base=Complex(1,0)/base;
    }
    while(exp>0){
        if(exp&1)res=res*base;
        base=base*base;
        exp>>=1;
    }
    return res;
}
double&Complex::operator[](int idx){
    if(idx==0)return real_;
    return imag_;
}
ostream&operator<<(ostream&os,const Complex&c){
    os<<c.real_<<(c.imag_>=0?" + ":" - ")<<abs(c.imag_)<<"i";
    return os;
}
