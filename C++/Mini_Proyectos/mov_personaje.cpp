#include <iostream> 
//PRIMERO DE 1 DIMENSION

void mostrarMapa(int posX, int posY, char gameMap[5][5]);
void llenarMapa(char gameMap[5][5]);
void posicionJugador(int &posX, int &posY, char posicionActual);
int main() {

    std::cout<<"Presiona d(derecha), a(izquierda), w(arriba), s(abajo) para que el personaje se mueva: \n";
    char gameMap[5][5];
    int posX = 0;
    int posY = 0;
    char posicionActual = ' ';

    llenarMapa(gameMap); //llena el mapa
    mostrarMapa(posX, posY, gameMap); //listo el mapa con las posiciones en el arreg
    std::cin>>posicionActual;
    

    while (posicionActual != 'p') {

        posicionJugador(posX, posY, posicionActual);
        mostrarMapa(posX, posY, gameMap); //MAPA ACTUALIZADO POR CADA MOVIMIENTO
        std::cin>>posicionActual; //para presionar denuevo despues de cada tecla que presiono
    } 

    std::cout<<"PERDISTE!\n";

    return 0;
}

//LLENAR EL ARREGLO
void llenarMapa(char gameMap[5][5]) {

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++) {
            gameMap[i][j] = '1';
        }
        }

}

//MOSTRAR MAPA
void mostrarMapa(int posX, int posY, char gameMap[5][5]) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if (posX == i && posY == j) {
                std::cout<<'H'<< ' ';
            } else {    
                std::cout<<'1'<< ' ';
            }
        }
        std::cout<<std::endl;
    }
}

void posicionJugador(int &posX, int &posY, char posicionActual) {

    switch (posicionActual) {
            case 'd':
                posY +=1;
                break; //sale y se va directo a mostrar al mapa actualizado, luego me pide que presione otra vez, pero recuerda, todo esta dentro del while
            case 'a':
                posY -=1;
                break;
            case 'w':
                posX -=1;
                break;
            case 's':
                posX +=1;
                break;
            default:
                std::cout<<"Presione una opcion valida! \n";
                break; 
            }
}