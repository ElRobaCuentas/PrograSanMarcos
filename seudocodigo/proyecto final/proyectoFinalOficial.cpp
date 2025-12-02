#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//ESTRUCTURAS
struct Vehiculo {
    int codigoVehiculo;
    char numChasis[50];
    char numMotor[50];
    char marca[50];
    char modelo[50];
    int anioFabricacion;
    char color[30];
    char tipoCombustible[30];
    char tipoTransmision[30];
    char tipoCarroceria[30];
    char proveedor[50];
    float precioVenta;
};

struct Cliente {
    int codigoCliente;
    char nombre[50];
    char apellido[50];
    char dni[20];
    char direccion[80];
    char telefono[20];
};

struct Venta {
    int codigoVenta;
    int codigoVehiculo;
    int codigoCliente;
    int dia;
    int mes;
    int anio;
};

//PROTOTIPOS
// Menus
void menuPrincipal(FILE *V, FILE *C, FILE *S, Vehiculo veh, Cliente cli, Venta ven);
void menuVehiculo(FILE *V, Vehiculo veh);
void menuCliente(FILE *C, Cliente cli);
void menuVenta(FILE *S, FILE *V, FILE *C, Vehiculo veh, Cliente cli, Venta ven);
void menuConsulta(FILE *S, FILE *C, FILE *V);

// Creacion de archivos
void crearArchivoVehiculo(FILE *V);
void crearArchivoCliente(FILE *C);
void crearArchivoVenta(FILE *S);

// Registro
void registrarVehiculo(FILE *V, Vehiculo veh);
void registrarCliente(FILE *C, Cliente cli);
void registrarVenta(FILE *S, Venta ven, FILE *V, FILE *C);

// Mostrar
void mostrarTodosVeh(FILE *V, Vehiculo veh);
void mostrarUnVeh(FILE *V, Vehiculo veh);

void mostrarTodosCli(FILE *C, Cliente cli);
void mostrarUnCli(FILE *C, Cliente cli);

void mostrarTodasVentas(FILE *S, Venta ven, FILE *V, FILE *C);
void mostrarUnaVenta(FILE *S, Venta ven, FILE *V, FILE *C);

bool existeCodigoVeh_enArchivo(FILE *V, int codigo);
bool existeCodigoCli_enArchivo(FILE *C, int codigo);
void obtenerDatosVehDesdeArchivo(FILE *V, int codigoVeh, Vehiculo &vehEncontrado);
void obtenerDatosCliDesdeArchivo(FILE *C, int codigoCli, Cliente &cliEncontrado);

// Reportes
void reporteVentasPorPeriodo(FILE *S, FILE *V);
void reporteClientesRentables(FILE *S, FILE *C, FILE *V);

//MAIN
int main() {

    FILE *V;
    FILE *C;
    FILE *S;

    Vehiculo veh;
    Cliente cli;
    Venta ven;

    menuPrincipal(V, C, S, veh, cli, ven);

    return 0;
}

//MENUS
void menuPrincipal(FILE *V, FILE *C, FILE *S, Vehiculo veh, Cliente cli, Venta ven) {
    char opc;
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Vehiculos\n";
        cout << "2. Clientes\n";
        cout << "3. Ventas\n";
        cout << "4. Consultas\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
            case '1': menuVehiculo(V, veh); break;
            case '2': menuCliente(C, cli); break;
            case '3': menuVenta(S, V, C, veh, cli, ven); break;
            case '4': menuConsulta(S, C, V); break;
            case '5': cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida\n"; break;
        }
    } while (opc != '5');
}

void menuVehiculo(FILE *V, Vehiculo veh) {
    char opc;
    do {
        cout << "\n--- MENU VEHICULO ---\n";
        cout << "1. Crear archivo vehiculo\n";
        cout << "2. Registrar vehiculo\n";
        cout << "3. Mostrar un vehiculo\n";
        cout << "4. Mostrar todos los vehiculos\n";
        cout << "5. Volver\n";
        cout << "Opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
            case '1': crearArchivoVehiculo(V); break;
            case '2': registrarVehiculo(V, veh); break;
            case '3': mostrarUnVeh(V, veh); break;
            case '4': mostrarTodosVeh(V, veh); break;
            case '5': break;
            default: cout << "Opcion invalida\n"; break;
        }
    } while (opc != '5');
}

void menuCliente(FILE *C, Cliente cli) {
    char opc;
    do {
        cout << "\n--- MENU CLIENTE ---\n";
        cout << "1. Crear archivo cliente\n";
        cout << "2. Registrar cliente\n";
        cout << "3. Mostrar un cliente\n";
        cout << "4. Mostrar todos los clientes\n";
        cout << "5. Volver\n";
        cout << "Opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
            case '1': crearArchivoCliente(C); break;
            case '2': registrarCliente(C, cli); break;
            case '3': mostrarUnCli(C, cli); break;
            case '4': mostrarTodosCli(C, cli); break;
            case '5': break;
            default: cout << "Opcion invalida\n"; break;
        }
    } while (opc != '5');
}

void menuVenta(FILE *S, FILE *V, FILE *C, Vehiculo veh, Cliente cli, Venta ven) {
    char opc;
    do {
        cout << "\n--- MENU VENTA ---\n";
        cout << "1. Crear archivo venta\n";
        cout << "2. Registrar venta\n";
        cout << "3. Mostrar una venta\n";
        cout << "4. Mostrar todas las ventas\n";
        cout << "5. Volver\n";
        cout << "Opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
            case '1': crearArchivoVenta(S); break;
            case '2': registrarVenta(S, ven, V, C); break; // V, C se usan internamente en registrarVenta
            case '3': mostrarUnaVenta(S, ven, V, C); break;
            case '4': mostrarTodasVentas(S, ven, V, C); break;
            case '5': break;
            default: cout << "Opcion invalida\n"; break;
        }
    } while (opc != '5');
}

void menuConsulta(FILE *S, FILE *C, FILE *V) {
    char opc;
    do {
        cout << "\n--- MENU CONSULTAS ---\n";
        cout << "1. Reporte ventas por periodo\n";
        cout << "2. Clientes mas rentables\n";
        cout << "3. Volver\n";
        cout << "Opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
            case '1': reporteVentasPorPeriodo(S, V); break;
            case '2': reporteClientesRentables(S, C, V); break;
            case '3': break;
            default: cout << "Opcion invalida\n"; break;
        }
    } while (opc != '3');
}

//CREACION DE ARCHIVOS
void crearArchivoVehiculo(FILE *V) {
    V = fopen("Vehiculos.txt", "w");
    if (V != NULL) {
        fclose(V);
        cout << "Vehiculos.txt creado\n";
    } else {
        cout << "Error creando Vehiculos.txt\n";
    }
}

void crearArchivoCliente(FILE *C) {
    C = fopen("Clientes.txt", "w");
    if (C != NULL) {
        fclose(C);
        cout << "Clientes.txt creado\n";
    } else {
        cout << "Error creando Clientes.txt\n";
    }
}

void crearArchivoVenta(FILE *S) {
    S = fopen("Ventas.txt", "w");
    if (S != NULL) {
        fclose(S);
        cout << "Ventas.txt creado\n";
    } else {
        cout << "Error creando Ventas.txt\n";
    }
}

//REGISTRO
void registrarVehiculo(FILE* V, Vehiculo veh) {
    char temp[2];

    cout << "Codigo del vehiculo: "; cin >> veh.codigoVehiculo;
    gets(temp);
    cout << "Numero de chasis: "; gets(veh.numChasis);
    cout << "Numero de motor: "; gets(veh.numMotor);
    cout << "Marca: "; gets(veh.marca);
    cout << "Modelo: "; gets(veh.modelo);
    cout << "Anio de fabricacion: "; cin >> veh.anioFabricacion;
    gets(temp);
    cout << "Color: "; gets(veh.color);
    cout << "Tipo de combustible: "; gets(veh.tipoCombustible);
    cout << "Tipo de transmision: "; gets(veh.tipoTransmision);
    cout << "Tipo de carroceria: "; gets(veh.tipoCarroceria);
    cout << "Proveedor: "; gets(veh.proveedor);
    cout << "Precio de venta: "; cin >> veh.precioVenta;
    gets(temp);

    V = fopen("Vehiculos.txt", "a");
    if (V != NULL) {
        fwrite(&veh, sizeof(Vehiculo), 1, V);
        if (!ferror(V)) {
            cout << "Vehiculo registrado con exito\n";
            fclose(V);
        } else {
            cout << "Error al escribir en Vehiculos.txt\n";
            fclose(V);
        }
    } else {
        cout << "No se pudo abrir Vehiculos.txt\n";
    }
}

void registrarCliente(FILE *C, Cliente cli) {
    char temp[2];

    cout << "Codigo del cliente: "; cin >> cli.codigoCliente;
    gets(temp);
    cout << "Nombre: "; gets(cli.nombre);
    cout << "Apellido: "; gets(cli.apellido);
    cout << "DNI: "; gets(cli.dni);
    cout << "Direccion: "; gets(cli.direccion);
    cout << "Telefono: "; gets(cli.telefono);

    C = fopen("Clientes.txt", "a");
    if (C != NULL) {
        fwrite(&cli, sizeof(Cliente), 1, C);
        if (!ferror(C)) {
            cout << "Cliente registrado con exito\n";
            fclose(C);
        } else {
            cout << "Error al escribir en Clientes.txt\n";
            fclose(C);
        }
    } else {
        cout << "No se pudo abrir Clientes.txt\n";
    }
}

void registrarVenta(FILE *S, Venta ven, FILE *V, FILE *C) {
    char temp[2];
    bool error = false;
    bool validoVeh = false;
    bool validoCli = false;

    cout << "Codigo de venta: "; cin >> ven.codigoVenta;
    gets(temp);

    while (!validoVeh && !error) {
        cout << "Codigo del vehiculo: "; cin >> ven.codigoVehiculo;
        gets(temp);

        V = fopen("Vehiculos.txt", "r");
        if (V == NULL) {
            cout << "No existe Vehiculos.txt para validar\n";
            error = true;
        } else {
            if (existeCodigoVeh_enArchivo(V, ven.codigoVehiculo)) {
                validoVeh = true;
            } else {
                cout << "Codigo de vehiculo NO existe\n";
            }
            fclose(V);
        }
    }

    // VALIDAR CLIENTE
    while (!validoCli && !error) {
        cout << "Codigo del cliente: "; cin >> ven.codigoCliente;
        gets(temp);

        C = fopen("Clientes.txt", "r");
        if (C == NULL) {
            cout << "No existe Clientes.txt para validar\n";
            error = true;
        } else {
            if (existeCodigoCli_enArchivo(C, ven.codigoCliente)) {
                validoCli = true;
            } else {
                cout << "Codigo de cliente NO existe\n";
            }
            fclose(C);
        }
    }

    if (!error && validoVeh && validoCli) {
        cout << "Dia: "; cin >> ven.dia;
        cout << "Mes: "; cin >> ven.mes;
        cout << "Anio: "; cin >> ven.anio;
        gets(temp);

        S = fopen("Ventas.txt", "a");
        if (S != NULL) {
            fwrite(&ven, sizeof(Venta), 1, S);
            if (!ferror(S)) {
                cout << "Venta registrada con exito\n";
                fclose(S);
            } else {
                cout << "Error al escribir en Ventas.txt\n";
                fclose(S);
            }
        } else {
            cout << "No se pudo abrir Ventas.txt\n";
        }
    } else {
        if (error) cout << "No se pudo completar registro de venta por error en archivos\n";
    }
}

//MOSTRAR
void mostrarTodosVeh(FILE *V, Vehiculo veh) {
    V = fopen("Vehiculos.txt", "r");
    if (V == NULL) {
        cout << "No existe Vehiculos.txt\n";
    } else {
        fread(&veh, sizeof(Vehiculo), 1, V);
        while (!feof(V)) {
            cout << "-------------------------\n";
            cout << "Codigo: " << veh.codigoVehiculo << "\n";
            cout << "Chasis: " << veh.numChasis << "\n";
            cout << "Motor: " << veh.numMotor << "\n";
            cout << "Marca: " << veh.marca << "\n";
            cout << "Modelo: " << veh.modelo << "\n";
            cout << "Anio: " << veh.anioFabricacion << "\n";
            cout << "Color: " << veh.color << "\n";
            cout << "Combustible: " << veh.tipoCombustible << "\n";
            cout << "Transmision: " << veh.tipoTransmision << "\n";
            cout << "Carroceria: " << veh.tipoCarroceria << "\n";
            cout << "Proveedor: " << veh.proveedor << "\n";
            cout << "Precio: " << veh.precioVenta << "\n";

            fread(&veh, sizeof(Vehiculo), 1, V);
        }
        fclose(V);
    }
}

void mostrarUnVeh(FILE *V, Vehiculo veh) {
    int codigoBuscado;
    cout << "Ingrese codigo del vehiculo: ";
    cin >> codigoBuscado;
    cin.ignore();

    V = fopen("Vehiculos.txt", "r");
    if (V == NULL) {
        cout << "No existe Vehiculos.txt\n";
    } else {
        fread(&veh, sizeof(Vehiculo), 1, V);
        while (!feof(V)) {
            if (veh.codigoVehiculo == codigoBuscado) {
                cout << "-------------------------\n";
                cout << "Codigo: " << veh.codigoVehiculo << "\n";
                cout << "Chasis: " << veh.numChasis << "\n";
                cout << "Motor: " << veh.numMotor << "\n";
                cout << "Marca: " << veh.marca << "\n";
                cout << "Modelo: " << veh.modelo << "\n";
                cout << "Anio: " << veh.anioFabricacion << "\n";
                cout << "Color: " << veh.color << "\n";
                cout << "Combustible: " << veh.tipoCombustible << "\n";
                cout << "Transmision: " << veh.tipoTransmision << "\n";
                cout << "Carroceria: " << veh.tipoCarroceria << "\n";
                cout << "Proveedor: " << veh.proveedor << "\n";
                cout << "Precio: " << veh.precioVenta << "\n";
                // Notamos el registro pero seguimos leyendo hasta el EOF (estilo del PDF)
            }
            fread(&veh, sizeof(Vehiculo), 1, V);
        }
        fclose(V);
    }
}

void mostrarTodosCli(FILE *C, Cliente cli) {
    C = fopen("Clientes.txt", "r");
    if (C == NULL) {
        cout << "No existe Clientes.txt\n";
    } else {
        fread(&cli, sizeof(Cliente), 1, C);
        while (!feof(C)) {
            cout << "-------------------------\n";
            cout << "Codigo: " << cli.codigoCliente << "\n";
            cout << "Nombre: " << cli.nombre << " " << cli.apellido << "\n";
            cout << "DNI: " << cli.dni << "\n";
            cout << "Direccion: " << cli.direccion << "\n";
            cout << "Telefono: " << cli.telefono << "\n";
            fread(&cli, sizeof(Cliente), 1, C);
        }
        fclose(C);
    }
}

void mostrarUnCli(FILE *C, Cliente cli) {
    int codigoBuscado;
    cout << "Ingrese codigo cliente: ";
    cin >> codigoBuscado;
    cin.ignore();

    C = fopen("Clientes.txt", "r");
    if (C == NULL) {
        cout << "No existe Clientes.txt\n";
    } else {
        fread(&cli, sizeof(Cliente), 1, C);
        while (!feof(C)) {
            if (cli.codigoCliente == codigoBuscado) {
                cout << "-------------------------\n";
                cout << "Codigo: " << cli.codigoCliente << "\n";
                cout << "Nombre: " << cli.nombre << " " << cli.apellido << "\n";
                cout << "DNI: " << cli.dni << "\n";
                cout << "Direccion: " << cli.direccion << "\n";
                cout << "Telefono: " << cli.telefono << "\n";
            }
            fread(&cli, sizeof(Cliente), 1, C);
        }
        fclose(C);
    }
}

void mostrarTodasVentas(FILE *S, Venta ven, FILE *V, FILE *C) {
    S = fopen("Ventas.txt", "r");
    if (S == NULL) {
        cout << "No existe Ventas.txt\n";
    } else {
        fread(&ven, sizeof(Venta), 1, S);
        while (!feof(S)) {
            cout << "-------------------------\n";
            cout << "Codigo venta: " << ven.codigoVenta << "\n";
            cout << "Fecha: " << ven.dia << "/" << ven.mes << "/" << ven.anio << "\n";

            // Abrir Vehiculos para obtener datos (usando V PASADO como parametro local)
            V = fopen("Vehiculos.txt", "r");
            if (V != NULL) {
                Vehiculo vehBuscado;
                obtenerDatosVehDesdeArchivo(V, ven.codigoVehiculo, vehBuscado);
                cout << "Vehiculo: " << vehBuscado.marca << " " << vehBuscado.modelo << " Precio: " << vehBuscado.precioVenta << "\n";
                fclose(V);
            } else {
                cout << "Datos de vehiculo no disponibles\n";
            }

            // Abrir Clientes para obtener datos
            C = fopen("Clientes.txt", "r");
            if (C != NULL) {
                Cliente cliBuscado;
                obtenerDatosCliDesdeArchivo(C, ven.codigoCliente, cliBuscado);
                cout << "Cliente: " << cliBuscado.nombre << " " << cliBuscado.apellido << "\n";
                fclose(C);
            } else {
                cout << "Datos de cliente no disponibles\n";
            }

            fread(&ven, sizeof(Venta), 1, S);
        }
        fclose(S);
    }
}

void mostrarUnaVenta(FILE *S, Venta ven, FILE *V, FILE *C) {
    int codigoBuscado;
    cout << "Ingrese codigo de venta: ";
    cin >> codigoBuscado;
    cin.ignore();

    S = fopen("Ventas.txt", "r");
    if (S == NULL) {
        cout << "No existe Ventas.txt\n";
    } else {
        fread(&ven, sizeof(Venta), 1, S);
        while (!feof(S)) {
            if (ven.codigoVenta == codigoBuscado) {
                cout << "-------------------------\n";
                cout << "Codigo venta: " << ven.codigoVenta << "\n";
                cout << "Fecha: " << ven.dia << "/" << ven.mes << "/" << ven.anio << "\n";

                V = fopen("Vehiculos.txt", "r");
                if (V != NULL) {
                    Vehiculo vehBuscado;
                    obtenerDatosVehDesdeArchivo(V, ven.codigoVehiculo, vehBuscado);
                    cout << "Vehiculo: " << vehBuscado.marca << " " << vehBuscado.modelo << " Precio: " << vehBuscado.precioVenta << "\n";
                    fclose(V);
                } else {
                    cout << "Datos de vehiculo no disponibles\n";
                }

                C = fopen("Clientes.txt", "r");
                if (C != NULL) {
                    Cliente cliBuscado;
                    obtenerDatosCliDesdeArchivo(C, ven.codigoCliente, cliBuscado);
                    cout << "Cliente: " << cliBuscado.nombre << " " << cliBuscado.apellido << "\n";
                    fclose(C);
                } else {
                    cout << "Datos de cliente no disponibles\n";
                }
                // continuar hasta EOF (no break)
            }
            fread(&ven, sizeof(Venta), 1, S);
        }
        fclose(S);
    }
}

//EXTRAS
bool existeCodigoVeh_enArchivo(FILE *V, int codigo) {
    bool existe = false;
    if (V != NULL) {
        Vehiculo tmpVeh;
        fread(&tmpVeh, sizeof(Vehiculo), 1, V);
        while (!feof(V)) {
            if (tmpVeh.codigoVehiculo == codigo) {
                existe = true;
            }
            fread(&tmpVeh, sizeof(Vehiculo), 1, V);
        }
        // No cerramos V aquí
    }
    return existe;
}

bool existeCodigoCli_enArchivo(FILE *C, int codigo) {
    bool existe = false;
    if (C != NULL) {
        Cliente tmpCli;
        fread(&tmpCli, sizeof(Cliente), 1, C);
        while (!feof(C)) {
            if (tmpCli.codigoCliente == codigo) {
                existe = true;
            }
            fread(&tmpCli, sizeof(Cliente), 1, C);
        }
        // No cerramos C aquí
    }
    return existe;
}

void obtenerDatosVehDesdeArchivo(FILE *V, int codigoVeh, Vehiculo &vehEncontrado) {
    // Asumimos V ya abierto por el llamador y posicionado al inicio
    if (V != NULL) {
        Vehiculo tmpVeh;
        fread(&tmpVeh, sizeof(Vehiculo), 1, V);
        while (!feof(V)) {
            if (tmpVeh.codigoVehiculo == codigoVeh) {
                vehEncontrado = tmpVeh;
            }
            fread(&tmpVeh, sizeof(Vehiculo), 1, V);
        }
    } else {
        // Dejar vehEncontrado sin modificar si no hay archivo
    }
}

void obtenerDatosCliDesdeArchivo(FILE *C, int codigoCli, Cliente &cliEncontrado) {
    if (C != NULL) {
        Cliente tmpCli;
        fread(&tmpCli, sizeof(Cliente), 1, C);
        while (!feof(C)) {
            if (tmpCli.codigoCliente == codigoCli) {
                cliEncontrado = tmpCli;
            }
            fread(&tmpCli, sizeof(Cliente), 1, C);
        }
    }
}

//REPORTES
void reporteVentasPorPeriodo(FILE *S, FILE *V) {
    int mesBuscado, anioBuscado;
    cout << "Ingrese mes (1-12): "; cin >> mesBuscado;
    cout << "Ingrese anio: "; cin >> anioBuscado;
    cin.ignore();

    S = fopen("Ventas.txt", "r");
    if (S == NULL) {
        cout << "No existe Ventas.txt\n";
    } else {
        Venta ven;
        float totalVendido = 0.0f;
        bool huboVentas = false;

        fread(&ven, sizeof(Venta), 1, S);
        while (!feof(S)) {
            if (ven.mes == mesBuscado && ven.anio == anioBuscado) {
                huboVentas = true;
                V = fopen("Vehiculos.txt", "r");
                if (V != NULL) {
                    Vehiculo vehBuscado;
                    obtenerDatosVehDesdeArchivo(V, ven.codigoVehiculo, vehBuscado);
                    cout << "Comprobante: " << ven.codigoVenta << " - Precio: " << vehBuscado.precioVenta << "\n";
                    totalVendido += vehBuscado.precioVenta;
                    fclose(V);
                } else {
                    cout << "Vehiculos.txt no disponible\n";
                }
            }
            fread(&ven, sizeof(Venta), 1, S);
        }

        fclose(S);

        if (!huboVentas) cout << "No hubo ventas en ese periodo\n";
        else cout << "Total vendido en " << mesBuscado << "/" << anioBuscado << ": " << totalVendido << "\n";
    }
}

void reporteClientesRentables(FILE *S, FILE *C, FILE *V) {
    S = fopen("Ventas.txt", "r");
    C = fopen("Clientes.txt", "r");

    if (S == NULL || C == NULL) {
        cout << "No se pudieron abrir archivos necesarios para el reporte\n";
        if (S != NULL) fclose(S);
        if (C != NULL) fclose(C);
    } else {
        // Cargar clientes en array
        const int MAXC = 500;
        Cliente clientes[MAXC];
        int totalClientes = 0;

        fread(&clientes[totalClientes], sizeof(Cliente), 1, C);
        while (!feof(C) && totalClientes < MAXC) {
            totalClientes++;
            fread(&clientes[totalClientes], sizeof(Cliente), 1, C);
        }
        fclose(C);

        // vectores de acumulacion
        float totalGastado[MAXC];
        int numeroCompras[MAXC];
        int i;
        for (i = 0; i < totalClientes; i++) {
            totalGastado[i] = 0.0f;
            numeroCompras[i] = 0;
        }

        // Recorrer ventas y acumular por cliente
        Venta ven;
        fread(&ven, sizeof(Venta), 1, S);
        while (!feof(S)) {
            // buscar cliente en array cargado
            for (i = 0; i < totalClientes; i++) {
                if (clientes[i].codigoCliente == ven.codigoCliente) {
                    // obtener precio vehiculo
                    V = fopen("Vehiculos.txt", "r");
                    if (V != NULL) {
                        Vehiculo vehBuscado;
                        obtenerDatosVehDesdeArchivo(V, ven.codigoVehiculo, vehBuscado);
                        totalGastado[i] += vehBuscado.precioVenta;
                        numeroCompras[i] += 1;
                        fclose(V);
                    } else {
                        // si no hay vehiculos.txt, omitimos
                    }
                    break; // cliente encontrado para esta venta
                }
            }
            fread(&ven, sizeof(Venta), 1, S);
        }
        fclose(S);

        // Ordenar por totalGastado (burbuja simple)
        int a, b;
        for (a = 0; a < totalClientes - 1; a++) {
            for (b = a + 1; b < totalClientes; b++) {
                if (totalGastado[b] > totalGastado[a]) {
                    // swap totales
                    float tmpF = totalGastado[a]; totalGastado[a] = totalGastado[b]; totalGastado[b] = tmpF;
                    int tmpN = numeroCompras[a]; numeroCompras[a] = numeroCompras[b]; numeroCompras[b] = tmpN;
                    // swap cliente struct
                    Cliente tmpC = clientes[a]; clientes[a] = clientes[b]; clientes[b] = tmpC;
                }
            }
        }

        // Imprimir top 5 o menos
        int limite = totalClientes;
        if (limite > 5) limite = 5;
        cout << "---- TOP " << limite << " CLIENTES MAS RENTABLES ----\n";
        for (i = 0; i < limite; i++) {
            cout << (i + 1) << ". Codigo: " << clientes[i].codigoCliente
                << " - Nombre: " << clientes[i].nombre << " " << clientes[i].apellido
                << " - Compras: " << numeroCompras[i]
                << " - Total: " << totalGastado[i] << "\n";
        }
    }
}

