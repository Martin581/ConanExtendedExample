#include<assert.h>
#include<functional>
#include<RootsolversPackage/rootsolvers.h>
#include<FinitediffPackage/finitedifferences.h>

static const double 	fd_pert 	= 1.0e-2;

void rootSolve_newton(std::function<double(const double&)> func_f, double& x){
	// warning: may diverge
	// requirements: x0!=x1, x0,x1 , x0,x1 within well-behaved domain
	const double 	tol 	= 1.0e-4;
	const int 		maxit 	= 10;
	double 			f,df 	;
	int 			i 		= 0;
	//
	auto func_df 	= [&func_f](const double& x){ 
		return fd_der1(func_f,x);
	};
	//
	do{
		f 	= func_f(x);
		//
		df 	= func_df(x);
		assert(df!=0.0);
		//
		x 	-= f/df;
	}while(f*f>tol*tol && ++i<maxit);
}