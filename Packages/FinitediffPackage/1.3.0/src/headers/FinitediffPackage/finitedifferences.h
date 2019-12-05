// iteration schemes for computation of roots for R^1-->R^1 functions
#include<functional>

static const double 	pert 	= 1.0e-5;

inline double 	fd_der1(std::function<double(const double&)> func_f,const double& x){
	return 0.5/(pert     ) * ( func_f(x+pert)                   - func_f(x-pert) );
} 	// func_f, x 	, first  derivative

inline double 	fd_der2(std::function<double(const double&)> func_f,const double& x){
	return 1.0/(pert*pert) * ( func_f(x+pert) - 2.0 * func_f(x) + func_f(x-pert) );
} 	// func_f, x 	, second derivative