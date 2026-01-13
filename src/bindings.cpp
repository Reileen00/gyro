
// #include <pybind11/pybind11.h>
// #include <pybind11/eigen.h>
// #include "gyro/api.hpp"

// namespace py=pybind11;

// PYBIND11_MODULE(gyro, m)
// {
//     m.def("mobius_add",&gyro::mobius_add);
//     m.def("mobius_scalar",&gyro::mobius_scalar);
//     m.def("expmap",&gyro::expmap);
//     m.def("logmap",&gyro::logmap);
//     m.def("distance",&gyro::distance);
// }

#include <pybind11/numpy.h>
#include "gyro/cuda.hpp"

m.def("mobius_add_cuda",[](py::array_t<double> A,
                          py::array_t<double> B,
                          double s){
    auto bufA = A.request(), bufB = B.request();
    int N = bufA.shape[0];
    int D = bufA.shape[1];

    auto C = py::array_t<double>({N,D});

    gyro::mobius_add_cuda(
        (double*)bufA.ptr,
        (double*)bufB.ptr,
        (double*)C.request().ptr,
        N,D,s
    );
    return C;
});
