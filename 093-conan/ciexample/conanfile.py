from conans import ConanFile, CMake
import os
import sys

class MessagingConan(ConanFile):
    name = "helloworld"
    version = os.environ['VERSION']
    license = "GNU Beer"
    url = "https://gitlab.com/rodolfoap/ciexample"
    description = "Example"
    settings = "os", "compiler", "build_type", "arch"
    options = {}
    default_options = []
    generators = ["cmake_find_package", "cmake_paths"]
    build_policy = "missing"
    requires = [ "nlohmann_json/3.9.1" ]

    exports = ["VERSION"]

    def export_sources(self):
        # Exclude large directories
        self.copy("*", excludes=("*build*",))

    def configure(self):
        pass

    def source(self):
        pass

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder=".", defs={"IS_BUILDING_FROM_CONAN": "ON"})
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.configure(source_folder=".", defs={"IS_BUILDING_FROM_CONAN": "ON"})
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = [
            "HelloWorld",
            "nlohmann_json::nlohmann_json",
        ]
