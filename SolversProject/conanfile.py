from conans import ConanFile, CMake


class SolversProject(ConanFile):
    name = "SolversProject"
    version = "1.0.0"
    license = "none"
    author = "Martin no@thanks.com"
    description = "A conan test project that uses various versions of three packages, respectively"
    requires = "RootsolversPackage/[>=1]","MinimizersPackage/[>=1]"
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
        self.copy("*.h", dst="include/FinitediffPackage", src="src/headers/FinitediffPackage")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["finitedifferences"] 	# this thing must have the name of the *.h-file .
