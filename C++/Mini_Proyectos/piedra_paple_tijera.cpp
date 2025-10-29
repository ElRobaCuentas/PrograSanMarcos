#include <iostream>
#include <cstdlib>
#include <ctime>

char eleccionUsuario();
char eleccionComputadora();
void mostrarEleccion(char eleccion);
void elejirGanador(char jugador, char computadora);

int main() {

    srand(time(0));

    char jugador; // opciones como 'r', 'p', 't'
    char computadora; //opciones 

    jugador = eleccionUsuario();
    std::cout<<"Jugador: ";
    mostrarEleccion(jugador);

    computadora = eleccionComputadora();
    std::cout<<"Computadora: ";
    mostrarEleccion(computadora);


    elejirGanador(jugador, computadora);
    
    return 0;
}

char eleccionUsuario(char jugador) {
    
    do { 
    std::cout<<"**************************\n";
    std::cout<<"Roca, Papel o Tijera\n";
    std::cout<<"**************************\n";

    std::cout<<"Elija cualquiera de las tres opciones\n";
    std::cout<<"'r' para Roca\n";
    std::cout<<"'p' para Papel\n";
    std::cout<<"'t' para Tijera\n";

    std::cin>>jugador; //Lo que elijo se almacena en la variable jugador.


    } while (jugador != 'r' && jugador != 'p' && jugador != 't');
    
    return jugador;

}
char eleccionComputadora(int num) {
    //no existe char computadora, por eso no retorno computadora

    /*
        ACA ES DEFRENTE, EN  LA FUNCION MAIN() LLAMO A LA FUNCION eleccionComputadora() y el valor que me devuleve lo almaceno en computadora.
        segun num, puede elejir entre 1, 2 o 3 y depende a eso retorna 'r', 'p' o 't'.
        Lo que retorna computadora lo almaceno en la variable computadora -> computadora = eleccionComputadora();
        luego al llamar a la funcion mostrarEleccion() le envio como parametro el valor de computadora, en este caso puede ser 'r', 't', o 'p' y eso muestra.
    */
    
    num = (rand() % 3) + 1;

    switch (num) { 
        case 1: return 'r'; //como defrente me va a retornar, no es necesario usar break
        case 2: return 'p';
        case 3: return 't';             
        //tampoco es necesario usar default porque solo elijira opciones como 1, 2 o 3; solo eso.
    }

    return 0; //no hace falta este return, ya que arriba ya estoy retornando.
}
void mostrarEleccion(char eleccion) { //sea del jugador o de la computadora
    /* 
    TODO: mostrarEleccion(jugador) en el main, llama a la funcion mostrarEleccion()  y le pasa el valor que tiene jugador como argumento, entonces, dentro de mostrarEleccion();
    TODO: 1. el parametro eleccion mostrarEleccion(char eleccion) recibe el valor de jugador, osea, si jugador es igual a 'p', entonces eleccion es igual a 'p'
    TODO: 2. El switch revisa:
        Si es 'r' → imprime "Roca".
        Si es 'p' → imprime "Papel".
        Si es 't' → imprime "Tijera".
    */
        switch (eleccion){
        case 'r':
            std::cout<<"Roca\n";
            break;
        case 'p':
            std::cout<<"Papel\n";
            break;
        case 't':
            std::cout<<"Tijera\n";
            break;
        }
}
void elejirGanador(char jugador, char computadora) {

    switch (jugador) { //el papel le gana a la roca :0
        case 'r':
            if( computadora == 'r') {
                std::cout<<"Empate!\n";
            } else if ( computadora == 'p') {
                std::cout<<"Perdiste!\n";
            } else {
                std::cout<<"Ganaste!\n";
            }
            break;
        case 'p':
            if( computadora == 'p') {
                std::cout<<"Empate!\n";
            } else if ( computadora == 'r') {
                std::cout<<"Ganaste!\n";
            } else {
                std::cout<<"Perdiste!\n";
            }
            break;
        case 't':
            if( computadora == 't') {
                std::cout<<"Empate!\n";
            } else if ( computadora == 'r') {
                std::cout<<"Perdiste!\n";
            } else {
                std::cout<<"Ganaste!\n";
            }
            break;    
    }
}




//---------------------------------------------------------------------------------//

//CON UNA FUNCION MAS AGREGADA

// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// void menuJuego(); //quiero una funcion que me muestre el panel del juego
// char elccionUsuario();//quiero una funcion que me muestre lo que elija el usuario
// char eleccionComputadora();//quiero una funcion que me muestre lo que elija la computadora

// void mostrarEleccion(char eleccion);//quiero una funcion que muestre la eleccion de ambos
// void elejirGanador(char jugador, char computadora);//quiero una funcion que elija al ganador


// int main() {    
    
//     srand(time(0));
//     char jugador;
//     char computadora;

//     do {
//         menuJuego();
//         jugador = elccionUsuario();
//         //TODO:elccionUsuario(); //lo llamo, pero no guardo el valor que retorna, por ende, la varible jugador dentro del main nunca cambia de valor, por eso el while no funciona
//     } while (jugador != 'r' && jugador != 'p' && jugador != 't');
    
//     std::cout<<"Jugador: ";
//     mostrarEleccion(jugador);
    
//     computadora = eleccionComputadora();
//     std::cout<<"Computadora: ";
//     mostrarEleccion(computadora);

//     std::cout<<"Ganador: ";
//     elejirGanador(jugador, computadora);
//     return 0;
// }

// void menuJuego() {

//     std::cout<<"\n**************************\n";
//     std::cout<<"Roca, Papel o Tijera\n";
//     std::cout<<"**************************\n";

//     std::cout<<"'r' para Roca\n";
//     std::cout<<"'p' para Papel\n";
//     std::cout<<"'t' para Tijera\n";
//     std::cout<<"Elija cualquiera de las tres opciones: ";

// }

// char elccionUsuario() {
//     char jugador;
//     std::cin>>jugador;

//     return jugador;
// }

// char eleccionComputadora() {
//     int num;
//     num = rand() % 3 + 1;

//     switch (num) {
//     case 1: return 'r';
//     case 2: return 'p';
//     case 3: return 't';
//     }

//     return 0;
// }

// void mostrarEleccion( char eleccion) {


//     switch (eleccion)
//     {
//     case 'r': 
//         std::cout<<"Roca\n";
//         break;

//     case 'p': 
//         std::cout<<"Papel\n";
//         break;

//     case 't': 
//         std::cout<<"Tijera\n";
//         break;
//     }

// }

// void elejirGanador(char jugador, char computadora) {