#pragma once
#include "mobius.hpp"

namespace gyro {

inline Eigen::VectorXd expmap(const Eigen::VectorXd& p,
                              const Eigen::VectorXd& v,
                              double s=1.0)
{
    double p2=p.squaredNorm();
    double lambda=2.0/(1.0-p2/s/s);
    double nv=v.norm();
    if(nv<1e-12) return p;

    Eigen::VectorXd u=std::tanh(nv/lambda)*(v/nv);
    return mobius_add(p,u,s);
}

inline Eigen::VectorXd logmap(const Eigen::VectorXd& p,
                              const Eigen::VectorXd& q,
                              double s=1.0)
{
    Eigen::VectorXd d=mobius_add(-p,q,s);
    double nd=d.norm();
    if(nd<1e-12) return d;

    double p2=p.squaredNorm();
    double lambda=2.0/(1.0-p2/s/s);
    return (2.0/lambda)*std::atanh(nd)*d/nd;
}

}
