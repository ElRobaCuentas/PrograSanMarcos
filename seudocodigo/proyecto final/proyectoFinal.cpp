#include <iostream>
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

struct Cliente {
    int codigoCliente;
    char dni[10];
    char nombres[30];
    char apellidos[30];
    char direccion[40];
    char telefono[15];
};

struct Venta {
    int numComprobante;
    int codigoVehiculo;
    int codigoCliente;
    int dia;
    int mes;
    int anio;
};

//PROTOTIPOS

// Menús
void menuPrincipal();
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
void mostrarTodosVeh(FILE *V, Vehiculo veh);

// Módulos Cliente
void crearArchivoCliente(FILE* C);
void registrarCliente(FILE* C, Cliente cli);
void mostrarUnCli(FILE* C, Cliente cli);
void mostrarTodosCli(FILE* C, Cliente cli);

//Modulos Venta
void crearArchivoVenta(FILE*S);
void registrarVenta(FILE*S, Venta ven);
void mostrarUnaVenta(FILE*S, Venta ven);
void mostrarTodasVentas(FILE*S, Venta ven);

bool existeCodigoVeh(int codigo);
bool existeCodigoCli(int codigo);

void obtenerDatosVehVenta(int codigo, Vehiculo &vehEncontrado);
void obtenerDatosCliente(int codigo, Cliente &cliEncontrado);

//Modulo Reportes

//reporte 1
void reporteClientesRentables(FILE *S, FILE *C);
int cargarClientes(FILE* C, Cliente clientes[], int max);
void procesarVentas(FILE* S, Cliente clientes[], int totalClientes, float totalGastado[], int numeroCompras[]);
void inicializarVectores(float totalGastado[], int numeroCompras[], int tam);
void ordenarClientesPorGasto(Cliente clientes[], float totalGastado[], int numeroCompras[], int totalClientes);
void mostrarClientesRentables(Cliente clientes[], float totalGastado[], int numeroCompras[], int totalClientes);

//reporte 2
void reporteVentasPorPeriodo();

//Principal

int main() {

    

    menuPrincipal();
    return 0;
}

void salir() {
    cout << "GRACIAS POR SU VISITA" << endl;
}

void menuPrincipal() {

    char opcion;

    do {
        cout<<"******"<<endl;
        cout<<"GESTION DE VENTAS DE AUTOMOVILES"<<endl;
        cout<<"1. VEHICULO"<<endl;
        cout<<"2. CLIENTE"<<endl;
        cout<<"3. VENTA"<<endl;
        cout<<"4. CONSULTAS"<<endl;
        cout<<"5. SALIR"<<endl;
        cout<<"******"<<endl;
        cout<<"Seleccione una opcion: ";
        cin >> opcion;
        // system("cls");

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
    Vehiculo V;

    do {
        cout<<"******"<<endl;
        cout<<"Menu Vehiculo"<<endl;
        cout<<"1. Crear archivo vehiculo"<<endl;
        cout<<"2. Registrar Vehiculo"<<endl;
        cout<<"3. Mostrar un vehiculo registrado"<<endl;
        cout<<"4. Mostrar todos los vehiculos registrados"<<endl;
        cout<<"5. Retornar menu principal"<<endl;
        cout<<"*****"<<endl;
        cout<<"Seleccione una opcion: ";
        cin >> opc_Veh;
        // system("cls");

        switch (opc_Veh) {

            case '1':
                crearArchivoVehiculo(NULL);
                break;

            case '2':
                registrarVehiculo(NULL, V); break;
            case '3':
                mostrarUnVeh(NULL, V); break;
            case '4':
                mostrarTodosVeh(NULL, V); break;
            case '5': break;
            default: cout<<"Opcion no valida \n"; break;
        }

    } while (opc_Veh != '5');
}

void menuCliente() {

    char opc_Cli;
    Cliente C;

    do {
        cout<<"*****"<<endl;
        cout<<"Menu Cliente"<<endl;
        cout<<"1. Crear archivo cliente"<<endl;
        cout<<"2. Registrar cliente"<<endl;
        cout<<"3. Mostrar un cliente registrado"<<endl;
        cout<<"4. Mostrar todos los clientes registrados"<<endl;
        cout<<"5. Retornar menu principal"<<endl;
        cout<<"******"<<endl;
        cout<<"Seleccione una opcion: ";
        cin >> opc_Cli;

        switch (opc_Cli) {
            case '1': crearArchivoCliente(NULL); break;
            case '2': registrarCliente(NULL, C); break;
            case '3': mostrarUnCli(NULL, C); break;
            case '4': mostrarTodosCli(NULL, C); break;
            case '5': break;
            default: cout<<"Opcion no valida\n"; break;
        }

    } while (opc_Cli != '5');
}

void menuVenta() {

    char opc_Ven;
    Venta Sventa; 

    do {
        cout<<"****"<<endl;
        cout<<"Menu Venta"<<endl;
        cout<<"1. Crear archivo venta"<<endl;
        cout<<"2. Registrar venta"<<endl;
        cout<<"3. Mostrar una venta"<<endl;
        cout<<"4. Mostrar todas las ventas"<<endl;
        cout<<"5. Retornar menu principal"<<endl;
        cout<<"****"<<endl;
        cout<<"Seleccione una opcion: ";
        cin >> opc_Ven;

        switch (opc_Ven) {

            case '1': crearArchivoVenta(NULL); break;
            case '2': registrarVenta(NULL, Sventa); break;
            case '3': mostrarUnaVenta(NULL, Sventa); break;
            case '4': mostrarTodasVentas(NULL, Sventa); break;
            case '5': break;
            default: cout<<"Opcion no valida\n"; break;
        }

    } while (opc_Ven != '5');
}

void menuConsulta() {
    char opc_Con;
    FILE *S;
    FILE *C;

    do {
        cout<<"*****"<<endl;
        cout<<"Menu Consultas"<<endl;
        cout<<"1. Reporte de ventas por periodo (mes/anio)"<<endl;
        cout<<"2. Reporte clientes mas rentables"<<endl;
        cout<<"3. Retornar al menu principal"<<endl;
        cout<<"******"<<endl;
        cout<<"Seleccione una opcion: ";
        cin >> opc_Con;

        switch (opc_Con) {
            case '1': reporteVentasPorPeriodo(); break; 
            case '2': reporteClientesRentables(S,C); break;
            case '3': break;
            default: cout<<"Opcion no valida\n"; break;
        }

    } while (opc_Con != '3');
}

//MODULOS VEHICULO
void crearArchivoVehiculo(FILE* V) {
    V = fopen("Vehiculo.txt", "w");

    if (V == NULL)
        cout<<"NO se pudo crear el archivo Vehiculo.txt"<<endl;
    else {
        cout<<"Creacion del archivo Vehiculo.txt exitosa"<<endl;
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
    gets(temp);

    V = fopen("Vehiculo.txt", "a");
    if(V != NULL) {
        fwrite(&veh, sizeof(veh), 1, V);
        if(!ferror(V)) { //validar
            cout<<"Vehiculo registrado con exito \n";
            fclose(V);
        }
        else
            cout << "Error al escribir en Vehiculo.txt\n";
    }
    else {
        cout << "No se pudo abrir Vehiculo.txt\n";
    }
}

void mostrarUnVeh(FILE *V, Vehiculo veh) {

    int codigo;
    bool encontrado = false;

    cout<<"Ingrese el codigo del vehiculo a buscar: ";
    cin>>codigo;

    V = fopen("Vehiculo.txt", "r");
    if (V == NULL) {
        cout<<"No se puede abrir el archivo Vehiculo\n";
    }
    else {
        while (fread(&veh, sizeof(veh), 1, V) == 1) {
            if (veh.codigoVehiculo == codigo) {
                cout<<"Codigo del vehiculo: "<<veh.codigoVehiculo<<endl;
                cout<<"Marca: "<<veh.marca<<endl;
                cout<<"Modelo: "<<veh.modelo<<endl;
                cout<<"Anio: "<<veh.anioFabricacion<<endl;
                cout<<"Color: "<<veh.color<<endl;
                cout<<"Precio de venta: "<<veh.precioVenta<<endl;
                encontrado = true;
            }
        }

        fclose(V);
    }

    if (encontrado == false) {
        cout<<"Vehiculo no encontrado\n";
    }
}

void mostrarTodosVeh(FILE *V, Vehiculo veh) {

    V = fopen("Vehiculo.txt", "r");

    if (V == NULL) {
        cout<<"No se pudo abrir Vehiculo.txt\n";
    }
    else {
        while (fread(&veh, sizeof(veh), 1, V) == 1) {
            cout<<"Codigo del vehiculo: "<<veh.codigoVehiculo<<endl;
            cout<<"Marca: "<<veh.marca<<endl;
            cout<<"Modelo: "<<veh.modelo<<endl;
            cout<<"Anio: "<<veh.anioFabricacion<<endl;
            cout<<"Color: "<<veh.color<<endl;
            cout<<"Precio de venta: "<<veh.precioVenta<<endl;
            cout<<"-----------------------------\n";
        }
        fclose(V);
    }
}

//MODULOS CLIENTE

void crearArchivoCliente(FILE* C) {
    C = fopen("Cliente.txt", "w");

    if (C == NULL)
        cout<<"NO se pudo crear el archivo Cliente.txt"<<endl;
    else {
        cout<<"Creacion del archivo Cliente.txt exitosa"<<endl;
        fclose(C);
    }
}

void registrarCliente(FILE* C, Cliente cli) {

    char temp[2];

    cout<<"Codigo del cliente: ";
    cin >> cli.codigoCliente;
    gets(temp);

    cout<<"Nombres: "; gets(cli.nombres);
    cout<<"Apellidos: "; gets(cli.apellidos);
    cout<<"DNI: "; gets(cli.dni);
    cout<<"Telefono: "; gets(cli.telefono);
    cout<<"Direccion: "; gets(cli.direccion);

    C = fopen("Cliente.txt", "a");

    if (C != NULL) {
        fwrite(&cli, sizeof(cli), 1, C);
        if (!ferror(C)) {
            cout<<"Cliente registrado con exito\n";
            fclose(C);
        } else {
            cout<<"Error al escribir en Cliente.txt\n";
        }
    }
    else {
        cout<<"No se pudo abrir Cliente.txt\n";
    }

}

void mostrarUnCli(FILE* C, Cliente cli) {

    int codigo;
    bool encontrado = false;

    cout<<"Ingrese el codigo del cliente a buscar: ";
    cin>>codigo;

    C = fopen("Cliente.txt", "r");
    if (C == NULL) {
        cout<<"No se puede abrir Cliente.txt\n";
    }
    else {
        while (fread(&cli, sizeof(cli), 1, C) == 1) {
            if (cli.codigoCliente == codigo) {
                cout<<"Nombres: "<<cli.nombres<<endl;
                cout<<"Apellidos: "<<cli.apellidos<<endl;
                cout<<"DNI: "<<cli.dni<<endl;
                cout<<"Telefono: "<<cli.telefono<<endl;
                cout<<"Direccion: "<<cli.direccion<<endl;
                encontrado = true;
            }
        }
        fclose(C);
    }

    if (!encontrado)
        cout<<"Cliente no encontrado\n";
}

void mostrarTodosCli(FILE* C, Cliente cli) {

    C = fopen("Cliente.txt", "r");

    if (C == NULL) {
        cout<<"No se pudo abrir Cliente.txt\n";
    }
    else {
        while (fread(&cli, sizeof(cli), 1, C) == 1) {
            cout<<"Nombres: "<<cli.nombres<<endl;
            cout<<"Apellidos: "<<cli.apellidos<<endl;
            cout<<"DNI: "<<cli.dni<<endl;
            cout<<"Telefono: "<<cli.telefono<<endl;
            cout<<"Direccion: "<<cli.direccion<<endl;
            cout<<"---------------------------\n";
        }
        fclose(C);
    }
}

//MODULOS VENTA

void crearArchivoVenta(FILE*S) {
    S = fopen("Ventas.txt", "w");

    if (S == NULL)
        cout<<"NO se pudo crear el archivo Ventas.txt"<<endl;
    else {
        cout<<"Creacion del archivo Ventas.txt exitosa"<<endl;
        fclose(S);
    }
}

void registrarVenta(FILE* S, Venta ven) {

    bool valido;
    Vehiculo veh; //para obtener precio de venta

    cout<<"Numero de comprobante: ";
    cin >> ven.numComprobante;

    valido = false;
    do {
        cout<<"Codigo Vehiculo: ";
        cin >> ven.codigoVehiculo;

        if (existeCodigoVeh(ven.codigoVehiculo) == true) {
            valido = true;
        }
        else {
            cout<<"Codigo de vehiculo NO existe. Ingrese nuevamente.\n";
        }

    } while (valido == false);

    obtenerDatosVehVenta(ven.codigoVehiculo, veh); //obtener vehiculo y su precio

    valido = false;
    do {
        cout<<"Codigo Cliente: ";
        cin >> ven.codigoCliente;

        if (existeCodigoCli(ven.codigoCliente) == true) {
            valido = true;
        }
        else {
            cout<<"Codigo de cliente no existe. Ingrese nuevamente.\n";
        }

    } while (valido == false);

    cout<<"Dia de venta: ";
    cin >> ven.dia;
    cout<<"Mes de venta: ";
    cin >> ven.mes;
    cout<<"Anio de venta: ";
    cin >> ven.anio;


    S = fopen("Ventas.txt", "a");
    if (S != NULL) {

        fwrite(&ven, sizeof(ven), 1, S);

        if (!ferror(S)) {
            cout<<"Venta registrada con exito\n";
            fclose(S);
        }
        else {
            cout<<"Error al escribir en Ventas.txt\n";
        }
    }
    else {
        cout<<"No se pudo abrir Ventas.txt\n";
    }
}

bool existeCodigoVeh(int codigo) {

    FILE*V;
    Vehiculo veh;

    bool existe = false;

    V = fopen("Vehiculo.txt", "r");
    if (V != NULL) {
        while (fread(&veh, sizeof(veh), 1, V) == 1) {
            if (veh.codigoVehiculo == codigo) {
                existe = true;
            }
        }
        fclose(V);
    }
    return existe;
}

bool existeCodigoCli(int codigo) {

    FILE *C;
    Cliente cli;
    bool existe = false;

    C = fopen("Cliente.txt", "r");

    if (C != NULL) {
        while (fread(&cli, sizeof(cli), 1, C) == 1) {
            if (cli.codigoCliente == codigo) {
                existe = true;
            }
        }
        fclose(C);
    }
    return existe;
}

void obtenerDatosVehVenta(int codigo, Vehiculo &vehEncontrado) {

    FILE *V;
    Vehiculo veh;
    bool encontrado = false;

    V = fopen("Vehiculo.txt", "r");

    if (V != NULL) {
        while (!encontrado && fread(&veh, sizeof(veh), 1, V) == 1) {

            if (veh.codigoVehiculo == codigo) {
                vehEncontrado = veh;
                encontrado = true;
            }
        }
        fclose(V);
    }
}

void obtenerDatosCliente(int codigo, Cliente &cliEncontrado) {

    FILE *C;
    Cliente cli;
    bool encontrado = false;

    C = fopen("Cliente.txt", "r");

    if (C != NULL) {
        while (!encontrado && fread(&cli, sizeof(cli), 1, C) == 1) {

            if (cli.codigoCliente == codigo) {
                cliEncontrado = cli;
                encontrado = true;
            }
        }
        fclose(C);
    }
}

void mostrarUnaVenta(FILE*S, Venta ven) {

    int comprobante;
    bool encontrado = false;

    cout<<"Ingrese el numero de comprobante: ";
    cin >> comprobante;

    S = fopen("Ventas.txt", "r");
    if (S == NULL) {
        cout<<"No se puede abrir Ventas.txt\n";
    }
    else {
        while (!encontrado && fread(&ven, sizeof(ven), 1, S) == 1) {

            if (ven.numComprobante == comprobante) {

                Vehiculo veh;
                obtenerDatosVehVenta(ven.codigoVehiculo, veh);

                Cliente cli;
                obtenerDatosCliente(ven.codigoCliente, cli);

                cout<<"Comprobante: "<<ven.numComprobante<<endl;
                cout<<"Fecha: "<<ven.dia<<"/"<<ven.mes<<"/"<<ven.anio<<endl;

                cout<<"\n--- Vehiculo ---\n";
                cout<<"Codigo: "<<veh.codigoVehiculo<<endl;
                cout<<"Marca: "<<veh.marca<<endl;
                cout<<"Modelo: "<<veh.modelo<<endl;
                cout<<"Anio: "<<veh.anioFabricacion<<endl;
                cout<<"Precio: "<<veh.precioVenta<<endl;

                cout<<"\n--- Cliente ---\n";
                cout<<"Codigo cliente: "<<cli.codigoCliente<<endl;
                cout<<"Nombres: "<<cli.nombres<<endl;
                cout<<"Apellidos: "<<cli.apellidos<<endl;
                cout<<"DNI: "<<cli.dni<<endl;

                cout<<"========================"<<endl;

                encontrado = true;
            }
        }

        fclose(S);
    }

    if (!encontrado)
        cout<<"Venta no encontrada\n";
}
	

void mostrarTodasVentas(FILE*S, Venta ven) {

    S = fopen("Ventas.txt", "r");

    if (S == NULL) {
        cout<<"No se puede abrir Ventas.txt\n";
    }
    else {
        while (fread(&ven, sizeof(ven), 1, S) == 1) {

            Vehiculo veh;
            obtenerDatosVehVenta(ven.codigoVehiculo, veh);

            Cliente cli;
            obtenerDatosCliente(ven.codigoCliente, cli);

            cout<<"Comprobante: "<<ven.numComprobante<<endl;
            cout<<"Fecha: "<<ven.dia<<"/"<<ven.mes<<"/"<<ven.anio<<endl;

            cout<<"\n--- Vehiculo ---\n";
            cout<<"Codigo: "<<veh.codigoVehiculo<<endl;
            cout<<"Marca: "<<veh.marca<<endl;
            cout<<"Modelo: "<<veh.modelo<<endl;
            cout<<"Anio: "<<veh.anioFabricacion<<endl;
            cout<<"Precio: "<<veh.precioVenta<<endl;

            cout<<"\n--- Cliente ---\n";
            cout<<"Codigo cliente: "<<cli.codigoCliente<<endl;
            cout<<"Nombres: "<<cli.nombres<<endl;
            cout<<"Apellidos: "<<cli.apellidos<<endl;
            cout<<"DNI: "<<cli.dni<<endl;

            cout<<"========================" << endl;
        }

        fclose(S);
    }
}

//Modulo Reportes
//Reporte de clientes mas rentables
int cargarClientes(FILE* C, Cliente clientes[], int max) {
    int total = 0;
    while (total < max && fread(&clientes[total], sizeof(Cliente), 1, C) == 1) {
        total++;
    }
    return total;
}

void inicializarVectores(float totalGastado[], int numeroCompras[], int tam) {
    int i = 0;
    while (i < tam) {
        totalGastado[i] = 0;
        numeroCompras[i] = 0;
        i++;
    }
}

void procesarVentas(FILE* S, Cliente clientes[], int totalClientes, float totalGastado[], int numeroCompras[]) {
    Venta ven;
    while (fread(&ven, sizeof(Venta), 1, S) == 1) {
        int i = 0;
        while (i < totalClientes) {
            if (clientes[i].codigoCliente == ven.codigoCliente) {
                Vehiculo v;
                obtenerDatosVehVenta(ven.codigoVehiculo, v);

                totalGastado[i] = totalGastado[i] + v.precioVenta;
                numeroCompras[i] = numeroCompras[i] + 1;
            }
            i++;
        }
    }
}

void ordenarClientesPorGasto(Cliente clientes[], float totalGastado[], int numeroCompras[], int totalClientes) {
    int i = 0;
    while (i < totalClientes - 1) {
        int j = i + 1;
        while (j < totalClientes) {
            if (totalGastado[j] > totalGastado[i]) {
                float auxTotal = totalGastado[i];
                totalGastado[i] = totalGastado[j];
                totalGastado[j] = auxTotal;

                int auxNum = numeroCompras[i];
                numeroCompras[i] = numeroCompras[j];
                numeroCompras[j] = auxNum;

                Cliente auxCli = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = auxCli;
            }
            j++;
        }
        i++;
    }
}

void mostrarClientesRentables(Cliente clientes[], float totalGastado[], int numeroCompras[], int totalClientes) {

    int limite;
    if (totalClientes < 5)
        limite = totalClientes;
    else
        limite = 5;
    cout << "\n----- CLIENTES MAS RENTABLES -----\n";

    int i = 0;
    while (i < limite) {

        cout << (i + 1)
            << ". Codigo: " << clientes[i].codigoCliente
            << " | Nombre: " << clientes[i].nombres
            << " " << clientes[i].apellidos
            << " | Compras: " << numeroCompras[i]
            << " | Total gastado: S/ " << totalGastado[i]
            << endl;
        i++;
    }
    cout << "----------------------------------\n";
}

void reporteClientesRentables(FILE* S, FILE* C) {

    S = fopen("Ventas.txt", "r");
    C = fopen("Cliente.txt", "r");

    if (S == NULL || C == NULL) {
        cout << "No se pudieron abrir los archivos.\n";
    }
    else {
        Cliente clientes[1000];
        float totalGastado[1000];
        int numeroCompras[1000];

        inicializarVectores(totalGastado, numeroCompras, 1000);

        int totalClientes = cargarClientes(C, clientes, 1000);

        procesarVentas(S, clientes, totalClientes, totalGastado, numeroCompras);

        ordenarClientesPorGasto(clientes, totalGastado, numeroCompras, totalClientes);

        mostrarClientesRentables(clientes, totalGastado, numeroCompras, totalClientes);

        fclose(S);
        fclose(C);
    }
}

//Reporte ventas por periodo
void reporteVentasPorPeriodo() {

    int mesBuscado, anioBuscado;
    bool hayVentas = false;
    float totalVendido = 0;

    cout << "Ingrese el mes: ";
    cin >> mesBuscado;

    cout << "Ingrese el anio: ";
    cin >> anioBuscado;

    FILE *S;
    Venta ven;

    S = fopen("Ventas.txt", "r");

    if (S == NULL) {
        cout << "No se puede abrir Ventas.txt\n";
    }
    else {
        cout << "\n=== REPORTE DE VENTAS DE "<< mesBuscado << "/" << anioBuscado << " ===\n";

        while (fread(&ven, sizeof(ven), 1, S) == 1) {
            if (ven.mes == mesBuscado && ven.anio == anioBuscado) {
                hayVentas = true;

                Vehiculo veh;
                obtenerDatosVehVenta(ven.codigoVehiculo, veh);

                cout << "Comprobante: " << ven.numComprobante << endl;
                cout << "Fecha: " << ven.dia << "/" << ven.mes << "/" << ven.anio << endl;
                cout << "Precio venta: " << veh.precioVenta << endl;
                cout << "-----------------------------\n";

                totalVendido += veh.precioVenta;
            }
        }

        fclose(S);
    }

    if (!hayVentas) {
        cout << "No hubo ventas en ese periodo.\n";
    }
    else {
        cout << "\nTOTAL VENDIDO EN " << mesBuscado << "/" << anioBuscado << ": "<< totalVendido << endl;
    }
}
