from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "gyro",
        ["src/bindings.cpp"],
        include_dirs=["include"],
    ),
]

setup(
    name="gyro",
    version="0.1",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
)
