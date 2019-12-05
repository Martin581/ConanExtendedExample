#include<assert.h>
#include"MinimizersPackage/deg1_minimizers.h"

static const float fd_pert 	= 1.0e-3;

void minimize_secant(float(*func_f)(const float&), float x0, float& x1){
	// warning: may diverge
	// requirements: x0!=x1, x0,x1 , x0,x1 within well-behaved domain
	assert(x0!=x1);
	const float 	tol 		= 1.0e-4;
	const int 		maxit 		= 100;
	//
	auto func_df 	= [&func_f](const float& x){
		return 0.5/fd_pert * ( func_f(x+fd_pert) - func_f(x-fd_pert) );
	};
	//
	float 			x2,df0,df1	= func_df(x0);
	int 			i 			= 0;
	do{
		df0 	= df1;
		df1 	= func_df(x1);
		//
		x2 	= (x0*df1 - x1*df0)/(df1-df0);
		//
		x0 	= x1;
		x1 	= x2;
	}while(df1*df1>tol*tol && ++i<maxit);
}