
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include "gyro/api.hpp"

namespace py=pybind11;

PYBIND11_MODULE(gyro, m)
{
    m.def("mobius_add",&gyro::mobius_add);
    m.def("mobius_scalar",&gyro::mobius_scalar);
    m.def("expmap",&gyro::expmap);
    m.def("logmap",&gyro::logmap);
    m.def("distance",&gyro::distance);
}
