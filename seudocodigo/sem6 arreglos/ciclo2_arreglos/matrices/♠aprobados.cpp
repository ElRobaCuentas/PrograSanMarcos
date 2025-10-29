
//♠ SIGNIFICA ESE TIPO DE PROBLEMA DONDE NO VOY A HALLAR UN "prom" general, sino cuantos promedios hay

/*

Se tiene m alumnos (máximo 50) que llevan n cursos (máximo 6).
Se pide:
a. Guardar las notas obtenidas en un arreglo bidimensional (mxn).
b. Hallar cantidad de notas desaprobatorias
c. Hallar promedio de cada alumno y guardar en arreglo unidimensional
llamado promAlu.
d. Halar el promedio por curso y guardar en arreglo unidimensional
llamado promCur


/Prototipos
Accion llenarNotas(Entero ma[][6], Entero m, Entero n)
Entero Accion notasDesap(Entero ma[][6], Entero m, Entero n)
Accion promAlumno(Entero ma[][6], Entero m, Entero n, promAlu[])
Accion promCurso(Entero ma[][6], Entero m, Entero n, promCur[])
Acción mostrarPromAlu(Real promAlu[], Entero m)
Acción mostrarPromCur(Real promCur[], Entero n)

Accion Principal
DV
    Entero m, n, ma[50][6] //E
    Entero notasD //S
    Real pAlumno, pCurso //S
    
Inicio 
    Leer(m,n)
    llenarNotas(ma[][6], m, n)
    notasD <- notasDesap(ma[][6], m, n)
    promAlumno(ma[][6], m, n, promAlu)
    promCurso(ma[][6], m, n, promCur)
    mostrarPromAlu(promAlu, m)
    mostrarPromCur(promCur, n)
    Escribir(notasD)
    
Fin

Accion llenarNotas(Entero ma[][6], Entero m, Entero n)
DV
    Entero i, j
Inicio
    Para i desde 1 hasta m Hacer
        Para j desde 1 hasta n Hacer
            Leer(ma[i][j])
        FPara
    FPara
Fin


Acción mostrarPromAlu(Real promAlu[], Entero m)
DV 
    Entero i
Inicio
    Para i desde 1 m Hacer
        Escribir(promAlu[i])
    FPara
Fin

Acción mostrarPromCur(Real promCur[], Entero n)
DV 
    Entero j
Inicio
    Para j desde 1 n Hacer
        Escribir(promAlu[j])
    FPara
Fin



Entero Accion notasDesap(Entero ma[][6], Entero m, Entero n)
DV
    Entero i, j, desap
Inicio 
    Para i desde 1 hasta m Hacer
        Para j desde 1 hasta n Hacer
            Si ma[i][j] < 11 Entonces
                desap <- desap + 1
            FSi
        FPara
    FPara
    Retornar desap
Fin

Accion promAlumno(Entero ma[][6], Entero m, Entero n, promAlu[])  //Recueda que m(alumnos) y n(cursos)

TODO: Hay una diferencia entre:
    ? prom -> Es una cantidad
    ? promAlu[i] -> Para i = 1, es el promedio del alumno 1
TODO: Lo que yo quiero es el promedio de los alumnos, es decir, 12+15+10/3=12.333333 y los otros
            Para m = 2 (alumnos) y n = 3(cursos):
-------------------------------------------------------------------
                Curso1       |        Curso2   |     Curso3
    Alumno1: notas[1,1] = 12 | notas[1,2] = 15 | notas[1,3] = 10
    Alumno2: notas[2,1] = 08 | notas[2,2] = 14 | notas[2,3] = 16
--------------------------------------------------------------------
    Para i = 1:
    suma <- 0
    j = 1 → suma <- 0 + 12 = 12
    j = 2 → suma <- 12 + 15 = 27
    j = 3 → suma <- 27 + 10 = 37
    promAlu[1] <- 37 / 3 = 12.333333... (resultado almacenado)

    Para i = 2:
    suma <- 0
    j = 1 → suma <- 0 + 8 = 8
    j = 2 → suma <- 8 + 14 = 22
    j = 3 → suma <- 22 + 16 = 38

    promAlu[2] <- 38 / 3 = 12.666666... (resultado almacenado)


DV
    Entero i, j, sum
Incio 
    Para i desde 1 hasta m Hacer
        sum <- 0
        Para j desde 1 hasta n Hacer //Con suma arriba de j halla el promedio de cada alumno, en orden, osea para i = 1, paso por j = 1,2,..6
            sum <- sum + ma[i][j]
        FPara                        //para i = 1, ya paso por j= 1,2,...6 ahora pasa a la siguiente linea (para hallar el prom de ese alumno)
        promAlu[i] <- sum/n
    FPara
Fin


Real Accion promCurso(Entero ma[][6], Entero m, Entero n, promCur[]) //Recueda que m(alumnos) y n(cursos)

TODO:  Ahora lo que yo quiero es el promedio de cada curso, es decir, 12+8 = 20/2 = 10...
            Para m = 2 (alumnos) y n = 3(cursos):
-------------------------------------------------------------------
                Curso1       |        Curso2   |     Curso3
    Alumno1: notas[1,1] = 12 | notas[1,2] = 15 | notas[1,3] = 10
    Alumno2: notas[2,1] = 08 | notas[2,2] = 14 | notas[2,3] = 16
--------------------------------------------------------------------
    Para j = 1: Curso 1
    suma <- 0
    i = 1 → suma <- 0 + 12 = 12
    i = 2 → suma <- 12 + 08 = 20
    promCurso[j=1] <- 20 / 2 = 10 (resultado almacenado)

    Para j = 2: Curso 2
    suma <- 0
    i = 1 → suma <- 0 + 15 = 15
    i = 2 → suma <- 15 + 14 = 29
    promCurso[j=2] <- 29 / 2 = 14.5 (resultado almacenado)

    Para j = 3: Curso 3
    suma <- 0
    i = 1 → suma <- 0 + 10 = 10
    i = 2 → suma <- 10 + 16 = 26
    promCurso[j=3] <- 26 / 2 = 13 (resultado almacenado)


DV
    Entero i, j, sum
Incio 
    Para j desde 1 hasta n Hacer
        sum <- 0
        Para i desde 1 hasta m Hacer //Con suma arriba de j halla el promedio de cada alumno, en orden, osea para i = 1, paso por j = 1,2,..6
            sum <- sum + ma[i][j]
        FPara                        //para i = 1, ya paso por j= 1,2,...6 ahora pasa a la siguiente linea (para hallar el prom de ese alumno)
        promCur[j] <- sum/m
    FPara
Fin



















*/





