from conans import ConanFile, CMake
import os
import sys


class MessagingConan(ConanFile):
    name = "libplatformhelpers"
    url = "https://git.gtd-international.com/me_ia/plateforme/libs/libplatformhelpers"
    description = "MeIA Platform Helpers Library"
    requires = ["yaml-cpp/0.7.0"]

    options = {}
    default_options = []
    version = os.environ["VERSION"]
    exports = ["VERSION"]
    settings = "os", "compiler", "build_type", "arch"
    generators = ["cmake_find_package", "cmake_paths"]
    build_policy = "missing"
    license = "© 2022 GTD International SAS"

    def export_sources(self):
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
            "yaml-cpp::yaml-cpp",
        ]
