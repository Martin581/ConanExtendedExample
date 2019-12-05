#include<iostream>
#include"MinimizersPackage/minimizers.h"

float func_f(const float& x){
	// this function has a root between -1 and 1
	return 10.0 * x*x - 0.5*x + 0.01 * x*x*x; 	// at x = 0.0249991
}

int main(void){
	
	float xL=-2, xR=2, x=0.0/0.0;
	
	minimize_golden(func_f,xL,xR,x);
	std::cout 	<< std::scientific 
				<< "Golden section minimizer : " << x << std::endl;
	
	x=xR;
	minimize_secant(func_f,xL,x);
	std::cout 	<< "Secant critical point    : " << x << std::endl;
	
	return 0;
}