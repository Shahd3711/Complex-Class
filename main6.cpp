#include"Complex.h"
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define el '\n'

int main(){
    cout<<fixed<<setprecision(2);
    cout<<"--- Shahooda's C++ Complex Class Test ---"<<el;

    double a,b;
    cout<<"Enter real and imaginary part: ";
    cin>>a>>b;
    Complex c(a,b);
    cout<<"User-input Complex c = "<<c<<el;

    Complex c1(3.0,4.0);
    Complex c2(1.0,-2.0);
    Complex c_mod_rem_b(2.0,0.0);
    Complex c_inc(5.0, 5.0);
    Complex c_zero(0.0, 0.0);
    Complex c_non_zero(1.0, 0.0);
    Complex c_cast(65.75, 5.67);

    cout<<"Initial Values:"<<el;
    cout<<"c1 = "<<c1<<el;
    cout<<"c_inc = "<<c_inc<<el;
    cout<<"-----------------------------------"<<el;

    // Binary Arithmetic Test
    Complex sum=c1+c2;
    cout<<"Addition (c1 + c2):"<<el;
    cout<<c1<<" + "<<c2<<" = "<<sum<<el;
    cout<<"-----------------------------------"<<el;

    // Unary Sign Operators Test
    cout<<"Unary Sign Operators Test:"<<el;
    cout<<"-c1 (Negative): "<<-c1<<el;
    cout<<"-----------------------------------"<<el;

    // Modulus and Assignment Test
    Complex remainder=c1%c_mod_rem_b;
    cout<<"Modulus Operator (c1 % c_mod_rem_b):"<<el;
    cout<<c1<<" % "<<c_mod_rem_b<<" = "<<remainder<<el;
    cout<<"c1 before %=: "<<c1<<el;
    c1%=c_mod_rem_b;
    cout<<"c1 after %=: "<<c1<<el;
    cout<<"-----------------------------------"<<el;

    // Increment/Decrement Test
    cout<<"Prefix and Postfix Operators Test:"<<el;
    Complex prefix_res=++c_inc;
    cout<<"Prefix Increment (++c_inc) Result: "<<prefix_res<<" | c_inc now: "<<c_inc<<el;
    Complex postfix_res=c_inc++;
    cout<<"Postfix Increment (c_inc++) Result: "<<postfix_res<<" | c_inc now: "<<c_inc<<el;
    cout<<"-----------------------------------"<<el;

    // Logical Operators Test
    cout<<"Logical Operators Test:"<<el;
    cout<<"!c1 (Not non-zero) : "<<(!c1 ? "True" : "False")<<el;
    cout<<"!c_zero (Not zero) : "<<(!c_zero ? "True" : "False")<<el;
    cout<<"(c1 && c2) : "<<(c1 && c2 ? "True" : "False")<<el;
    cout<<"(c_zero || c_non_zero) : "<<(c_zero || c_non_zero ? "True" : "False")<<el;
    cout<<"-----------------------------------"<<el;

    // Casting Operators Test
    double d_val = (double)c_cast;
    int i_val = (int)c_cast;
    float f_val = (float)c_cast;
    long long ll_val = (long long)c_cast;
    char ch_val = (char)c_cast;
    
    cout<<"Casting Operators Test (c_cast = "<<c_cast<<"):"<<el;
    cout<<"Explicit cast to double: "<<d_val<<el;
    cout<<"Explicit cast to int: "<<i_val<<el;
    cout<<"Explicit cast to float: "<<f_val<<el;
    cout<<"Explicit cast to long long: "<<ll_val<<el;
    cout<<"Explicit cast to char (ASCII 65): "<<ch_val<<el;
    
    cout<<"-----------------------------------"<<el;

    return 0;
}
