/*
6. En un concurso (25 participantes) los criterios de calificación son: ropa de
baño, personalidad y traje de noche.
PUNTOS

                    1   2   3   4 ... 23 24 25

1   Ropa Baño
2   Personalidad
3   Traje Noche
    
    TotPun


a. Crear la matriz Puntos, en la que se considera los puntos de cada participante en las tres áreas.
b. Crear el arreglo TotPun con puntaje total para cada participante.
c. Determinar el primer puesto.
d. Si la Miss simpatía se elige por el mayor puntaje en Personalidad, indicar el número de miss simpatía.

Prototipos
Accion llenarM(mPuntos[][25], Entero f, Entero c)
Accion puntajeTotalParticipante(mPuntos[][25], Entero f, Entero c, Entero pTotalPartic[])
Entero Accion hallarPrimerPuesto(Entero c, Entero pTotalPartic[]) //Funcion que me retorna el puntaje del 1er puesto
Entero Acción hallarNumeroMisSimpatia(mPuntos[][25], Entero c)


Accion Principal
DV
  Entero f, c, mPuntos[3][25] //E
  Entero pTotalPartic[], primerPuesto, nMisSim //S
Inicio 
  Leer(f, c)
  llenarM(mPuntos, f, c)
  puntajeTotalParticipante(mPuntos, f, c, pTotalPartic)
  primerPuesto <- hallarPrimerPuesto(c, pTotalPartic)
  nMisSim <- hallarNumeroMisSimpatia(mPuntos, c)
  Escribir(primerPuesto, nMisSim)
Fin

Accion llenarM(mPuntos[][25], Entero f, Entero c)
DV 
  Entero i, j
Inicio 
  Para i desde 1 hasta f Hacer
    Para j desde 1 hasta c Hacer
        Leer(mPuntos[i][j])
    FPara
  FPara
Fin


Accion puntajeTotalParticipante(mPuntos[][25], Entero f, Entero c, Entero pTotalPartic[])
DV
  Entero i, j, sum
Inicio 
  Para j desde 1 hasta c Hacer
    sum <- 0
    Para i desde 1 hasta f Hacer
        sum <- sum + mPuntos[i][j]
    FPara
    pTotalPartic[j] <- sum
  FPara
Fin


Entero Accion hallarPrimerPuesto(Entero c, Entero pTotalPartic[]) //Funcion que me retorna el puntaje del 1er puesto
DV
  Entero j, mayorPuntaje
Inicio 
  mayorPuntaje <- 0
  Para j desde 1 hasta c Hacer
    Si pTotalPartic[j] > mayorPuntaje Entonces 
        mayorPuntaje <- pTotalPartic[j]
    FSi
  FPara
  Retornar mayorPuntaje
Fin



TODO: Para el punto d. hay que tener las cosas claras y entenderlo bien. 

1. Solo voy a enfocarme en la F2, por eso no nececito declarar i, porque sé que i sera siempre 2
y j irá cambiando, por eso j desde 1 hasta c, es decir iremos avanzando por columnas. 
2. Voy a comparar columna por columna de la F2 y de ahi hallar el mayor puntaje 
3. Indico el indice de ese mayor puntaje 
4. El indice lo voy a almacenar en una variable y eso voy a retornar, por lo que usaré una función
No olvides que el indice es un número entero. 


Entero Acción hallarNumeroMisSimpatia(mPuntos[][25], Entero c)
DV
  Entero j, mayorPuntaje, numMis
Inicio
  mayorPuntaje <- 0
  Para j desde 1 hasta c Hacer
    Si mPuntos[2][j] > mayorPuntaje Entonces
      mayorPuntaje <- mPuntos[2][j]
      numMis <- j
    Fsi
  FPara
  Retornar numMis
Fin









*/

