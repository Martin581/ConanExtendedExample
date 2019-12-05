#include<assert.h>
#include<RootsolversPackage/rootsolvers.h>

void rootSolve_newton(double(*func_f)(const double&), double& x){
	// warning: may diverge
	// requirement: f'(x)!=0 locally
	assert(x0!=x1);
	const double 	tol 	= 1.0e-8;
	const double 	h 		= 1.0e-5;
	double 			df,f 	;
	do{
		f 	= func_f(x);
		df 	= 0.5/h*(func_f(x+h)-func_f(x-h));
		//
		assert(df!=0.0);
		x 	-= f/df;
	}while(f*f>tol*tol);
}