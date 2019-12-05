#include<iostream>
#include"MinimizersPackage/minimizers.h"

double func_f(const double& x){
	// this function has a root between -1 and 1
	return 10.0 * x*x + 0.3*x - 1.1; 	// minimizer at x = -0.015
}

int main(void){
	
	double xL=-2, xR=2, x=0.0/0.0;
	
	minimize_golden(func_f,xL,xR,x);
	std::cout 	<< std::scientific 
				<< "Golden section minimizer : " << x << std::endl;
	
	x=xR;
	minimize_newton(func_f,x);
	std::cout 	<< "Newton critical point    : " << x << std::endl;
	
	return 0;
}