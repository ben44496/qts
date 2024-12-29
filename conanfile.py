from conan import ConanFile
from conan.tools.cmake import cmake_layout

class QuantTradingSuite(ConanFile):
    generators = ("CMakeDeps", "CMakeToolchain")
    settings = ("os", "compiler", "build_type", "arch")
    name = "QuantTradingSuite"

    def requirements(self):
        self.requires("boost/1.86.0")
        self.requires("fmt/11.0.2")
        self.requires("libuuid/1.0.3")
        self.requires("eventpp/0.1.3")
        self.requires("spdlog/1.15.0")

    def build_requirements(self):
        self.tool_requires("cmake/[>=3.25]")

    # def layout(self):
    #     cmake_layout(self)