#include<iostream>
#include"FinitediffPackage/finitedifferences.h"

double func_f     (const double& x){
	// this function has a root between -1 and 1
	return 0.2 * x*x + 5.0 * x -1.1;
}

double func_f_der1(const double& x){
	// this function has a root between -1 and 1
	return 0.4 * x   + 5.0         ;
}

double func_f_der2(const double& x){
	// this function has a root between -1 and 1
	return 0.4                     ;
}

int main(void){
	
	double x 	= 17.2;
	
	std::cout 	<< std::scientific
				<<   "x                  = " 	<< x
				<< "\n--------------------------------------"
				<< "\nf\'(x)              = " 	<< func_f_der1(x)
				<< "\ndq1{f}(x)          = " 	<< fd_der1(func_f,x)
				<< "\n--------------------------------------"
				<< "\nf\'\'(x)             = " 	<< func_f_der2(x)
				<< "\ndq1{f\'(x)}         = " 	<< fd_der1(func_f_der1,x)
				<< "\ndq2{f(x)}          = " 	<< fd_der2(func_f     ,x)
				<< std::endl;
	
	return 0;
}