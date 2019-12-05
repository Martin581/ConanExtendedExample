#include<iostream>
#include"FinitediffPackage/finitedifferences.h"

long double func_f     (const long double& x){
	// this function has a root between -1 and 1
	return 0.2 * x*x + 5.0 * x -1.1;
}

long double func_f_der1(const long double& x){
	// this function has a root between -1 and 1
	return 0.4 * x   + 5.0         ;
}

long double func_f_der2(const long double& x){
	// this function has a root between -1 and 1
	return 0.4                     ;
}

int main(void){
	
	long double x 	= 17.2;
	
	std::cout 	<< std::scientific
				<<   "x                  = " 	<< x
				<< "\n--------------------------------------"
				<< "\nf\'(x)              = " 	<< func_f_der1(x)
				<< "\ndq1{f}(x)          = " 	<< fd_der1<long double,long double>(func_f,x)
				<< "\n--------------------------------------"
				<< "\nf\'\'(x)             = " 	<< func_f_der2(x)
				<< "\ndq1{f\'(x)}         = " 	<< fd_der1<long double,long double>(func_f_der1,x)
				<< "\ndq2{f(x)}          = " 	<< fd_der2<long double,long double>(func_f     ,x)
				<< std::endl;
	
	return 0;
}