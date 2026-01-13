#pragma once
#include <Eigen/Dense>
#include <cmath>

namespace gyro {

inline Eigen::VectorXd mobius_add(const Eigen::VectorXd& u,
                                  const Eigen::VectorXd& v,
                                  double s=1.0)
{
    double u2=u.squaredNorm();
    double v2=v.squaredNorm();
    double uv=u.dot(v);
    double s2=s*s;

    double A=1+2*uv/s2+v2/s2;
    double B=1-u2/s2;
    double D=1+2*uv/s2+(u2*v2)/(s2*s2);

    return (A*u + B*v)/D;
}

inline Eigen::VectorXd mobius_neg(const Eigen::VectorXd& v){
    return -v;
}

inline Eigen::VectorXd mobius_scalar(double r,
                                     const Eigen::VectorXd& v,
                                     double s=1.0)
{
    double n=v.norm();
    if(n<1e-12) return v;
    double mag=s*std::tanh(r*std::atanh(n/s));
    return (mag/n)*v;
}

}
