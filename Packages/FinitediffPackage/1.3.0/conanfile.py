from conans import ConanFile, CMake


class FiniteDifferences(ConanFile):
    name = "FinitediffPackage"
    version = "1.3.0"
    license = "none"
    author = "Martin no@thanks.com"
    description = "finite differences of second order for first and second derivatives, header-only; virtually the same as version 1.2"
    settings = "cppstd", "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"
    exports_sources = "src/*"
    no_copy_source = True

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")     # in src must be a makefile.
        cmake.build()

    # def source(self) # this routine can be used if there are sources available, e.g. in git or svn

    def package(self):
        self.copy("*.h", dst="include/FinitediffPackage", src="src/headers/FinitediffPackage")
        # self.copy("*.lib", dst="lib", keep_path=False)
        # self.copy("*.dll", dst="bin", keep_path=False)
        # self.copy("*.dylib*", dst="lib", keep_path=False)
        # self.copy("*.so", dst="lib", keep_path=False)
        # self.copy("*.a", dst="lib", keep_path=False)

    def package_id(self):
        self.info.header_only()

    #def package_info(self):
        # self.cpp_info.libs = ["finitedifferences"] # there are no links to be set.
