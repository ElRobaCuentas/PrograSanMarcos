#include <iostream>
using namespace std;


//Prototipos

//P1.MENUS
void menu();
void validarOpcion(char opcion);
void menuVehiculo();
void menuCliente();
void menuVenta();
void menuConsulta();
    //reporte 1
    //reporte 2
void salir();


//Main

int main() {

    menu();
    
}

void salir() {
    cout<<"GRACIAS POR SU VISITA"<<endl;
}

void menu() {
    char opcion;
    do {
        cout<<"***********************************"<<endl;
        cout<<"GESTION DE VENTAS DE AUTOMOVILES"<<endl; //nombre genérico
        cout<<"1. VEHICULO"<<endl;
        cout<<"2. CLIENTE"<<endl;
        cout<<"3. VENTA"<<endl;
        cout<<"4. CONSULTAS"<<endl;
        cout<<"5. SALIR"<<endl;
        cout<<"***********************************"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion; 

        validarOpcion(opcion); 
    } while (opcion != '5');
}


void validarOpcion(char opcion) {

    switch (opcion) {
    case '1':  menuVehiculo();
        break; 
    case '2': menuCliente();
        break;
    case '3': menuVenta();
        break;
    case '4': menuConsulta();
        break;
    case '5':  salir(); 
        break;
    default:
        cout<<"Presione una opcion valida!"<<endl;
        break;
    } 
} 

void menuVehiculo() {
    char opc_Veh;
    do {
        cout<<"******************************************"<<endl;
        cout<<"Menu Vehiculo"<<endl;
        cout<<"1. Crear archivo vehiculo"<<endl;
        cout<<"2. Registrar Vehiculo"<<endl;
        cout<<"3. Mostrar vehiculos registrados (todos)"<<endl;
        cout<<"4. Mostrar un vehiculo registrado"<<endl;
        cout<<"5. Retornar menu principal"<<endl;
        cout<<"*******************************************"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opc_Veh;

        switch (opc_Veh) {
            case '1': cout<<"1";
                break;
            case '2': cout<<"2";
                break;
            case '3': cout<<"3";
                break;
            case '4': cout<<"4";
                break;
            case '5': break; 
        } 
    } while (opc_Veh != '5'); 
}

void menuCliente() {
    char opc_Cli;
    do {
        cout<<"*********************************************"<<endl;
        cout<<"Menu Cliente"<<endl;
        cout<<"1. Crear archivo cliente"<<endl;
        cout<<"2. Registrar cliente"<<endl;
        cout<<"3. Mostrar clientes registrados (todos)"<<endl;
        cout<<"4. Mostrar un cliente registrado"<<endl;
        cout<<"5. Retornar menu principal"<<endl;
        cout<<"**********************************************"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opc_Cli;
    
        switch (opc_Cli) {
            case '1': cout<<"1";
                break;
            case '2': cout<<"2";
                break;
            case '3': cout<<"3";
                break;
            case '4': cout<<"4";
                break;
            case '5': break;
        }
    } while (opc_Cli != '5');
        
}

void menuVenta() {
    char opc_Ven;
    do {

        cout<<"************************************"<<endl;
        cout<<"Menu Venta"<<endl;
        cout<<"1. Crear archivo venta"<<endl;
        cout<<"2. Registrar venta"<<endl;
        // cout<<"3. Mostrar ventas registradas (todos)"<<endl;
        // cout<<"4. Mostrar una venta registrada"<<endl;
        cout<<"3. Retornar menu principal"<<endl;
        cout<<"************************************"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opc_Ven;
    
        switch (opc_Ven) {
            case '1': cout<<"1";
                break;
            case '2': cout<<"2";
                break;
            case '3': cout<<"3";
                break;
            case '4': cout<<"4";
                break;
            case '5': menu();
                break;
        }
    } while (opc_Ven != '5');
}

void menuConsulta() {
    char opc_Con;
    do {
        cout<<"*********************************************"<<endl;
        cout<<"Menu Consultas"<<endl;
        cout<<"1. Reporte de marca de auto mas vendida"<<endl;
        cout<<"2. Reporte de cliente con multiples compras"<<endl;
        cout<<"3. Retonar al menu principal"<<endl;
        cout<<"**********************************************"<<endl;

        cout<<"Seleccione una opcion: ";
        cin>>opc_Con;

        switch (opc_Con) {

            case '1': cout<<"REPORTE 1";
                break;
            case '2': cout<<"REPORTE 2";
                break;
            case '3': break;
        }
    } while (opc_Con != '3');
}