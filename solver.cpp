#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "solver.hpp"
#include <stdio.h>

using namespace std;
using namespace solver;

RealVariable solver::operator+ (const RealVariable& real1, const RealVariable& real2)
{
    return RealVariable(real1.a+real2.a,real1.b+real2.b,real1.c+real2.c);
}

RealVariable solver::operator- (const RealVariable& real1, const RealVariable& real2)
{
    return RealVariable(real1.a-real2.a,real1.b-real2.b,real1.c-real2.c);
}

RealVariable solver::operator/ (const RealVariable& real1, const RealVariable& real2)
{
    RealVariable zero(0,0,0);
    //  if (real2.a==0&&real2.b==0&&real2.c==0)
    if(real2<=>zero)
    {
        throw runtime_error("Division by zero");
    }
    return RealVariable(real1.a/real2.c,real1.b/real2.c,real1.c/real2.c);  
}      

RealVariable solver::operator* (const RealVariable& real1, const RealVariable& real2)
{
    if((real1.a!=0 && (real2.a!=0 || real2.b !=0 )) || (real2.a!=0) && (real1.a!=0 || real1.b !=0 ))
    {
        throw runtime_error("power bigger than X^2");
    }
    return RealVariable(real1.a*real2.c+real2.a*real1.c+real1.b*real2.b,real1.b*real2.c+real2.b*real1.c,real1.c*real2.c);
}

RealVariable solver::operator^ (const RealVariable& real1, double power)
{
    if (power!=2)
    {
        throw runtime_error("power bigger than X^2");
    }
    return RealVariable(1,0,0);
}

RealVariable solver::operator== (const RealVariable& real1,const RealVariable& real2)
{
    return RealVariable(real1-real2);
}

bool solver::operator<=>(const RealVariable& real1,const RealVariable& real2)
{
     if(real1.a==real2.a && real1.b==real2.b && real1.c==real2.c) return true;
     return false;
}

double solver::solve(RealVariable real) {
    if (real.a ==0 &&real.b==0) throw runtime_error("no solution");
    if (real.a != 0)
    {
        double ans = pow(real.b, 2) - 4 * real.a * real.c; // B^2-4AC
        if (ans < 0) throw runtime_error("no solution");
        return (-real.b + sqrt(ans)) / (2 * real.a);
    }
    return (-real.c)/real.b;
}



//////////////////////////////////////////////////////////////////////////////////
ComplexVariable solver::operator+ (const ComplexVariable& comp1, const ComplexVariable& comp2)
{
    return ComplexVariable(comp1.a+comp2.a,comp1.b+comp2.b,comp1.c+comp2.c);
}

ComplexVariable solver::operator- (const ComplexVariable& comp1, const ComplexVariable& comp2)
{
    return ComplexVariable(comp1.a-comp2.a,comp1.b-comp2.b,comp1.c-comp2.c);
}

ComplexVariable solver::operator/ (const ComplexVariable& comp1, const ComplexVariable& comp2)
{
    complex<double> zero (0,0);
    if(comp2.a == zero && comp2.b == zero && comp2.c==zero)
        throw runtime_error("ERROR: Must not divide by 0");
    return ComplexVariable(comp1.a/comp2.c,comp1.b/comp2.c,comp1.c/comp2.c);
}

ComplexVariable solver::operator* (const ComplexVariable& comp1, const ComplexVariable& comp2)
{
    complex<double> zero (0,0);
    if((comp1.a!=zero&&(comp2.a!=zero||comp2.b!=zero)) ||
       (comp2.a!=zero&&(comp1.a!=zero||comp1.b!=zero)))
        throw runtime_error("ERROR: The power are more then 2");
    return ComplexVariable(comp1.b*comp2.b+comp1.a*comp2.c+comp2.a*comp1.c,comp1.b*comp2.c+comp1.c*comp2.b,comp1.c*comp2.c);
}

ComplexVariable solver::operator^ (const ComplexVariable& comp, double power)
{
    complex<double> zero (0,0);
    if(power!=2) throw runtime_error("ERROR: The power are more then 2");
    return ComplexVariable((1.0),(0.0),(0.0));
}

ComplexVariable solver::operator== (const ComplexVariable& comp1,const ComplexVariable& comp2){
    return ComplexVariable(comp1-comp2);
}

// bool solver::operator<=>(const complex <double>& comp1,const Complex<double>&  comp2)
// {
//     if(comp1.a==comp2.a&&comp1.b==comp2.b&&comp1.c==comp2.c) return true;
//     return false
// }

complex<double> solver::solve(ComplexVariable comp)
{
    complex<double> zero (0,0);
    if (comp.a==zero && comp.b== zero) throw runtime_error("ERROR: There is no solution");
    if (comp.a != zero){
        complex<double> dis = sqrt(pow(comp.b, 2) - 4.0 * comp.a * comp.c);
        return (-comp.b + dis) / (2.0 * comp.a);
    }
    return (-comp.c)/comp.b;
}







