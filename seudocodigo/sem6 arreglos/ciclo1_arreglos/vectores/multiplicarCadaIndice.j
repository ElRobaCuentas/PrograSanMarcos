Almacene en un vector A de 10 elementos, luego ingrese un numero por el teclado que multiplique por cada 
elemento del vector A y lo guarde en un nuevo vector llamado NUEVOA. 


//Prototipos
Accion llenarV(Entero v[], Entero n)
Accion mostrarNuevoA(Entero n, Entero A[], Entero NUEVOA[])
Accion mostrarV(Entero v[], Entero n)

Accion Principal 
DV
  Entero n, A[10] //E
  Entero NUEVOA[10] //S
Inicio
  Leer(n)
  llenarV(A, n)
  mostrarNuevoA(Entero n, Entero A[], Entero NUEVOA[])
  mostrarV(NUEVOA, n)
Fin

Accion llenarV(Entero v[], Entero n)
DV
  Entero i
Inicio 
  Para i desde 1 a n Hacer
    Leer(v[i])
  FPara
Fin

Accion mostrarV(Entero v[], Entero n)
DV
  Entero i
Inicio 
  Para i desde 1 a n Hacer
    Escribir(v[i])
  FPara
Fin

Accion mostrarNuevoA(Entero n, Entero A[], Entero NUEVOA[])
DV
  Entero i
Inicio
  Para i desde 1 a n Hacer
    NUEVOA[i] = A[i] * num
  FPara
Fin

----------------------------------------------------- 

Duda, estoy usando a n como el numero que multiplica, pero tambien es el tamaño de mi arreglo.
Eso está mal, deben separarse, por ejemplo: 
n -> tamaño del vector
num -> numero que multiplica

ACLARADO CON [1.DUDAS]

**MAL**

//Prototipos
Accion llenarV(Entero v[], Entero n)
Accion mostrarNuevoA(Entero n, Entero A[], Entero NUEVOA[])

Accion Principal 
DV
  Entero n, A[10] //E
  Entero NUEVOA[10] //S
Inicio
  Leer(n)
  llenarV(A, n)
  mostrarNuevoA(Entero n, Entero A[], Entero NUEVOA[])
Fin

Accion llenarV(Entero v[], Entero n)
DV
  Entero i
Inicio 
  Para i desde 1 a n Hacer
    Leer(v[i])
  FPara
Fin

Accion mostrarNuevoA(Entero n, Entero A[], Entero NUEVOA[])
DV
  Entero i
Inicio
  Para i desde 1 a n Hacer
    NUEVOA[i] = A[i] * n
  FPara
Fin