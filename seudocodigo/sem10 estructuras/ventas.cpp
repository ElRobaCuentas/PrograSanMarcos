/*

1. En la empresa Pris S.A. se debe guardar el código, nombre y apellido, género,
año de ingreso, monto de ventas y sueldo de cada empleado. Se pide:
a. Almacenar los datos de los n empleados (máximo 100) en un arreglo de
estructuras (no se ingresa el sueldo).
b. Mostrar cuántas empleadas hay en la empresa.
c. Calcular y guardar el sueldo sabiendo que es el 10% del monto vendido.
d. ¿Cuál es el sueldo promedio en la empresa?
e. ¿Cuántos trabajadores tienen un sueldo inferior al promedio?
f. Eliminar a trabajador despedido de empresa, su posición en arreglo será indicada por el usuario.


//SEUDOCODIGO:

//Estructuras

Estructura Empleados
    Cadena nombre
    Cadena apellido
    Entero codigo
    Caracter genero
    Entero anioIngreso 
    Real sueldo
    Real montoVentas  //el monto de ventas es el acumulativo del total de ventas que vendio. S/.800
FEstructura




//Prototipos
Accion llenarVEst(Empleados datos[], Entero c) //a
Entero cantEmplMujeres(Empleados datos[], Entero c)  //b
Accion hallarSueldo(Empleados datos[], Entero c) //c
Real Accion hallarSueldoPromEmpresa(Empleados datos[], Entero c) //d
Entero Accion hallarSueldoMenorProm(Empleados datos[], Entero c) //e
Accion eliminarEmpleado(Empleados datos[], Entero &c) //f






//Accion Principal
DV
  Entero c
  Entero empleadas, sueldoMenorP
  Real promE
  Empleados datos[100]

Inicio 
  Leer(c)
  llenarVEst(datos, c)
  empleadas <- cantEmplMujeres(datos, c)
  hallarSueldo(datos[], c)
  promE <- hallarSueldoPromEmpresa(datos, c)
  sueldoMenorP <- hallarSueldoMenorProm(datos, c)
  eliminarEmpleado(datos, c)

  Escribir(empleadas, promE, sueldoMenorP, c)  //c tiene otro valor
Fin


Accion llenarVEst(Empleados datos[], Entero c)
DV
  Entero i
Inicio
  Para i desde 1 hasta c Hacer
    Leer(datos[i].nombre)
    Leer(datos[i].apellido)
    Leer(datos[i].codigo)
    Leer(datos[i].genero)
    Leer(datos[i].anioIngreso)
    Leer(datos[i].montoVentas)
  FPara
Fin


Entero cantEmplMujeres(Empleados datos[], Entero c)
DV 
  Entero i, cant
Inicio 
  cant <- 0
  Para i desde 1 hasta c Hacer
    Si datos[i].genero = 'F' Entonces
        cant <- cant + 1
    FSi
  FPara
  Retornar cant
Fin


TODO: Por ahora el arreglo en momoria:
Índice	código	nombre	ventas	sueldo
1	    101	    Ana	    8000	—
2	    102	    Luis	5000	—
3	    103	    Carla	10000	—




Accion hallarSueldo(Empleados datos[], Entero c) //c RECUERDA QUE LOS ARREGLOS SE PASAN COMO REFERENCIA, POR ESO EL ARREGLO DATOS, LUEGO DE ALMACENAR LOS SUELDOS SE MODIFICA. 
DV
  Entero i
Inicio   
  Para i desde 1 hasta c Hacer
    datos[i].sueldo <- datos[i].montoVentas*0.1
  FPara
Fin

TODO: Despues de guardar los sueldos:
Índice	código	nombre	ventas	sueldo
1	    101	    Ana	    8000	800
2	    102	    Luis	5000	500
3	    103	    Carla	10000	1000


Real Accion hallarSueldoPromEmpresa(Empleados datos[], Entero c)
DV
  Entero i
  Real prom, sum                //si sum fuera entero, estaria dividiendo entero / entero = real? NO
Inicio 
  sum <- 0
  Para i desde 1 hasta c Hacer
    sum <- sum + datos[i].sueldo
  FPara
  prom <- sum / c
  Retornar prom
Fin


Entero Accion hallarSueldoMenorProm(Empleados datos[], Entero c, Real promE)
DV 
  Entero i, cant
Inicio
  cant <- 0
  Para i desde 1 hasta c Hacer
    Si datos[i].sueldo < promE Entonces
      cant <- cant + 1
    FSi
  FPara
  Retornar cant
Fin


Accion eliminarEmpleado(Empleados empresa[], Entero &c)
DV
    Entero i, p
Inicio
    Leer(p)
    Para i desde p hasta c - 1 Hacer
        empresa[i] <- empresa[i + 1]
    FPara
    c <- c - 1
Fin


TODO: 

p=3
c=5

i = 3	    empresa[3] <- empresa[4]	      copia a Pedro sobre Carla
i = 4	    empresa[4] <- empresa[5]	      copia a Sofía sobre Pedro
fin	      n <- c - 1	                    arreglo queda con 4 elementos





//CODIGO: 


*/


// #include <iostream>
// #include <string>
// using namespace std;

// struct Empleados {
//     string nombre;
//     string apellido;
//     int codigo;
//     char genero;
//     int anioIngreso;
//     float sueldo;
//     float montoVentas;
// };

// void llenarVEst(Empleados datos[], int c);
// int cantEmplMujeres(Empleados datos[], int c);
// void hallarSueldo(Empleados datos[], int c);
// float hallarSueldoPromEmpresa(Empleados datos[], int c);
// int hallarSueldoMenorProm(Empleados datos[], int c, float promE);
// void eliminarEmpleado(Empleados datos[], int &c);

// int main() {
//     int c, empleadas, sueldoMenorP;
//     float promE;
//     Empleados datos[100];

//     cin >> c;
//     llenarVEst(datos, c);
//     empleadas = cantEmplMujeres(datos, c);
//     hallarSueldo(datos, c);
//     promE = hallarSueldoPromEmpresa(datos, c);
//     sueldoMenorP = hallarSueldoMenorProm(datos, c, promE);
//     eliminarEmpleado(datos, c);
//     cout << empleadas << endl;
//     cout << promE << endl;
//     cout << sueldoMenorP << endl;
//     cout << c << endl;

//     return 0;
// }

// void llenarVEst(Empleados datos[], int c) {
//     for (int i = 0; i < c; i++) {
//         cin >> datos[i].nombre;
//         cin >> datos[i].apellido;
//         cin >> datos[i].codigo;
//         cin >> datos[i].genero;
//         cin >> datos[i].anioIngreso;
//         cin >> datos[i].montoVentas;
//     }
// }

// int cantEmplMujeres(Empleados datos[], int c) {
//     int cant = 0;
//     for (int i = 0; i < c; i++) {
//         if (datos[i].genero == 'F') 
//             cant++;
//     }
//     return cant;
// }

// void hallarSueldo(Empleados datos[], int c) {
//     for (int i = 0; i < c; i++) {
//         datos[i].sueldo = datos[i].montoVentas * 0.10;
//     }
// }

// float hallarSueldoPromEmpresa(Empleados datos[], int c) {
//     float sum = 0, prom;
//     for (int i = 0; i < c; i++) {
//         sum = sum + datos[i].sueldo;
//     }
//     prom = sum / c;
//     return prom;
// }

// int hallarSueldoMenorProm(Empleados datos[], int c, float promE) {
//     int cant = 0;
//     for (int i = 0; i < c; i++) {
//         if (datos[i].sueldo < promE) 
//             cant++; 
//     }
//     return cant;
// }

// void eliminarEmpleado(Empleados datos[], int &c) {
//     int p;
//     cin >> p; //eliminas la posicion (p), en version "humana" es p=3, pero el indice en 2, o sea uno menos
//     for (int i = p-1; i < c - 1; i++) {
//         datos[i] = datos[i + 1];
//     }
//     c = c - 1;
// }
