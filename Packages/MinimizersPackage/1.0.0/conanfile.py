from conans import ConanFile, CMake


class Minimizers(ConanFile):
    name = "MinimizersPackage"
    version = "1.0.0"
    license = "none"
    author = "Martin no@thanks.com"
    description = "minimization solvers for 1D convex functions, conan exercise; golden_section and secant on derivative"
    settings = "cppstd", "os", "compiler", "build_type", "arch"
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
        self.copy("*.h", dst="include/MinimizersPackage", src="src/headers/MinimizersPackage")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["minimizers"] 	# this thing must have the name of the main *.h-file .
