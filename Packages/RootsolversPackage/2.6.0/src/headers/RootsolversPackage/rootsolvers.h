// iteration schemes for computation of roots for R^1-->R^1 functions
#include<functional>

void rootSolve_bisect(std::function<double(const double&)>,double,double,double&); 		// func_f, xL,xR, return x

void rootSolve_newton(std::function<double(const double&)>,double&); 					// func_f, x0, return x1