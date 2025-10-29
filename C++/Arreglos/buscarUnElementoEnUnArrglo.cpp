#include <iostream>
/*
EL EJERCICIO ES BUSCAR UN ELEMENTO DEL SIGUIENTE ARREGLO. YO SE CUANTOS Y QUE ELEMENTOS HAY EN EL ARREGLO, PERO QUIEN PONE LOS NUMEROS
NO LO SABE, POR ENDE, EN CONSOLA, VOY A PONER NUMEROS QUE YO CREA QUE ESTEN EN ARREGLO, SI LO ESTAN, PUES EN CONSOLA ME DA COMO 
RESULTADO EL NUMERO Y LA UBICACION DEL INDICE EN EL CUAL SE ENCUENTRA ESE NUMERO.

EL OBJETIVO ES CREAR UNA FUNCION QUE ENCUENTRE ESE NUMERO EN EL ARREGLO Y QUE RETORNE EL INDICE (POSICION), PARA ESO NECESITO SABER EL TAMAÑO DEL ARREGLO, CON ESO SE LA
CANTIDAD DE ELEMENTOS DEL ARREGLO PARA LUEGO PODER ENCONTRAR EL NUMERO.

*/

int encontrarArreglo(int arreglo[], int tam, int numeroConsola);

int main() {

    int numeros[] = {1,2,3,4,5,6,7,8,9,10}; //MI ARREGLO
    int tamano = sizeof(numeros) / sizeof(int); //TAMANO DEL ARREGLO
    int indice; //LA POSICION DEL ELEMENTO EN EL ARREGLO
    int num; //EL NUMERO QUE INGRESE EN CONSOLA, SI SE ENCUENTRA EN EL ARREGLO O NO

    std::cout<<"Ingrese el numero: ";
    std::cin>>num;
    
    indice = encontrarArreglo(numeros, tamano, num); //ME VA A PASAR COMO PARAMETROS EL ARREGLO, TAMAÑO Y EL NUMERO QUE YO INGRESE EN CONSOLA

    if(indice != -1) { //en caso ese numero se haya encontrado
        std::cout<<"El numero "<<num<<" se encuentra en el indice "<<indice;
    } else { 
        std::cout<<"El numero "<<num<<" no se encuentra en el arreglo";
    }

    return 0;
}

int encontrarArreglo(int arreglo[], int tam, int numeroConsola) {
    
    for(int i = 0; i < tam; i++) {
        if(numeroConsola == arreglo[i]) {
            return i; //que me retorne el indice
        }
    }

    return -1; //EN CASO DE QUE NO SALGA PONGO -1, ESO QUIERE DECIR QUE NO SE ENCONTRÓ

}
