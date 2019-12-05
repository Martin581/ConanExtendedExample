// iteration schemes for computation of roots for R^1-->R^1 functions

static const float 	pert 	= 1.0e-3;

inline float 	fd_der1(float(*func_f)(const float&),const float& x){
	return 0.5/(pert     ) * ( func_f(x+pert)                   - func_f(x-pert) );
} 	// func_f, x 	, first  derivative

inline float 	fd_der2(float(*func_f)(const float&),const float& x){
	return 1.0/(pert*pert) * ( func_f(x+pert) - 2.0 * func_f(x) + func_f(x-pert) );
} 	// func_f, x 	, second derivative