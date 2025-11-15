#include <iostream>
using namespace std;

//Prototipos
void mostrarMenu(float &saldo);
void procesarOpcion(char opcion, float &saldo);
void mostrarSaldo(float saldo);
float depositarSaldo();
float retirarSaldo(float saldo);

int main() {

    float saldo = 0;  

    mostrarMenu(saldo);
    mostrarSaldo(saldo);

    return 0;
}


void mostrarMenu(float &saldo) {

    char opcion = ' ';

    do{
    cout<<"************************"<<endl;
    cout<<"SISTEMA BANCARIO"<<endl;
    cout<<"************************"<<endl;
    cout<<"'1': Mostrar mi saldo"<<endl;
    cout<<"'2': Desositar dinero"<<endl;
    cout<<"'3': Retirar dinero"<<endl;
    cout<<"'4': Salir"<<endl;
    cout<<"Elija cualquiera de las siguientes opciones: ";
    cin>>opcion;

    procesarOpcion(opcion, saldo);
    
} while(opcion != '4');
    
}

void procesarOpcion(char opcion, float &saldo) {

    float saldoActualizado;

    switch (opcion){
        case '1': 
            mostrarSaldo(saldo);
            break;
        case '2':
            // saldoActualizado = depositarSaldo();
            // saldoActualizado = saldoActualizado + saldo;
            // cout<<"Tu nuevo saldo es: "<<saldoActualizado<<endl;

            saldo = saldo + depositarSaldo();
            cout<<"Tu nuevo saldo es: "<<saldo<<endl;
            break;
        case '3':
            saldo = retirarSaldo(saldo);
            cout<<"Tu nuevo saldo es: "<<saldo<<endl;

    }
}

void mostrarSaldo(float saldo) {
    cout<<"Tu saldo es: "<< saldo <<endl;
}


float depositarSaldo() {

    float depositar;

    cout<<"Deposite su dinero: ";
    cin>>depositar;

    return depositar;
}


float retirarSaldo(float saldo) {

    float retirar; 

    cout<<"Retire su dinero: ";
    cin>>retirar;

    if(retirar > saldo) {
        cout<<"No es posible retirar esta cantidad porque es mayor a su saldo actual";
    } else {
        retirar = saldo - retirar;
    }

    return retirar;

}

