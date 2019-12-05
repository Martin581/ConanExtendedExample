#include<assert.h>
#include<RootsolversPackage/rootsolvers.h>

void rootSolve_bisect(double(*func_f)(const double&), double xL, double xR, double& x){
	// requirements: xL<xR, f(xL)*f(xR)<0
	const double 	tol 	= 1.0e-4;
	const int 		maxit 	= 10;
	double 			res 	= 2.0*tol;
	const double 	s 		= func_f(xL);
	int 			i 		= 0;
	assert(xL<xR);
	assert(func_f(xL)*func_f(xR)<0.0);
	while(xR-xL>tol && i++<maxit){
		x 	= 0.5*(xL+xR);
		res = func_f(x);
		if(res*s>0.0){
			xL 	= x;
		}else{
			xR 	= x;
		}
	}
}