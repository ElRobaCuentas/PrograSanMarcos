#include <iostream> 

void estructuraBanco();
void mostrarSaldo(double saldo);
double depositar(); //solo voy a depositar, no necesito enviarle como parametro nada
double retirar(double saldo);


int main() {

    double saldo = 0;
    char opcion;
    
    do {

    estructuraBanco();
    
    std::cin>>opcion;

    switch (opcion) { //SOLO LLAMO
        case '1':
            mostrarSaldo(saldo);
            break;
        case '2':     
            saldo += depositar();
            // mostrarSaldo(saldo); // ACA GUARDA EL VALOR QUE LO RETORNA, TONCES ESTO VA ARRIBA, OSEA EN saldo += depositar();
            break;
        case '3':
            saldo -= retirar(saldo);
            break;
        case '4':
            std::cout<<"Gracias por su visita! :D";
            break;
        default:
            std::cout<<"Porfavor elija una opcion valida\n";
            break;
    }
} while (opcion != '4');


    return 0;

}

// QUE VA A HACER CADA FUNCION

void mostrarSaldo(double saldo) {
    std::cout<<"Tu saldo es:"<<"S/"<<saldo<<"\n";
}

double depositar() {
    double deposito = 0;

    std::cout<<"Cuanto quiere depositar?: ";
    std::cin>>deposito;

    if(deposito > 0) {
        return deposito;
    } else {
        return 0;
    }

    return deposito; //voy a retornar esto en la funcion principal
}

double retirar(double saldo) {
    
    double retiro = 0;
    std::cout<<"Cuanto quieres retirar?: ";
    std::cin>>retiro;

    if( retiro < saldo ) {
        return retiro;
    } else {
        std::cout<<"Saldo insuficiente!\n";    
        return 0;
    }
}

void estructuraBanco() {
    std::cout<<"*******************\n";
    std::cout<<"SISTEMA BANCARIO\n";
    std::cout<<"*******************\n";

    std::cout<<"ELIJA ALGUNA DE ESTAS OPCIONES \n";

    std::cout<<"1. VER MI SALDO \n";
    std::cout<<"2. DEPOSITAR DINERO \n";
    std::cout<<"3. RETIRAR DINERO \n";
    std::cout<<"4. SALIR DEL SISTEMA \n";
}