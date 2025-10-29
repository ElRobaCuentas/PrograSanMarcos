#TEST MOVIMIENTO 1D
#Notebook sobre movimiento, velocidad y acelaracion

import numpy as np
import matplotlib.pyplot as plt

# x = A*t^2 + B*t + C
# x = 1/2*a*t^2 + vo*t * xo

#PARA 15g
A = -0.358
B = -0.172
C = 1.023

a = 2*A
print("Para la masa de 15g")
print(f"La aceleracion es: {a}")

#PARA 20g

A1 = -0.361
B1 = -0.146
C1 = 1.021

a1 = 2*A1
print("-----------------------------------------------------")
print("Para la masa de 20g")
print(f"La aceleracion es: {a1}")

#PARA 25g

A2 = -0.5
B2 = -0.28
C2 = 1.039

a2 = 2*A2
print("-----------------------------------------------------")
print("Para la masa de 25g")
print(f"La aceleracion es: {a2}")

