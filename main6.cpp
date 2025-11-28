#include "Complex.h"
#include <iostream>
#include <iomanip>
using namespace std;
#define el '\n'
int main()
{
    cout<<fixed<<setprecision(2);
    cout<<"--- Shahooda's C++ Complex Class ---"<<el;
    double a, b;
    cin>>a>>b;
    Complex c(a, b);
    cout<<c<<el;
    Complex c1(3.0, 4.0);
    Complex c2(1.0, -2.0);
    Complex c3(5.0);
    Complex c4;
    cout<<"Initial Values:"<<el;
    cout<<"c1 = "<<c1<<el;//Output: 3.00 + 4.00i
    cout<<"c2 = "<<c2<<el;//Output: 1.00 - 2.00i
    cout<<"c3 (real only) = "<<c3<<el; // Output: 5.00 + 0.00i
    cout<<"c4 (default) = "<<c4<<el; // Output: 0.00 + 0.00i
    cout<<"-----------------------------------"<<el;
    //Addition Test: c1 + c2 = (3+1) + (4-2)i = 4 + 2i
    Complex sum=c1 + c2;
    cout<<"Addition (c1 + c2):"<<el;
    cout<<c1<<" + "<<c2<<" = "<<sum<<el;
    cout<<"-----------------------------------"<<el;
    //Subtraction Test: c1 - c2 = (3-1) + (4-(-2))i = 2 + 6i
    Complex diff=c1 - c2;
    cout<<"Subtraction (c1 - c2):"<<el;
    cout<<c1<< " - "<<c2<<" = "<<diff<<el;
    cout<<"-----------------------------------"<<el;
    // 4. Multiplication Test: c1 * c2 = (3+4i)(1-2i) = (3*1 - 4*(-2)) + (3*(-2) + 4*1)i = (3+8) + (-6+4)i = 11 - 2i
    Complex prod=c1 * c2;
    cout<<"Multiplication (c1 * c2):"<<el;
    cout<<c1<<" * "<<c2<<" = "<<prod<<el;
    cout<<"-----------------------------------"<<el;
    // 5. Division Test: c1 / c2 = (3+4i) / (1-2i)
    // Numerator: (3*1 + 4*(-2)) + (4*1 - 3*(-2))i = (3+8) + (4+6)i = 11 + 10i
    // Denominator: 1^2 + (-2)^2 = 5
    // Result: (11/5) + (10/5)i = 2.2 + 2i
    Complex quot=c1 / c2;
    cout<<"Division (c1 / c2):"<<el;
    cout<<c1<<" / "<<c2<<" = "<<quot<<el;
    cout<<"-----------------------------------"<<el;

    // 6. Division by Zero Test
    Complex c_zero(0.0, 0.0);
    cout<<"Division by Zero Test (c1 / 0):"<<el;
    Complex c_error=c1 / c_zero; // Should print an error and return 0 + 0i
    cout<<"Result: "<<c_error<<el;
    cout<<"-----------------------------------"<<el;
    return 0;
}