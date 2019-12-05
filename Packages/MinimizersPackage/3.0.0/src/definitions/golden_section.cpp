#include<assert.h>
#include<cmath>
#include<MinimizersPackage/deg0_minimizers.h>

void minimize_golden(double(*func_f)(const double&), double xL, double xR, double& x0){
	// requirements: xL<xR, func_f convex
	assert(xL<xR);
	const double 	tol 	= 1.0e-4;
	const double 	gr 		= 0.5+0.5*std::sqrt(5.0); 	// golden ratio
	double 			x1,f0,f1	;
	//
	x0 			= xR - (xR-xL)/gr;
	x1 			= xL + (xR-xL)/gr;
	f0 			= func_f(x0);
	f1 			= func_f(x1);
	//
	while(xR-xL>tol){
		if( f0 < f1 ){
			xR 			= x1;
			x1 			= x0;
			f1 			= f0;
			x0 			= xR - (xR-xL)/gr;
			f0 			= func_f(x0);
		}else{
			xL 			= x0;
			x0 			= x1;
			f0 			= f1;
			x1 			= xL + (xR-xL)/gr;
			f1 			= func_f(x1);
		}
	}
}