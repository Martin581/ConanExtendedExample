// iteration schemes for computation of roots for R^1-->R^1 functions
#include<functional>

static const long double 	pert 	= 1.0e-5;

// force type-cast
template<typename T> inline long double operator+(const T& rhs1, const long double& rhs2){
	return (T)(rhs1+rhs2);
}
template<typename T> inline long double operator-(const T& rhs1, const long double& rhs2){
	return (T)(rhs1+rhs2);
}

template<typename Y, typename X>
inline Y 	fd_der1(std::function<Y(const X&)> func_f,const X& x){
	return 0.5/(pert     ) * ( func_f(x+pert)                   - func_f(x-pert) );
} 	// func_f, x 	, first  derivative

template<typename Y, typename X>
inline Y 	fd_der2(std::function<Y(const X&)> func_f,const X& x){
	return 1.0/(pert*pert) * ( func_f(x+pert) - 2.0 * func_f(x) + func_f(x-pert) );
} 	// func_f, x 	, second derivative