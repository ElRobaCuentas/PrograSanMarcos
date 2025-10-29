#TEST PENDULO
#Notebook sobre el pendulo

import numpy as np
import matplotlib.pyplot as plt


# --- Variables ---
A = 1.204
B = 3.070
C = -1.418
D = 2.096

DW = 0.002

#gravedad

#1
W = 3.070
L = 1.0 

g = W**2*L
print(f"La gravedad es: {g}")

Dg = (np.sqrt(2)*(DW / W))*g
print(f"La desviación de la gravedad es: {Dg}")

print(f"g = {g:.3f} ± {Dg:.3f} m/s^2")




