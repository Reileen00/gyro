import gyro
import numpy as np

x=np.array([0.2,0.1])
y=np.array([0.1,0.3])

z=gyro.mobius_add(x,y)
v=gyro.expmap(x,y)
u=gyro.logmap(x,z)
d=gyro.distance(x,y)


A = np.random.randn(100000,3)*0.1
B = np.random.randn(100000,3)*0.1

C = gyro.mobius_add_cuda(A,B,1.0)
