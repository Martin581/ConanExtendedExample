from conans import ConanFile, CMake


class RootSolvers(ConanFile):
    name = "RootsolversPackage"
    version = "2.5.0"
    license = "none"
    author = "Martin no@thanks.com"
    description = "root solvers for 1D functions, conan exercise; uses finite differences package in double precision"
    settings = "cppstd", "os", "compiler", "build_type", "arch"
    requires = "FinitediffPackage/[~=1 >=1.2]"   # std::function only supported from minor version 1
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"
    exports_sources = "src/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")     # in src must be a makefile.
        cmake.build()

    # def source(self) # this routine can be used if there are sources available, e.g. in git or svn

    def package(self):
        self.copy("*.h", dst="include/RootsolversPackage", src="src/headers/RootsolversPackage")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["rootsolvers"] 	# this thing must have the name of the *.h-file .
