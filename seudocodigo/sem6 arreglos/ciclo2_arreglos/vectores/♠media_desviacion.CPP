
//♠SIGNIFICA ESE TIPO DE PROBLEMA DONDE NO VOY A HALLAR UN "prom" general, sino cuantos promedios hay. En este caso modas. 

/*

Dado un arreglo unidimensional de enteros que contienen las calificaciones de
un grupo de n alumnos (máximo 30) de un determinado examen, calcule lo
siguiente:
• La media aritmética. Esta se calcula como la suma de elementos entre el
número de elementos.
• La varianza. Esta se calcula como la suma de los cuadrados de las
desviaciones de la media, entre el número de elementos.
• La desviación estándar. Esta se calcula como la raíz cuadrada de la varianza.
• La moda. Esta se calcula obteniendo el número que más frecuencia tiene.

Media(M) = Sumatoria desde i = 0 hasta n de (Xi) / n 
Varianza (V) = Sumatoria desde i = 0 hasta n de (Xi – M)2 / n 
Estándar (D) = raiz cuadrada de V


/Prototipos
Accion llenarV(Entero notas[], Entero n)
Real Accion mediaArit(Entero notas[], Entero n)
Real Accion varianza(Entero notas[], Entero n, Real mediaA)
Real Accion desviacionEstandar(Real var)
Accion moda(Entero notas[], Entero n)

Accion Principal 
DV
  Entero n, notas[30] //E
  Entero moda
  Real mediaA, var, desvEst //S
Inicio 
  Leer(n)
  llenarV(notas, n)
  mediaA <- mediaArit(notas, n)
  var <- varianza(notas, n, mediaA)
  desvEst <- desviacionEstandar(var)
  moda(notas, n, moda)
  Escribir(mediaA, var, desvEst, mod)
Fin

Accion llenarV(Entero notas[], Entero n)
DV
  Entero i
Inicio 
  Para i desde 1 hasta n Hacer
    Leer(notas[i])
  FPara
Fin

Real Accion mediaArit(Entero notas[], Entero n)
DV
  Entero i, sum
  Real prom
Inicio 
  sum <- 0
  Para i desde 1 hasta n Hacer
    sum <- sum + notas[i]
  FPara
  prom <- 1.0*sum/n
  Retornar prom
Fin

Real Accion varianza(Entero notas[], Entero n, Real mediaA)
DV
  Entero i
  Real sum, var
Inicio  
  sum <- 0 
  Para i desde 1 hasta n Hacer
    sum <- sum + (notas[i] - mediaA)**2 
  FPara
  var <- 1.0*sum/n
  Retornar var
Fin

Real Accion desviacionEstandar(Real var)
DV
  Real desv
Inicio
  desv <- var**0.5 
  Retornar desv
Fin


/
la nota con mas frecuencia, y va a retornar esa nota. 

TODO: Primero que nada puede haber mas de una moda, por ende lo trabajas como procedimiento.
TODO: La lógica de esto es la siguiente:
  Tener en cuenta que voy a tener dos variables que me van a servir como contador.
  Una de ellas es para contar la cantidad de veces que se repite un numero dentro del arreglo y la otra
  es para decir cual de esos numeros es el que se repite mas, y ojo, pueden ser mas de dos. 

  Entonces, lo que haremos es trabajar con dos bucles anidados(bucles Para), entonces usaremos notas[i] 
  para que sea el elemento actual del bucle externo y notas[j] para el elemento actual del bucle externo
  (para comparar con notas[i]). 
  Entonces, i recorre cada nota(posicion principal) y j recorre todo el arreglo para comparar
  Tambien usaremos dos variables importantes, que son maxCont y cont. 
  cont se usará para contar cuantas veces se repite notas[i], y esto estará dentro del ciclo i, porque 
  cada nota tiene su propio conteo y maxCont guarda el numero maximo de repeticiones encontradas hasta
  ahora y estará antes del ciclo i, porque almacena el maximo "global" encontrado. 
  Una vez acabe un ciclo, por ejemplo para i=1, entonces voy a comparar cont > maxCont, y si es asi, 
  entonces a cont le asigno maxCont (maxCont <- cont) y hasta ese entonces, para notas[1], la cantidad
  veces que se repite, sea uno o mas, será el mayor, hasta ese entonces, y a ese valor le asigno la moda.
  notas[1] para i = 1 será la moda, ojo, solo para i = 1, porque faltaria recorrer los demas indices y 
  comparar i con j.

  - Para cont: cont cuenta las repeticiones de una sola nota(la que está en notas[i])
    Entonces, cada vez que cambiamos de nota principal (i) debemos empezar desde 0.
      Si i = 1 -> notas[1] = 12 -> cont contará cuántas veces aparece el 12
      Luego i = 2 -> notas[2] = 14 -> cont debe reiniciarse a 0 para contar cuántas veces aparece el 14



  Ejemplo: notas[10] = [12, 14, 15, 12, 16, 14, 14, 15, 12, 11]

Accion moda(Entero notas[], Entero n, Entero &moda)
DV
  Entero i, j, cont, maxCont
Inicio
  maxCont <- 0 
  Para i desde 1 hasta n Hacer
    cont <- 0 
    Para j desde 1 a n Hacer             /Vamos a comparar todos los j, y 12 se repite 3 veces
      Si notas[i] = notas[j] Entonces    /entonces cont = 3 y maxCont = 0, comparamos y es verdad,...
        cont <- cont + 1
      FSi
    FPara

    /de aca sale con cont = 3 y baja

    Si cont > contMax Entonces
      maxCont <- cont
      moda <- notas[i]
    FSi
  FPara
Fin

  /Termina y vuelve para i = 2, pero antes recordar que maxCont = 3 y moda = 12 (para i = 1)
  ? maxCont se actualiza solo una vez por número, justo despues de contar todas sus repeticiones
  ? luego se mantiene igual hasta que encuentre un número con más repeticiones. 

    de aca vuelve a //TODO: Para i desde 1 hasta n Hacer






*/