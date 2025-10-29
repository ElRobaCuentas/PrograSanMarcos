#include <iostream>

//TODO: DEFINICION DE UNA FUNCION Y FORMAS VALIDAS DE USAR UNA FUNCION

// //!DECLARO A MI FUNCION 
// void felizCumpleanos(std::string name, int edad);

// int main() {

//     std::string nombre = "Juan";
//     int edad = 19;

// //?LLAMO A MI FUNCION
//     felizCumpleanos(nombre, edad);

//     /* SI TU CODIGO FUERA ESTE:
//     void felizCumpleanos();
//     int main() {
//         std::string nombre = "Juan";
//         felizCumpleanos(nombre);
//     } //* la variable nombre solo vive dentro de main(), fuera de este nombre no existe. El amabito (escope, error que sale en consola) es el
//       //* lugar del programa donde existe una variable y es valida. Las variables de C++ solo existen dentro del bloque {...} donde fueron declaradas.
//     ...
//     void felizCumpleanos();
//     */

//     return 0;
// }

// //!DEFINO A MI FUNCION
// void felizCumpleanos(std::string name, int edad) {
//     std::cout<<"Feliz cumpleanos\n";
//     std::cout<<"Feliz cumpleanos\n";
//     std::cout<<"Feliz cumpleanos "<<name<<'\n';

//     std::cout<<"Tu edad es: "<<edad;

// }

// //!CUANDO DECLARO Y DEFINO MI FUNCION, NECESITO INDICAR EL (TIPO DE PARAMETRO Y EL NOMBRE). Al tipo de parametro me refiero al tipo de dato, el cual puede ser: int, float, double, char, bool...
// //!DE ESTA MANERA felizCumpleanos recibe un (std::string) que se va a llamar (nombre) dentro del cuerpo de la funcion

// //? SIMPLEMENTE LLAMO A LA FUNCION Y LE PASO UN VALOR COMO ARGUMENTO, NO NECESITO RECIBIR EL TIPO DE DATO [STRING], SOLO PASO EL VALOR QUE CORRESPONDE AL TIPO ESPERADO


//TODO: TODO SOBRE RETURN

//! CON FUNCIONES void NO HACE FALTA USAR RETURN

    //*AREA DE UN CUADRADO
// void areaCuadrado(double longitud);
// int main() {
    
//     double longitud = 5.0;
//     areaCuadrado(longitud);

//     return 0;
// }
// void areaCuadrado(double longitud) {
//     double area = longitud * longitud;
//     std::cout<<"El area es: "<<area<<"cm2";
// }

//! CON FUNCION CON tipo_de_retorno

// double areaCuadrado(double longitud);
// int main() {
    
//     double longitud = 5.0;
//     double area = areaCuadrado(longitud);
//     std::cout<<"El area del cuadrado es: "<<area<<"cm2";

//     return 0;
// }
// double areaCuadrado(double longitud) {
//     double area = longitud * longitud;
//     return area; //* NO HACE FALTA ALMACENARLO ACA EN area, YA QUE ARRIBA HACES LO MISMO
// }

//! CON FUNCION CON tipo_de_retorno, pero de otra forma

// double areaCuadrado(double longitud);
// int main() {
    
//     double longitud = 5.0;
//     // std::cout<<areaCuadrado(longitud)<<"cm2";

//     double area = areaCuadrado(longitud);
//     std::cout<<"El area del cuadrado es: "<<area<<"cm2";

//     return 0;
// }
// double areaCuadrado(double longitud) {
//     return longitud * longitud;
// }


    //* CONCATENAR STRING

// std::string concatenarString(std::string str1, std::string str2);

// int main() {

//     std::string nombre = "Juan";
//     std::string apellido = "Matias";

//     std::cout<<"Hola "<< concatenarString(nombre, apellido);

//     return 0;
// }

// std::string concatenarString(std::string str1, std::string str2) {
//     return str1 + " " + str2;
// }


//TODO: ENCAPSULAMIENTO DE UNA FUNCION
void prepararPizza();
void prepararPizza(std::string ingrediente1);
void prepararPizza(std::string ingrediente1, std::string ingrediente2);

int main() {
    prepararPizza("Muzarella", "Pepperoni");
    return 0;
}

void prepararPizza() { // CERO PARAMETROS
    std::cout<<"Aqui esta tu pizza!\n";
}

void prepararPizza(std::string ingrediente1) { //UN PARAMETRO
    std::cout<<"Aqui esta tu pizza de "<<ingrediente1;
}

void prepararPizza(std::string ingrediente1, std::string ingrediente2) { //DOS PARAMETRO
    std::cout<<"Aqui esta tu pizza de "<<ingrediente1 << " y "<<ingrediente2;
}