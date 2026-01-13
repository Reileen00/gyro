#pragma once
#include "mobius.hpp"

namespace gyro {

inline double distance(const Eigen::VectorXd& u,
                       const Eigen::VectorXd& v,
                       double s=1.0)
{
    Eigen::VectorXd d=mobius_add(-u,v,s);
    double n=d.squaredNorm();
    double u2=u.squaredNorm();
    double v2=v.squaredNorm();

    double arg=1+2*n/((s*s-u2)*(s*s-v2));
    return s*std::acosh(arg);
}

}
