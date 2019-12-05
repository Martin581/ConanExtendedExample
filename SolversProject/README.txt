To build the project, follow these steps:

1) Aquire recipes of 
	-	RootsolversPackage/[>=1]
	-	MinimizersPackage/[>=1]
	1.1) This can be achieved by calling "conan create ." within the package folder (i.e. "C:\...\Packagename\M.m.p", where M.m.p is the semver).

2) In the path of this README, call "mkdir build && cd build && conan install . && conan build ."