#include <iostream>
#include <cstdlib>
#include <ctime>


int main() {

    //ALEATORIEDAD
    /* 
    !<cstdlib>
    !<ctime>
    */
    
    //?NUMEROS ALEATORIOS
    // srand(time(0));
    // int num; 
    // num = rand() % 6 + 1;   

    //std::cout<<"El numero es: "<<num;

    //?EVENTOS ALEATORIOS

    // switch (num)
    // {
    //     case 1:
    //     case 3:
    //     case 5:

    //     std::cout<<"El numero es impar";
    //     break;

    //     case 2:
    //     case 4:
    //     case 6:

    //     std::cout<<"El numero es par";
    //     break;
    // }

    //?ADIVINA EL NUMERO

    srand(time(0));
    int num;
    int adiv;
    char option;
    
    do {
        num = rand() % 2 + 1;
        std::cout<<"Adivina el numero:";
        std::cin>>adiv;

        if(adiv == num) {
            std::cout<<"GANASTE!";
            break;
        } else {
            std::cout<<"PERDSITE!";
        }

        std::cout<<std::endl;
        std::cout<<"Quieres intentarlo otra vez? (y/Y para si):";
        std::cin>>option;

    } while( option == 'y' || option == 'Y');

    //HOLAAAAAAAA

    return 0;
}