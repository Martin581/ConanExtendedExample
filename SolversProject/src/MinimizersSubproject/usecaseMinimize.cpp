#include<iostream>
#include<MinimizersPackage/minimizers.h>

double func_f(const double& x){
	return 2.0 * x*x - 18.0; 	// roots are 9 and -9, minimizer is 0.
}

int main(void){
	std::cout << std::scientific << "running usecaseRootSolve.\n";
	
	double xL=-10,xR=15,x;
	minimize_golden(func_f,xL,xR,x);
	std::cout << "golden section minimizer : " << x << std::endl;
	
	return 0;
}