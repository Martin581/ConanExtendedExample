#include<iostream>
#include<RootsolversPackage/rootsolvers.h>

double func_f(const double& x){
	// this function has a root between -1 and 1
	return 0.2 * x*x + 5.0*x -1.1;
}

int main(void){
	
	double xL=-2, xR=2, x=0.0/0.0;
	
	std::function<double(const double&)> 	f 	= func_f;
	
	rootSolve_bisect               (     f,xL,xR,x);
	rootSolve_bisect<double,double>(     f,xL,xR,x);
	rootSolve_bisect<double,double>(func_f,xL,xR,x);
	//rootSolve_bisect               (func_f,xL,xR,x); 	// does not work
	std::cout 	<< std::scientific 
				<< "Bisection root : " << x << std::endl;
	
	x=xR;
	rootSolve_newton               (     f,x);
	rootSolve_newton<double,double>(     f,x);
	rootSolve_newton<double,double>(func_f,x);
	//rootSolve_newton               (func_f,x); 	// does not work
	std::cout 	<< "Newton    root : " << x << std::endl;
	
	return 0;
}