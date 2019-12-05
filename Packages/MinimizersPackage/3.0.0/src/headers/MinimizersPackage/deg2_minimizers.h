#include<FinitediffPackage/finitedifferences.h>
#include<RootsolversPackage/rootsolvers.h>

// define g(x) := f'(x)
//
// solve g(x)=0 for x via Newton

template<typename Y,typename X>
inline void minimize_newton(Y(*func_f)(const X&), X& x){
	// warning: may diverge
	std::function<Y(const X&)> 	func_g 	= [&func_f](const X& x){
		return fd_der1<Y,X>(func_f,x);
	};
	rootSolve_newton<Y,X>(func_g,x);
}