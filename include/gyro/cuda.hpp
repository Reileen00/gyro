#pragma once
#include <Eigen/Dense>

namespace gyro {
    void mobius_add_cuda(const double* A,
                         const double* B,
                         double* C,
                         int N, int D, double s);
}
