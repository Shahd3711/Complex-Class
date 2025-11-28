#include "Complex.h"
using namespace std;
//Constructors
Complex::Complex() : real_(0.0), imag_(0.0) 
{
    // Initializes complex number to 0 + 0i
}
Complex::Complex(double real) : real_(real), imag_(0.0) 
{
    // Initializes complex number to real + 0i
}

Complex::Complex(double real, double imag) : real_(real), imag_(imag) 
{
    // Initializes complex number to real + imag*i
}

//Operator Overloading (Binary Arithmetic)
// Addition: (a + bi) + (c + di) = (a + c) + (b + d)i
Complex Complex::operator+(const Complex& other) const 
{
    double newReal = real_ + other.real_;
    double newImag = imag_ + other.imag_;
    return Complex(newReal, newImag);
}

// Subtraction: (a + bi) - (c + di) = (a - c) + (b - d)i
Complex Complex::operator-(const Complex& other) const 
{
    double newReal = real_ - other.real_;
    double newImag = imag_ - other.imag_;
    return Complex(newReal, newImag);
}

// Multiplication: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
Complex Complex::operator*(const Complex& other) const 
{
    // a=real_, b=imag_, c=other.real_, d=other.imag_
    double newReal = (real_ * other.real_) - (imag_ * other.imag_);
    double newImag = (real_ * other.imag_) + (imag_ * other.real_);
    return Complex(newReal, newImag);
}

// Division: (a + bi) / (c + di) = [(ac + bd) / (c² + d²)] + [(bc - ad) / (c² + d²)]i
Complex Complex::operator/(const Complex& other) const 
{
    double c = other.real_;
    double d = other.imag_;
    // Calculate the denominator: c^2 + d^2
    double denominator = (c * c) + (d * d);
    // Basic error handling for division by zero complex number
    if (denominator == 0.0) {
        // In a real application, you would throw an exception.
        // For this assignment, we print an error and return 0 + 0i.
        cerr << "Error: Division by zero complex number." << endl;
        return Complex(0.0, 0.0);
    }
    // Calculate the numerator's real part: ac + bd
    double numReal = (real_ * c) + (imag_ * d);

    // Calculate the numerator's imaginary part: bc - ad
    double numImag = (imag_ * c) - (real_ * d);

    // Final result
    double newReal = numReal / denominator;
    double newImag = numImag / denominator;

    return Complex(newReal, newImag);
}

//Stream Overloading

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real_;
    // Handle the sign for the imaginary part
    if (c.imag_ >= 0) {
        os << " + " << c.imag_ << "i";
    } else {
        // If imag is negative, print the '-' sign directly
        os << " - " << -c.imag_ << "i";
    }
    return os;
}