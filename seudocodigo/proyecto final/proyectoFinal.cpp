#include <iostream>
#include <cstdio>   // Para FILE, fopen, fclose
using namespace std;

//Estructuras

struct Vehiculo {
    int codigoVehiculo;

    char numChasis[20];
    char numMotor[20];
    char marca[20];
    char modelo[20];
    int anioFabricacion;
    char color[20];
    char tipoCombustible[20];
    char tipoTransmision[20];
    char tipoCarroceria[20];
    char proveedor[20];

    float precioVenta;
};


//PROTOTIPOS

// Menús
void menu();
void validarOpcion(char opcion);
void menuVehiculo();
void menuCliente();
void menuVenta();
void menuConsulta();
void salir();

// Módulos Vehículo
void crearArchivoVehiculo(FILE* V);
void registrarVehiculo(FILE* V, Vehiculo veh);
void mostrarUnVeh(FILE *V, Vehiculo veh);


//Principal

int main() {

    menu();

}

void salir() {
    cout << "GRACIAS POR SU VISITA" << endl;
}


void menu() {

    char opcion;

    do {
        cout<<"******************************************"<<endl;
        cout<<"GESTION DE VENTAS DE AUTOMOVILES"<<endl;
        cout<<"1. VEHICULO"<<endl;
        cout<<"2. CLIENTE"<<endl;
        cout<<"3. VENTA"<<endl;
        cout<<"4. CONSULTAS"<<endl;
        cout<<"5. SALIR"<<endl;
        cout<<"******************************************"<<endl;
        cout<<"Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        validarOpcion(opcion);

    } while (opcion != '5');
}


void validarOpcion(char opcion) {

    switch (opcion) {

    case '1':  
        menuVehiculo();
        break;

    case '2': 
        menuCliente();
        break;

    case '3': 
        menuVenta();
        break;

    case '4': 
        menuConsulta();
        break;

    case '5':  
        salir(); 
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
        cin >> opc_Veh;
        // cin.ignore();
        system("cls");

        switch (opc_Veh) {

            case '1':
                crearArchivoVehiculo(NULL); 
                /*
                    crearArchivoVehiculo(FILE*V), al pasar FILE*V como valor, no necesito al
                    parametro para nada fuera de la funcion donde se está usando.
                        - Toda la lógica está dentro del módulo
                        - No me interesa el valor original
                    Entonces, ¿por qué NULL específicamente? Porque es la forma que deja más
                    explícito que "No necesito este parámetro para nada fuera de la función 
                    en donde se está usando". 
                */
                break;

            case '2': 
                Vehiculo V;
                registrarVehiculo(NULL, V);
                break;
            case '3':
                cout<<"MOSTRAR TODOS"<<endl;
                break;

            case '4':
                mostrarUnVeh(NULL, V);
                break;
            case '5':
                break;
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
        cin >> opc_Cli;

        switch (opc_Cli) {
            case '1': cout<<"1"<<endl; break;
            case '2': cout<<"2"<<endl; break;
            case '3': cout<<"3"<<endl; break;
            case '4': cout<<"4"<<endl; break;
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
        cout<<"3. Retornar menu principal"<<endl;
        cout<<"************************************"<<endl;
        cout<<"Seleccione una opcion: ";
        cin >> opc_Ven;

        switch (opc_Ven) {
            case '1': cout<<"1"<<endl; break;
            case '2': cout<<"2"<<endl; break;
            case '3': break;
        }

    } while (opc_Ven != '3');
}


void menuConsulta() {

    char opc_Con;

    do {
        cout<<"*********************************************"<<endl;
        cout<<"Menu Consultas"<<endl;
        cout<<"1. Reporte de marca de auto mas vendida"<<endl;
        cout<<"2. Reporte de cliente con multiples compras"<<endl;
        cout<<"3. Retornar al menu principal"<<endl;
        cout<<"**********************************************"<<endl;
        cout<<"Seleccione una opcion: ";
        cin >> opc_Con;

        switch (opc_Con) {
            case '1': cout<<"REPORTE 1"<<endl; break;
            case '2': cout<<"REPORTE 2"<<endl; break;
            case '3': break;
        }

    } while (opc_Con != '3');
}




//MODULOS VEHICULO
void crearArchivoVehiculo(FILE* V) {

    //Al salir de la funcion, ese V interno desaparece. Por lo tanto, lo que envies como
    //parámetro NO importa, porque NO se usará afuera. 

    V = fopen("Autos.txt", "w");

    if (V == NULL) 
        cout<<"NO se pudo crear el archivo Autos.txt"<<endl;
    else { 
        cout<<"Creacion del archivo Autos.txt exitosa"<<endl;
        fclose(V);
    }
}


void registrarVehiculo(FILE* V, Vehiculo veh) {

    char temp[2];

    cout<<"Codigo del vehiculo: "; cin>>veh.codigoVehiculo;
    gets(temp);
    cout<<"Numero de chasis: "; gets(veh.numChasis);
    cout<<"Numero de motor: "; gets(veh.numMotor);
    cout<<"Marca: "; gets(veh.marca);
    cout<<"Modelo: "; gets(veh.modelo);
    cout<<"Anio de fabricacion: "; cin>>veh.anioFabricacion;
    gets(temp);
    cout<<"Color: "; gets(veh.color);
    cout<<"Tipo de combustible: "; gets(veh.tipoCombustible);
    cout<<"Tipo de transmision: "; gets(veh.tipoTransmision);
    cout<<"Tipo de carroceria: "; gets(veh.tipoCarroceria);
    cout<<"Proveedor: "; gets(veh.proveedor);
    cout<<"Precio de venta: "; cin>>veh.precioVenta;



    //Abrir el archivo
    V = fopen("Autos.txt", "a");

    if(V != NULL) {
        fwrite(&veh, sizeof(veh), 1, V);
        if(!ferror(V)) {
            cout<<"Vehiculo registrado con exito \n";
            fclose(V);
        }
        else
            cout << "Error al escribir en Autos.txt\n";
    }
    else {
        cout << "No se pudo abrir Autos.txt\n";
    }
}

//opcion4

void mostrarUnVeh(FILE *V, Vehiculo veh) {

    int codigo;

    cout<<"Ingrese el codigo del vehiculo a buscar: ";
    cin>>codigo;

    V = fopen("Autos.txt", "r");    
    if(V == NULL) {
        cout<<"No se puede abrir el archivo Autos \n";
        system("cls");
    }
    while (!feof(V)) {
        fread(&veh, sizeof(veh), 1, V);
        if(veh.codigoVehiculo == codigo) {
            cout<<"Marca: "<<veh.marca<<endl;
            cout<<"Color: "<<veh.color<<endl;
            cout<<"Tipo de combustible: "<<veh.tipoCombustible<<endl;
        } else {
            cout<<"Vehiculo no encontrado"<<endl;
        }
    }
}
