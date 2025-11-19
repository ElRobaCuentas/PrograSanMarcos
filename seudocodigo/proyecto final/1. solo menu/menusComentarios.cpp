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
        cout<<"*********************************"<<endl;
        cout<<"GESTION DE VENTAS DE AUTOMOVILES"<<endl; //nombre genérico
        cout<<"1. VEHICULO"<<endl;
        cout<<"2. CLIENTE"<<endl;
        cout<<"3. VENTA"<<endl;
        cout<<"4. CONSULTAS"<<endl;
        cout<<"5. SALIR"<<endl;
        cout<<"*********************************"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion; //1

        validarOpcion(opcion); 
        //TODO:vuelve a donde fue llamado, osea aca, y despues de validar
        //TODO: pues vuelve a mostrar este menú principal
    } while (opcion != '5');
}


void validarOpcion(char opcion) {

    switch (opcion) {
    case '1':  menuVehiculo();
        break; //TODO:y termina despues de regresar aca con un break
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
    } //TODO: sale del swiitch al terminar el break de case '1'
} 
//TODO: termina validarOpcion y regresamos automaticamente al menu(), donde fue llamado validarOpcion()


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
            case '5': //!¿Por qué aquí no puse defrente menu()?
        /*
        ! menu()                 <-- frame A (original)
            ! validarOpcion()
                ! menuVehiculo()     <-- frame B (submenú)
                    ! user elige '5'
                        ! menu()         <-- frame C (¡nueva llamada al menú!)
                            ! validarOpcion()
                                ! menuVehiculo() <-- frame D
                                    ! user elige '5'
                                        ! menu()   <-- frame E
                                        ! ...
            !Cada vez que llamas a una función se crea un frame en la pila (stack)
            !con sus variables locales y la dirección de retorno. Si desde el 
            !submenú (menuVehiculo) llamas a menu(), no estas "volviendo", estás 
            !Zabriendo una nueva instancia de menu() encima de la anterior

            !Consecuencias: pila llega al límite (stack overflow) -> programa crashee
        */



            break; //TODO: solo sale del switch (en caso presione la opcion '5')
        } 
        //TODO: inmediatamente llega al final del bucle
    } while (opc_Veh != '5'); 
    //TODO: como opc_Veh == 5 (F) entonces sale del bucle
    //TODO: al salir del do...while termina la función menuVehiculo() y regresa al punto donde
    //TODO: fue llamada, que es validarOpcion();
}

void menuCliente() {

    char opc_Cli;

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
        case '5': menu();
            break;
    }
}

void menuVenta() {
    char opc_Ven;

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
}



void menuConsulta() {
    
    cout<<"*********************************************"<<endl;
    cout<<"Menu Consultas"<<endl;
    cout<<"1. Reporte de marca de auto mas vendida"<<endl;
    cout<<"2. Reporte de cliente con multiples compras"<<endl;
    cout<<"**********************************************"<<endl;

}