#include <cuda_runtime.h>
#include <cmath>

__global__ void mobius_kernel(const double* A,
                             const double* B,
                             double* C,
                             int D, double s)
{
    int i = blockIdx.x;
    int j = threadIdx.x;

    extern __shared__ double buf[];

    double* u = buf;
    double* v = buf + D;

    if(j < D){
        u[j] = A[i*D + j];
        v[j] = B[i*D + j];
    }
    __syncthreads();

    double u2 = 0, v2 = 0, uv = 0;
    for(int k=0;k<D;k++){
        u2 += u[k]*u[k];
        v2 += v[k]*v[k];
        uv += u[k]*v[k];
    }

    double s2 = s*s;
    double A0 = 1 + 2*uv/s2 + v2/s2;
    double B0 = 1 - u2/s2;
    double D0 = 1 + 2*uv/s2 + (u2*v2)/(s2*s2);

    if(j < D){
        C[i*D + j] = (A0*u[j] + B0*v[j]) / D0;
    }
}

extern "C"
void mobius_add_cuda(const double* A,
                     const double* B,
                     double* C,
                     int N, int D, double s)
{
    mobius_kernel<<<N,D,2*D*sizeof(double)>>>(A,B,C,D,s);
}
