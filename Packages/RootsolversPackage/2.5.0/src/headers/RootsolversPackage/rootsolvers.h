// iteration schemes for computation of roots for R^1-->R^1 functions

void rootSolve_bisect(double(*)(const double&),double,double,double&); 		// func_f, xL,xR, return x

void rootSolve_newton(double(*)(const double&),double&); 			// func_f, x0, return x1