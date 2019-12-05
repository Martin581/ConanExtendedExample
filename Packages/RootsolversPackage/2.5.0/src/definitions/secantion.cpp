#include<assert.h>
#include<RootsolversPackage/rootsolvers.h>
#include<functional>

void rootSolve_secant(std::function<double(const double&)>func_f, double x0, double& x1){
	// warning: may diverge
	// requirements: x0!=x1, x0,x1 , x0,x1 within well-behaved domain
	assert(x0!=x1);
	const double 	tol 	= 1.0e-8;
	const int 		maxit 	= 10;
	double 			x2,f0,f1= func_f(x0);
	int 			i 		= 0;
	do{
		f0 	= f1;
		f1 	= func_f(x1);
		//
		x2 	= (x0*f1 - x1*f0)/(f1-f0);
		//
		x0 	= x1;
		x1 	= x2;
	}while(f1*f1>tol*tol && ++i<maxit);
}