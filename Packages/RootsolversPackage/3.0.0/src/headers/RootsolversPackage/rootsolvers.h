// iteration schemes for computation of roots for R^1-->R^1 functions
#include<functional>
#include<assert.h>

// un-specific template function definitions must be implemented in header-files.

template<typename Y, typename X> 
inline void rootSolve_bisect(std::function<Y(const X&)> func_f, X xL, X xR, X& x){
	// requirements: xL<xR, f(xL)*f(xR)<0
	const double 	tol 	= 1.0e-4;
	const int 		maxit 	= 10;
	double 			res 	= 2.0*tol;
	const X			s 		= func_f(xL);
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

template<typename Y, typename X> 
void rootSolve_newton(std::function<Y(X const&)>,X&); 			// func_f, return x