#include<assert.h>
#include<functional>
#include<RootsolversPackage/rootsolvers.h>
#include<FinitediffPackage/finitedifferences.h>

// you cannot implement a non-specified template function in a compile unit file.

template<>
void rootSolve_newton<float,float>(std::function<float(float const&)> func_f, float& x){
	// warning: may diverge
	// requirements: x0!=x1, x0,x1 , x0,x1 within well-behaved domain
	const float 	tol 	= 1.0e-4;
	const int 		maxit 	= 10;
	float			f,df 	;
	int 			i 		= 0;
	//
	auto func_df 	= [&func_f](const float& x){ 
		return fd_der1<float,float>(func_f,x);
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

template<>
void rootSolve_newton<double,double>(std::function<double(double const&)> func_f, double& x){
	// warning: may diverge
	// requirements: x0!=x1, x0,x1 , x0,x1 within well-behaved domain
	const double 	tol 	= 1.0e-4;
	const int 		maxit 	= 10;
	double			f,df 	;
	int 			i 		= 0;
	//
	auto func_df 	= [&func_f](const double& x){ 
		return fd_der1<double,double>(func_f,x);
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

template<>
void rootSolve_newton<long double,long double>(std::function<long double(long double const&)> func_f, long double& x){
	// warning: may diverge
	// requirements: x0!=x1, x0,x1 , x0,x1 within well-behaved domain
	const long double 	tol 	= 1.0e-4;
	const int 			maxit 	= 10;
	long double			f,df 	;
	int 				i 		= 0;
	//
	auto func_df 	= [&func_f](const long double& x){ 
		return fd_der1<long double,long double>(func_f,x);
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