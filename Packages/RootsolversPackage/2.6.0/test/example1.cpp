#include<iostream>
#include"RootsolversPackage/rootsolvers.h"

double func_f(const double& x){
	// this function has a root between -1 and 1
	return 0.2 * x*x + 5.0*x -1.1;
}

int main(void){
	
	double xL=-2, xR=2, x=0.0/0.0;
	
	rootSolve_bisect(func_f,xL,xR,x);
	std::cout 	<< std::scientific 
				<< "Bisection root : " << x << std::endl;
	
	x=xR;
	rootSolve_newton(func_f,x);
	std::cout 	<< "Newston   root : " << x << std::endl;
	
	return 0;
}