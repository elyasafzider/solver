#include <iostream>
#include <stdexcept>
#include <complex>

using namespace std;

namespace solver
{

class RealVariable
{
    double a; // x^2
    double b; // x
    double c; // free number

public:
    RealVariable(): a(0),b(1),c(0){} 
    RealVariable( double a, double b, double c): a(a),b(b),c(c){}
    RealVariable(double number): RealVariable(0,0,number){}

    friend RealVariable operator+ (const RealVariable& real1 , const RealVariable& real2);
    friend RealVariable operator- (const RealVariable& real1, const RealVariable& real2);
    friend RealVariable operator/ (const RealVariable& real1, const RealVariable& real2);
    friend RealVariable operator* (const RealVariable& real1, const RealVariable& real2);
    friend RealVariable operator^ (const RealVariable& real1, double pow);
    friend RealVariable operator== (const RealVariable& real1,const RealVariable& real2);
    
    friend bool operator<=>(const RealVariable& real1,const RealVariable& real2);

    friend double solve(RealVariable real);

};
double solve(RealVariable real);


class ComplexVariable{
    complex<double> a,b,c;
public:
    //Constructors & explicit
    ComplexVariable ():a(0),b(1,0),c(0){}
    ComplexVariable (double d):ComplexVariable(complex<double>(d,0)){}
    ComplexVariable (const complex<double>& d):a(0),b(0),c(d){}
    ComplexVariable (const complex<double>& a,const complex<double>& b,const complex<double>& c):a(a),b(b),c(c){}

    friend ComplexVariable operator+ (const ComplexVariable& comp1 ,const ComplexVariable& comp2);
    friend ComplexVariable operator* (const ComplexVariable& comp1 ,const ComplexVariable& comp2);
    friend ComplexVariable operator/ (const ComplexVariable& comp1 ,const ComplexVariable& comp2);
    friend ComplexVariable operator- (const ComplexVariable& comp1 ,const ComplexVariable& comp2);
    friend ComplexVariable operator^ (const ComplexVariable& comp , double power);
    friend ComplexVariable operator== (const ComplexVariable& comp1,const ComplexVariable& comp2);
    friend complex<double> solve(ComplexVariable comp);

    //friend bool operator<=>(const ComplexVariable& comp1,const ComplexVariable&  comp2);
    


};
complex<double> solve(ComplexVariable comp);

}; 





