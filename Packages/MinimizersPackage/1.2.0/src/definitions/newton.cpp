#include<assert.h>
#include"MinimizersPackage/deg2_minimizers.h"
#include"FinitediffPackage/finitedifferences.h"

// define g(x) := f'(x)
//
// solve g(x)=0 for x via Newton

void minimize_newton(float(*func_f)(const float&), float& x){
	// warning: may diverge
	// requirements: x0!=x1, x0,x1 , x0,x1 within well-behaved domain
	assert(x0!=x1);
	const float 	tol 		= 1.0e-4;
	const int 		maxit 		= 100;
	//
	auto func_g 	= [&func_f](const float& x){
		return fd_der1(func_f,x);
	};
	//
	auto func_dg 	= [&func_f](const float& x){
		return fd_der2(func_f,x);
	};
	//
	float 			g,dg 		;
	int 			i 			= 0;
	do{
		g 	= func_g(x);
		//
		dg 	= func_dg(x);
		assert(dg!=0.0);
		//
		x 	-= g/dg;
	}while(g*g>tol*tol && ++i<maxit);
}