#include <iostream>
#include <stdexcept>
#include <complex>

using namespace std;

namespace solver
{

class RealVariable
{
    public:

    double a; // x^2
    double b; // x
    double c; // free number

    RealVariable(): a(0),b(1),c(0){} 
    RealVariable( double a, double b, double c): a(a),b(b),c(c){}
    RealVariable(double number): RealVariable(0,0,number){}

    friend RealVariable operator+ (const RealVariable& real1 , const RealVariable& real2);
    friend RealVariable operator- (const RealVariable& real1, const RealVariable& real2);
    friend RealVariable operator/ (const RealVariable& real1, const RealVariable& real2);
    friend RealVariable operator* (const RealVariable& real1, const RealVariable& real2);
    friend RealVariable operator^ (const RealVariable& real1, double pow);
    friend RealVariable operator== (const RealVariable& real1,const RealVariable& real2);


    friend ostream& operator<< (ostream& os, const RealVariable& real){
        return os << real.a << "x^2+" << real.b << "x+" << real.c; }

    friend double solve(RealVariable& real);
};

double solve(RealVariable real);



}; // namespace solver






