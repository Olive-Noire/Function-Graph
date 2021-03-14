#include "../Headers/Math.hpp"

//DECIMAL
double square(double x) { return x*x; }
double cube(double x) { return square(x)*x; }
double abs(double x) { if (x<0) return x*=-1; else return x; }
double power(double x,int p) { double t(x); for(int i = 1;i < p;i++) x*=t; return x; }
//double cos(double x) { }