import gyro
import numpy as np

x=np.array([0.2,0.1])
y=np.array([0.1,0.3])

z=gyro.mobius_add(x,y)
v=gyro.expmap(x,y)
u=gyro.logmap(x,z)
d=gyro.distance(x,y)
