#include<assert.h>
#include<RootsolversPackage/rootsolvers.h>
#include<FinitediffPackage/finitedifferences.h> 	// external package included as planned

static const float 	fd_pert 	= 1.0e-2;

void rootSolve_newton(float(*func_f)(const float&), float& x){
	// warning: may diverge
	// requirements: x0!=x1, x0,x1 , x0,x1 within well-behaved domain
	const float 	tol 	= 1.0e-4;
	const int 		maxit 	= 10;
	float 			f,df 	;
	int 			i 		= 0;
	//
	auto func_df 	= [&func_f](const float& x){ 
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