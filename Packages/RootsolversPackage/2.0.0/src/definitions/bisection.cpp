#include<assert.h>
#include<RootsolversPackage/rootsolvers.h>

void rootSolve_bisect(float(*func_f)(const float&), float xL, float xR, float& x){
	// requirements: xL<xR, f(xL)*f(xR)<0
	const float 	tol 	= 1.0e-4;
	const int 		maxit 	= 10;
	float 			res 	= 2.0*tol;
	const float 	s 		= func_f(xL);
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