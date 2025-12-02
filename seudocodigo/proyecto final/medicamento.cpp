#include <iostream>

using namespace std;

// Estructuras
struct Medicamento {
    char nombreM[50];
    int codigoDelMedicamento;
    char tipo; // GENERICO O DE MARCA "G" O "M"
    int diaVencimiento;
    int mesVencimiento;
    int anioVencimiento;
    float precioxU;
    bool esReceta;
};

struct Cliente {
    char nombreCliente[50];
    int codigoC;
    char dni[15];
    char genero;
    int telefono;
    char correo[50];
};

struct Venta {
    int codigoC;
    int codigoM;
    int numeroBoleta;
    int diaEmision;
    int mesEmision;
    int anioEmision;
    int cantidadVendida;
    float precioxU;
    float costoT;
    float vuelto; // CALCULO AUTOMATICO
};

// Prototipos
int menuPrincipal();
int menuMedicamento();
int menuCliente();
int menuVenta();
int menuConsultas();

void crearArchivoMed(FILE *M);
void ingresarMed(FILE *M, Medicamento med);
void mostrarTodosMed(FILE *M, Medicamento med);
void mostrarUnoMed(FILE *M, Medicamento med);
void controladorMedicamentos(FILE *M, Medicamento med);

void crearArchivoCli(FILE *C);
void ingresarCli(FILE *C, Cliente cli);
void mostrarTodosCli(FILE *C, Cliente cli);
void mostrarUnoCli(FILE *C, Cliente cli);
void controladorClientes(FILE *C, Cliente cli);

void crearArchivoVen(FILE *V);
void realizarVenta(FILE *V, Venta ven);
bool existeCodigoCliente(int codigo);
bool existeCodigoMedicamento(int codigo);
void controladorVentas(FILE *V, Venta ven);

void reporteClientesRentables(FILE *V, FILE *C);
int cargarClientes(FILE* C, Cliente clientes[], int max);
void procesarVentas(FILE* V, Cliente clientes[], int totalClientes, float totalGastado[], int numeroCompras[]);
void inicializarVectores(float totalGastado[], int numeroCompras[], int tam);
void ordenarClientesPorGasto(Cliente clientes[], float totalGastado[], int numeroCompras[], int totalClientes);
void mostrarClientesRentables(Cliente clientes[], float totalGastado[], int numeroCompras[], int totalClientes);

void reporteMasVendidos(FILE *V, FILE *M);
int cargarMedicamentos(FILE* M, int codigos[], char nombres[][50], int max);
void inicializarContadores(int totalVendidas[], int tam);
void procesarVentas(FILE* V, int codigos[], char nombres[][50], int totalMeds, char nombresUnicos[][50], int totalVendidas[], int* totalNombres);
void ordenarPorVentas(char nombresUnicos[][50], int totalVendidas[], int totalNombres);
void mostrarMasVendidos(char nombresUnicos[][50], int totalVendidas[], int totalNombres);

void controladorConsultas();

bool confirmarSalir();
void salir();


int main() {
    int opc;
    FILE *M, *C, *V;
    Medicamento med;
    Cliente cli;
    Venta ven;
    while (true) {
        system("cls");
        opc = menuPrincipal();
        if (opc == 5) {
            salir();
            break;
        }
        switch(opc) {
            case 1: controladorMedicamentos(M, med); 
					break;
            case 2: controladorClientes(C, cli); 
					break;
            case 3: controladorVentas(V, ven); 
					break;
            case 4: controladorConsultas(); 
					break;
        }
    }
    system("pause");
    return 0;
}

// Menus
int menuPrincipal() {
    int op;
    cout << "GESTION DE VENTAS DE AUTOMOVILES\n";
	cout<<" --- MENU PRINCIPAL ---\n";
    cout << "1. VEHICULO\n";
    cout << "2. CLIENTE\n";
    cout << "3. VENTA\n";
    cout << "4. CONSULTAS\n";
    cout << "5. SALIR\n"; 
    cout << "Seleccione opcion: ";
    cin >> op;
    if (op == 5 && confirmarSalir()==false) {
        op = 0;
    }
    system("cls");
    return op;
}

int menuMedicamento() {
    int op;
    cout << "\n--- MENU VEHICULO ---\n";
    cout << "1. CREAR\n";
    cout << "2. INGRESAR\n";
    cout << "3. MOSTRAR TODOS\n";
    cout << "4. MOSTRAR UN VEHICULO\n";
    cout << "5. RETORNAR\n";
    cout << "Seleccione opcion: ";
    cin >> op;
    system("cls");
    return op;
}

int menuCliente() {
    int op;
    // cout << "** BOTICA TRISALUD **";
    cout << "\n--- MENU CLIENTE ---\n";
    cout << "1. CREAR\n";
    cout << "2. INGRESAR\n";
    cout << "3. MOSTRAR TODOS\n";
    cout << "4. MOSTRAR UN CLIENTE\n";
    cout << "5. RETORNAR\n";
    cout << "Seleccione opcion: ";
    cin >> op;
    system("cls");
    return op;
}

int menuVenta() {
	// cout << "** BOTICA TRISALUD **";
    int op;
    cout << "\n--- MENU VENTA ---\n";
    cout << "1. CREAR\n";
    cout << "2. REALIZAR VENTA\n";
    cout << "3. RETORNAR\n";
    cout << "Seleccione opcion: ";
    cin >> op;
    system("cls");
    return op;
}

int menuConsultas() {
    int op;
    // cout << "** BOTICA TRISALUD **";
    cout << "\n--- MENU CONSULTAS ---\n";
    cout << "1. REPORTE DE CLIENTES MAS RENTABLES\n";
    cout << "2. REPORTE DE MARCAS DE AUTOS MAS VENDIDAS\n";
    cout << "3. RETORNAR\n";
    cout << "Seleccione opcion: ";
    cin >> op;
    system("cls");
    return op;
}


// Funciones de Medicamento
void crearArchivoMed(FILE *M) {
    M = fopen("Autos.txt", "w");
    if (M == NULL)
        cout << "No se pudo crear el archivo de autos\n";
    else {
        cout << "Archivo de autos creado con exito\n";
        fclose(M);
    }
}

void ingresarMed(FILE *M, Medicamento med) {
    cin.ignore();
    cout << "Ingrese nombre del medicamento: "; cin.getline(med.nombreM, 50);
    cout << "Codigo del medicamento: "; cin >> med.codigoDelMedicamento;
    cout << "Tipo (g/m): "; cin >> med.tipo;
    cout << "Fecha de vencimiento (dd mm aaaa): \n"; 
	cout<<"Dia: "; cin >> med.diaVencimiento;
	cout<<"Mes: "; cin >> med.mesVencimiento;
	cout<<"Anio: "; cin >> med.anioVencimiento;
    cout << "Precio por unidad: "; cin >> med.precioxU;
    cout << "Requiere receta? (1=Si, 0=No): "; cin >> med.esReceta;
    M = fopen("Medicamentos.txt", "a");
    if (M != NULL) {
        fwrite(&med, sizeof(med), 1, M);
        fclose(M);
        cout << "Medicamento ingresado con exito.\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

void mostrarTodosMed(FILE *M, Medicamento med) {
    M = fopen("Medicamentos.txt", "r");
    if (M == NULL) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    while (!feof(M)) {
    	fread(&med, sizeof(med), 1, M);
    	if (!feof(M)) {
	        cout << "\nNombre: " << med.nombreM << endl;
	        cout << "Codigo: " << med.codigoDelMedicamento << endl;
	        cout << "Tipo: ";
			if (med.tipo == 'g')
        		cout << "Generico" << endl;
			else
        		cout << "Marca" << endl;
	        cout << "Vencimiento: " << med.diaVencimiento << "/" << med.mesVencimiento << "/" << med.anioVencimiento << endl;
	        cout << "Precio x U: " << med.precioxU << endl;
	        cout << "Requiere receta: " ;
			    if (med.esReceta) 
			        cout << "Si" << endl;
				else
			        cout << "No" << endl;
	        cout << "--------------------------\n";
    	}
	}	
    fclose(M);
}

void mostrarUnoMed(FILE *M, Medicamento med) {
    int codigo;
    bool encontrado = false;
    cout << "Ingrese codigo del medicamento a buscar: ";
    cin >> codigo;
    M = fopen("Medicamentos.txt", "r");
    if (M == NULL) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
	while (!feof(M)) {
	    fread(&med, sizeof(med), 1, M);
	    if (!feof(M))
	        if (med.codigoDelMedicamento == codigo) {
	            cout << "\nNombre: " << med.nombreM << endl;
	            cout << "Codigo: " << med.codigoDelMedicamento << endl;
	            cout << "Tipo: ";
	            if (med.tipo == 'g')
	                cout << "Generico" << endl;
	            else
	                cout << "Marca" << endl;	
	            cout << "Vencimiento: " << med.diaVencimiento << "/" << med.mesVencimiento << "/" << med.anioVencimiento << endl;
	            cout << "Precio x U: " << med.precioxU << endl;
	            cout << "Requiere receta: ";
	            if (med.esReceta)
	                cout << "Si" << endl;
	            else
	                cout << "No" << endl;
	            cout << "--------------------------\n";
	            encontrado = true;
	            break;
	        }
	}
    if (encontrado == false) 
		cout << "Medicamento no encontrado.\n";
    fclose(M);
}

void controladorMedicamentos(FILE *M, Medicamento med) {
    int sub;
    do {
        sub = menuMedicamento();
        switch(sub) {
            case 1: crearArchivoMed(M); 
				break;
            case 2: ingresarMed(M, med); 
				break;
            case 3: mostrarTodosMed(M, med); 
				break;
            case 4: mostrarUnoMed(M, med); 
				break;
            case 5: 
				break;
            default: cout << "Opcion invalida.\n"; 
				break;
        }
    } while (sub != 5);
}

// Funciones Cliente
void crearArchivoCli(FILE *C) {
    C = fopen("Clientes.txt", "w");
    if (C == NULL)
        cout << "No se pudo crear el archivo de clientes.\n";
    else {
        cout << "Archivo de clientes creado con exito.\n";
        fclose(C);
    }
}

void ingresarCli(FILE *C, Cliente cli) {
    cin.ignore();
    cout << "Ingrese nombre del cliente: "; cin.getline(cli.nombreCliente, 50);
    cout << "Codigo: "; cin >> cli.codigoC;
    cin.ignore();
    cout << "DNI: "; cin.getline(cli.dni, 15);
    cout << "Genero (M/F): "; cin >> cli.genero;
    cout << "Telefono: "; cin >> cli.telefono;
    cin.ignore();
    cout << "Correo: "; cin.getline(cli.correo, 50);
    C = fopen("Clientes.txt", "a");
    if (C != NULL) {
        fwrite(&cli, sizeof(cli), 1, C);
        fclose(C);
        cout << "Cliente registrado con exito.\n";
    } else {
        cout << "Error al abrir archivo.\n";
    }
}

void mostrarTodosCli(FILE *C, Cliente cli) {
    C = fopen("Clientes.txt", "r");
    if (C == NULL) {
        cout << "No se pudo abrir archivo.\n";
        return;
    }
    while (!feof(C)) {
        fread(&cli, sizeof(cli), 1, C);
        if (!feof(C)) {
            cout << "\nNombre: " << cli.nombreCliente << endl;
            cout << "Codigo: " << cli.codigoC << endl;
            cout << "DNI: " << cli.dni << endl;
            cout << "Genero: " << cli.genero << endl;
            cout << "Telefono: " << cli.telefono << endl;
            cout << "Correo: " << cli.correo << endl;
            cout << "--------------------------\n";
        }
    }
    fclose(C);
}

void mostrarUnoCli(FILE *C, Cliente cli) {
    int codigo;
    bool encontrado = false;
    cout << "Ingrese codigo del cliente a buscar: ";
    cin >> codigo;
    C = fopen("Clientes.txt", "r");
    if (C == NULL) {
        cout << "No se pudo abrir archivo.\n";
        return;
    }
    while (!feof(C)) {
        fread(&cli, sizeof(cli), 1, C);
        if (!feof(C))
            if (cli.codigoC == codigo) {
                cout << "\nNombre: " << cli.nombreCliente << endl;
                cout << "Codigo: " << cli.codigoC << endl;
                cout << "DNI: " << cli.dni << endl;
                cout << "Genero: " << cli.genero << endl;
                cout << "Telefono: " << cli.telefono << endl;
                cout << "Correo: " << cli.correo << endl;
                cout << "--------------------------\n";
                encontrado = true;
                break;
            }
    }
    if (encontrado == false)
        cout << "Cliente no encontrado.\n";
    fclose(C);
}

void controladorClientes(FILE *C, Cliente cli) {
    int sub;
    do {
        sub = menuCliente();
        switch(sub) {
            case 1: crearArchivoCli(C); 
				break;
            case 2: ingresarCli(C, cli); 
				break;
            case 3: mostrarTodosCli(C, cli); 
				break;
            case 4: mostrarUnoCli(C, cli); 
				break;
            case 5: break;
            default: cout << "Opcion invalida.\n"; 
				break;
        }
    } while (sub != 5);
}

// Venta y Consultas
void crearArchivoVen(FILE *V) {
    V = fopen("Ventas.txt", "w");
    if (V == NULL) 
		cout << "No se pudo crear archivo de ventas.\n";
    else {
        cout << "Archivo de ventas creado con exito.\n";
        fclose(V);
    }
}

void realizarVenta(FILE *V, Venta ven) {    // VALIDAR EL CODIGO DE CLIENTE Y MEDICAMENTO SI NO SE ENCUENTRA REGISTRADO MOSTRARLO
    cout << "\nCodigo cliente: "; cin >> ven.codigoC;
    if (existeCodigoCliente(ven.codigoC) == false) {
        cout << "El codigo de cliente no está registrado.\n";
        return;
    }
    cout << "Codigo medicamento: "; cin >> ven.codigoM;
    if (existeCodigoMedicamento(ven.codigoM) == false) {
        cout << "El codigo de medicamento no esta registrado.\n";
        return;
    }
    cout << "Numero de boleta: "; cin >> ven.numeroBoleta;
    cout << "Fecha de emision (dd mm aaaa): \n";
	cout<<"Dia: "; cin >> ven.diaEmision;
	cout << "Mes: "; cin>> ven.mesEmision;
	cout << "Anio: "; cin>> ven.anioEmision;
    cout << "Cantidad vendida: "; cin >> ven.cantidadVendida;
    cout << "Precio x U: "; cin >> ven.precioxU;
    ven.costoT = ven.precioxU * ven.cantidadVendida;
    float pago;
    cout << "Pago del cliente: "; cin >> pago;
    ven.vuelto = pago - ven.costoT;
    cout<<"Vuelto: "<<ven.vuelto<<endl;
    V = fopen("Ventas.txt", "a");
    if (V != NULL) {
        fwrite(&ven, sizeof(ven), 1, V);
        fclose(V);
        cout << "Venta registrada con exito.\n";
    } else
        cout << "Error al abrir archivo.\n";
}

bool existeCodigoCliente(int codigo) {
    FILE *C = fopen("Clientes.txt", "r");
    if (C == NULL)
        return false;
    Cliente cli;
    while (!feof(C)) {
        fread(&cli, sizeof(cli), 1, C);
        if (!feof(C))
            if (cli.codigoC == codigo) {
                fclose(C);
                return true;
            }
    }
    fclose(C);
    return false;
}

bool existeCodigoMedicamento(int codigo) {
    FILE *M = fopen("Medicamentos.txt", "r");
    if (M == NULL)
        return false;
    Medicamento med;
    while (!feof(M)) {
        fread(&med, sizeof(med), 1, M);
        if (!feof(M))
            if (med.codigoDelMedicamento == codigo) {
                fclose(M);
                return true;
            }
    }
    fclose(M);
    return false;
}

void controladorVentas(FILE *V, Venta ven) {
    int sub;
    do {
        sub = menuVenta();
        switch(sub) {
            case 1: crearArchivoVen(V); 
				break;
            case 2: realizarVenta(V, ven); 
				break;
            case 3: 
				break;
            default: cout << "Opcion invalida.\n"; 
				break;
        }
    } while (sub != 3);
}

void controladorConsultas() {
    int sub;
    FILE *V, *M, *C;
    do {
        sub = menuConsultas();
        switch(sub) {
            case 1: reporteClientesRentables(V, C); 
				break;
            case 2: reporteMasVendidos(V, M); 
				break;
            case 3: 
				break;
            default: cout << "Opcion invalida.\n"; 
				break;
        }
    } while (sub != 3);
}

int cargarClientes(FILE* C, Cliente clientes[], int max) {
    int total = 0;
    while (!feof(C) && total < max) {
        if (fread(&clientes[total], sizeof(Cliente), 1, C) == 1)
            total++;
    }
    return total;
}

void procesarVentas(FILE* V, Cliente clientes[], int totalClientes, float totalGastado[], int numeroCompras[]) {
    Venta ven;
    while (!feof(V)) {
        if (fread(&ven, sizeof(Venta), 1, V) == 1) {
            for (int i = 0; i < totalClientes; i++) {
                if (clientes[i].codigoC == ven.codigoC) {
                    totalGastado[i] += ven.costoT;
                    numeroCompras[i]++;
                    break;
                }
            }
        }
    }
}

void inicializarVectores(float totalGastado[], int numeroCompras[], int tam) {
    for (int i = 0; i < tam; i++) {
        totalGastado[i] = 0;
        numeroCompras[i] = 0;
    }
}

void ordenarClientesPorGasto(Cliente clientes[], float totalGastado[], int numeroCompras[], int totalClientes) {
    for (int i = 0; i < totalClientes - 1; i++) {
        for (int j = i + 1; j < totalClientes; j++) {
            if (totalGastado[j] > totalGastado[i]) {
                // Intercambio del total Gastado
                float auxTotal = totalGastado[i];
                totalGastado[i] = totalGastado[j];
                totalGastado[j] = auxTotal;

                // Intercambio numero de Compras
                int auxNum = numeroCompras[i];
                numeroCompras[i] = numeroCompras[j];
                numeroCompras[j] = auxNum;

                // Intercambio de  clientes
                Cliente auxCli = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = auxCli;
            }
        }
    }
}

void mostrarClientesRentables(Cliente clientes[], float totalGastado[], int numeroCompras[], int totalClientes) {
    int limite;
    if (totalClientes < 5) 
        limite = totalClientes;
    else 
        limite = 5;
	cout << "\n--- CLIENTES MAS RENTABLES ---\n";
    for (int i = 0; i < limite; i++) {
        cout << (i + 1) << ". Codigo: " << clientes[i].codigoC;
        cout << " | Nombre: " << clientes[i].nombreCliente;
        cout << " | Compras: " << numeroCompras[i];
        cout << " | Total gastado: S/ " << totalGastado[i] << "\n";
    }
    cout << "--------------------------\n";
}

void reporteClientesRentables(FILE* V, FILE* C) {
    V = fopen("Ventas.txt", "r");
    C = fopen("Clientes.txt", "r");
    if (V == NULL || C == NULL) {
        cout << "No se pudieron abrir los archivos.\n";
        return;
    }
    Cliente clientes[1000];
    float totalGastado[1000];
    int numeroCompras[1000];
    inicializarVectores(totalGastado, numeroCompras, 1000);
    fseek(C, 0, SEEK_SET);
    int totalClientes = cargarClientes(C, clientes, 1000);
    fseek(V, 0, SEEK_SET);
    procesarVentas(V, clientes, totalClientes, totalGastado, numeroCompras);
    ordenarClientesPorGasto(clientes, totalGastado, numeroCompras, totalClientes);
    mostrarClientesRentables(clientes, totalGastado, numeroCompras, totalClientes);
    fclose(V);
    fclose(C);
}

int cargarMedicamentos(FILE* M, int codigos[], char nombres[][50], int max) {
    int total = 0;
    Medicamento med;
    fseek(M, 0, SEEK_SET);
    while (!feof(M) && total < max) {
        if (fread(&med, sizeof(Medicamento), 1, M) == 1) {
            codigos[total] = med.codigoDelMedicamento;
            int k = 0;
            while (med.nombreM[k] != '\0') {
                nombres[total][k] = med.nombreM[k];
                k++;
            }
            nombres[total][k] = '\0';
            total++;
        }
    }
    return total;
}

void inicializarContadores(int totalVendidas[], int tam) {
    for (int i = 0; i < tam; i++) {
        totalVendidas[i] = 0;
    }
}

void procesarVentas(FILE* V, int codigos[], char nombres[][50], int totalMeds, char nombresUnicos[][50], int totalVendidas[], int* totalNombres) {
    Venta ven;
    fseek(V, 0, SEEK_SET);
    while (!feof(V)) {
        if (fread(&ven, sizeof(Venta), 1, V) == 1) {
            int nombreEncontrado = 0;
            char nombreActual[50] = {'\0'};
            for (int i = 0; i < totalMeds && nombreEncontrado == 0; i++) {
                if (codigos[i] == ven.codigoM) {
                    int k = 0;
                    while (nombres[i][k] != '\0') {
                        nombreActual[k] = nombres[i][k];
                        k++;
                    }
                    nombreActual[k] = '\0';
                    nombreEncontrado = 1;
                }
            }
            if (nombreEncontrado == 1) {
                int posicion = -1;
                for (int i = 0; i < *totalNombres; i++) {
                    int iguales = 1;
                    int l = 0;
                    while (nombresUnicos[i][l] != '\0' || nombreActual[l] != '\0') {
                        if (nombresUnicos[i][l] != nombreActual[l])
                            iguales = 0;
                        l++;
                    }
                    if (iguales == 1 && posicion == -1)
                        posicion = i;
                }
                if (posicion == -1 && *totalNombres < 100) {
                    int m = 0;
                    while (nombreActual[m] != '\0') {
                        nombresUnicos[*totalNombres][m] = nombreActual[m];
                        m++;
                    }
                    nombresUnicos[*totalNombres][m] = '\0';
                    totalVendidas[*totalNombres] = ven.cantidadVendida;
                    (*totalNombres)++;
                } 
				else if (posicion != -1)
                    totalVendidas[posicion] += ven.cantidadVendida;
            }
        }
    }
}

void ordenarPorVentas(char nombresUnicos[][50], int totalVendidas[], int totalNombres) {
    for (int i = 0; i < totalNombres - 1; i++) {
        for (int j = i + 1; j < totalNombres; j++) {
            if (totalVendidas[j] > totalVendidas[i]) {
                // Intercambio ventas
                int aux = totalVendidas[i];
                totalVendidas[i] = totalVendidas[j];
                totalVendidas[j] = aux;

                // Intercambio de nombres
                char auxNombre[50];
                int t = 0;
                while (nombresUnicos[i][t] != '\0' || nombresUnicos[j][t] != '\0') {
                    auxNombre[t] = nombresUnicos[i][t];
                    nombresUnicos[i][t] = nombresUnicos[j][t];
                    nombresUnicos[j][t] = auxNombre[t];
                    t++;
                }
            }
        }
    }
}

void mostrarMasVendidos(char nombresUnicos[][50], int totalVendidas[], int totalNombres) {
    cout << "\n--- MEDICAMENTOS MAS VENDIDOS ---\n";
    int limite;
	if (totalNombres < 5) 
        limite = totalNombres;
    else 
        limite = 5;
    for (int i = 0; i < limite; i++) {
        cout << (i + 1) << ". " << nombresUnicos[i]
             << " - Unidades vendidas: " << totalVendidas[i] << "\n";
    }
    cout << "--------------------------\n";
}

void reporteMasVendidos(FILE* V, FILE* M) {
    V = fopen("Ventas.txt", "r");
    M = fopen("Medicamentos.txt", "r");
    if (V == NULL || M == NULL) {
        cout << "No se pudieron abrir los archivos.\n";
        return;
    }
    int codigos[1000];
    char nombres[1000][50];
    char nombresUnicos[100][50];
    int totalVendidas[100];
    int totalMeds, totalNombres = 0;
    totalMeds = cargarMedicamentos(M, codigos, nombres, 1000);
    fclose(M);
    inicializarContadores(totalVendidas, 100);
    procesarVentas(V, codigos, nombres, totalMeds, nombresUnicos, totalVendidas, &totalNombres);
    fclose(V);
    ordenarPorVentas(nombresUnicos, totalVendidas, totalNombres);
    mostrarMasVendidos(nombresUnicos, totalVendidas, totalNombres);
}

bool confirmarSalir() {
    char confirm;
    cout << "Esta seguro que desea salir del programa? (S/N): ";
    cin >> confirm;
    if (confirm == 'S' || confirm == 's')
        return true;  
    else 
        return false;
}

void salir() {
    cout << "Gracias por usar el sistema de BOTICA.\n";
}
