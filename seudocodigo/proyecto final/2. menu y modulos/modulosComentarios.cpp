#include <iostream>
using namespace std;


//Estructuras

// struct Vehiculo {

//     int codigoVehiculo;

//     string numChasis;
//     string numMotor;
//     string marca;
//     string modelo;
//     int anioFabricacion;
//     string color;
//     string tipoCombustible;
//     string tipoTransmision;
//     string tipoCarroceria;
//     string proveedor;

//     float precioVenta;

// };


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

//P2.MODULOS
//2.1 VEHICULO
// void crearArchivoVehiculo(FILE*V);


//Main

int main() {

    // FILE*V;
    // struct Vehiculo;

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
            case '1': cout<<"1"; //!crearArchivoVehiculo(V)
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
        cout<<"5. Retornar menu principal"<<endl;
        cout<<"************************************"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opc_Ven;
    
        switch (opc_Ven) {
            case '1': cout<<"1";
                break;
            case '2': cout<<"2";
                break;
            // case '3': cout<<"3";
                // break;
            // case '4': cout<<"4";
                // break;
            case '5': break;
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

//----------------ARCHIVO VEHICULO-------------------------------
// void crearArchivoVehiculo(FILE*V) {

//     V = fopen("c:Autos.txt", "w");
//     if(V == NULL) 
//         cout<<"NO se pudo crear el archivo Autos.txt"<<endl;
//     else { 
//         cout<<"Creación del archivo Autos.txt exitosa"<<endl;
//         fclose(V);
//     }
// }

//---------EXPLICACION------------//

/*
    1. Paso por valor (FILE*V): La función recibe una COPIA del argumento. Si el argumento es un 
    puntero (FILE*), la función recibe una copia del puntero; CAMBIAR ESA COPIA NO AFECTA
    AL PUNTERO ORIGINAL DEL LLAMADOR (!crearArchivoVehiculo(V)) y la función que fue 
    llamada (ccrearArchivoVehiculo(FILE*V)). 
    Si el argumento se pasa por valor, la función llamada recibe una COPIA(FILE*V -> puntero), 
    entonces, lo que hagas adentro no afecta al llamador. 


    *void crearArchivoVehiculo(FILE* V) {
    *    V = fopen(...);
    
    ? El problema es que V es local a la función. Cuando abres V = fopen(...), sólo la COPIA
    ? local apunta al ARCHIVO; el FILE del llamador ( menu(), menuVehiculo() ) sigue siendo el
    ? mismo.

    Analogía: Es como darle a alguien una fotocopia de un mapa: pueden rayarlo, marcarlos, lo
    que sea, pero el mapa original sigue igual.


    2. Paso por referencia (FILE*&V): La función recibe una referencia del argumentos original
    Cualquier asignación a V dentro de la función modifica el puntero del llamador. 

    *Cuando escribes la función:
    * V = fopen("Autos.txt", "w") 

    ? El ARCHIVO que nos referimos (explicando el paso por valor) es a "Autos.txt", el archivo
    ? físico que se creará en tu carpeta del proyecto. 
    ? Cuando decimos "se copia a V" (explicando el paso por valor), no se copia el archivo,
    ? se copia el puntero. 
    ? FILE*V es solo un puntero (explicando el paso por valor), no el archivo. 
    ? El puntero guarda una dirección de memoria que C usa para menejar el archivo. 
        ? El archivo real = "Autos.txt"
        ? El puntero V = un "identificador" que apunta a una estructura interna (FILE) creada
        ? por fopen()
    
    ? ¿Qué hace realmente fopen()?
    ? 1. Le dice al SO que abra un archivo "Autos.txt" en este modo "w"
    ? 2. El SO crea el archivo
    ? 3. El SO devuelve un puntero a una estructura interna FILE (que contiene toda la info
    ? necesaria para trabajar con el archivo)
    ? 4. Ese puntero es lo que recibe V

        ? fopen("Autos.txt", "w") --->   [FILE estructura interna] ---> puntero 0x7AF3F0
        ? Tu variable V almacena: (V = 0x7AF3F0)
    
    ? Entonces, ¿por qué necesitas pasar FILE*&V?
    ? Porque el puntero que devuelve fopen() -> 0x7AF3F0 debe almacenarse en la variable real,
    ? es decir, a la variable que existe fuera de la función, el lugar donde tu quieres que 
    ? guarde el resultado de fopen.
        ? FILE*V
        ? menuVehiculo(V)
        ? Aquí, esta V es la variable real. Es la que vive en el llamador (main, menu, etc.)
        ? Es la quieres que termine apuntando al archivo.
    ? V NO ES UNA COPIA QUE DEBE DESAPARECER CUANDO LA FUNCIÓN TERMINA

    ?RESUMEN:
    ? fopen(...) Crea un archivo físico y te devuelve un puntero que te permite operar en él 
    ? Y pasar FILE*&V permite que ese puntero quede guardado en la varible original, no es 
    ? una copia. 




*/