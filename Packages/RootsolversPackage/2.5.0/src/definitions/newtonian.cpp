#include<assert.h>
#include<RootsolversPackage/rootsolvers.h>
#include<FinitediffPackage/finitedifferences.h>
#include<functional>

void rootSolve_newton(std::function<double(const double&)>func_f, double& x){
	// warning: may diverge
	// requirement: f'(x)!=0 locally
	assert(x0!=x1);
	const double 	tol 	= 1.0e-8;
	const int 		maxit 	= 10;
	double 			df,f 	;
	int 			i 		= 0;
	do{
		f 	= func_f(x);
		df 	= fd_der1<double,double>(func_f,x);
		//
		assert(df!=0.0);
		x 	-= f/df;
	}while(f*f>tol*tol && ++i<maxit);
}