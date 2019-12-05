#include<iostream>
#include"RootsolversPackage/rootsolvers.h"

float func_f(const float& x){
	// this function has a root between -1 and 1
	return -0.8 * x*x + 5.0*x -1.1;
}

int main(void){
	
	float xL=-2, xR=2, x=0.0/0.0;
	
	rootSolve_bisect(func_f,xL,xR,x);
	std::cout << std::scientific << "Bisection root : " << x << std::endl;
	
	x=xR;
	rootSolve_secant(func_f,xL,x);
	std::cout << "Secantion root : " << x << std::endl;
	
	return 0;
}