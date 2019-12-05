// iteration schemes for computation of roots for R^1-->R^1 functions

void rootSolve_bisect(float(*)(const float&),float,float,float&); 		// func_f, xL,xR, return x

void rootSolve_newton(float(*)(const float&),float&); 			// func_f, x0, return x1