#include<assert.h>
#include"MinimizersPackage/deg2_minimizers.h"
#include"FinitediffPackage/finitedifferences.h"
#include<RootsolversPackage/rootsolvers.h>

// define g(x) := f'(x)
//
// solve g(x)=0 for x via Newton

void minimize_newton(double(*func_f)(const double&), double& x){
	// warning: may diverge
	//
	auto func_g 	= [&func_f](const double& x){
		return fd_der1(func_f,x);
	};
	//
	rootSolve_newton(func_g,x);
}