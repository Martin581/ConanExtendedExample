#include<assert.h>
#include<RootsolversPackage/rootsolvers.h>

void rootSolve_secant(double(*func_f)(const double&), double x0, double& x1){
	// warning: may diverge
	// requirements: x0!=x1, x0,x1 , x0,x1 within well-behaved domain
	assert(x0!=x1);
	const double 	tol 	= 1.0e-8;
	double 			x2,f0,f1= func_f(x0);
	do{
		f0 	= f1;
		f1 	= func_f(x1);
		//
		x2 	= (x0*f1 - x1*f0)/(f1-f0);
		//
		x0 	= x1;
		x1 	= x2;
	}while(f1*f1>tol*tol);
}