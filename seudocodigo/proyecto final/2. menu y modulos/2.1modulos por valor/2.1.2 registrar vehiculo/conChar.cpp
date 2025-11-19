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
        cout<<"***********************************"<<endl;
        cout<<"GESTION DE VENTAS DE AUTOMOVILES"<<endl;
        cout<<"1. VEHICULO"<<endl;
        cout<<"2. CLIENTE"<<endl;
        cout<<"3. VENTA"<<endl;
        cout<<"4. CONSULTAS"<<endl;
        cout<<"5. SALIR"<<endl;
        cout<<"***********************************"<<endl;
        cout<<"Seleccione una opcion: ";
        cin >> opcion;

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
        cin.ignore();

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
                cout<<"MOSTRAR UNO"<<endl;
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




//ARCHIVO VEHICULO

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



/*
    *FORMA 1
        char temp[2];
        cout <<"Ingreso de nuevo auto \n";
        cout<<"Digite datos del auto \n";
        *gets(temp);
        
        cout<<"Codigo del vehiculo: "; cin>>veh.codigoVehiculo;
        cout<<"Numero de chasis: "; gets(veh.numChasis);
        cout<<"Numero de motor: "; gets(veh.numMotor);

    Yo vengo de menuVehiculo -> registrarVehiculo.
    En menuVehiculo presioné la opción 2. y puse enter, pero deja el ENTER en
    el bufer (es un espacio de memoria temporal usado para almacenar datos 
    mientras se transfieren de un lugar a otro).
    Entonces, cuando entras al módulo de registrarVehiculo, el gets(temp) lo que 
    hace es limpiar ese ENTER (lo come), y despues el bufer ya queda limpio y no
    con un ENTER. O sea, consume el ENTER que quedó en el menu y como el ENTER
    es una linea vacía, entonces gets(temp) lo interpreta como:
        - esta línea está vacía
        - y escribe en temp -> "" (cadena vacía)
    Menu Vehiculo 1. 
    Crear archivo vehiculo 2. 
    Registrar Vehiculo 3. 
    Mostrar vehiculos registrados (todos) 
    4. Mostrar un vehiculo registrado 5. 
    Retornar menu principal 
    ******************************************* S
    eleccione una opcion: 2 
    Ingreso de nuevo auto 
    Digite datos del auto 
    ![ACA HAY UN ESPACIO DONDE ME PERMITE ESCRIBIR CUALQUIER COSA] 
    !ese espacio donde tu escribes es el gets(temp) comiendose lo que tú escribas
    !despues de que gets(temp) se come lo que tú escribiste, recién llega: codVeh
    Codigo del vehiculo: 123
    ?cin>>veh.codigoVehiculo deja otro ENTER en el bufer, por eso gets(chasis) ve
    ?ese ENTER, lo toma como cadena vacía y no te deja escribir como quieres. 
    Numero de chasis: Numero de motor:     LITERALMENTE TODO JUNTO, porque 
    gets(veh.numChasis) se tragó la línea vacía, no te deja escribir nada e 
    inmediatamente se ejecutó el siguiente cout que aparece pegado. 
    El cursor recién aparece despues de "Numero de motor" porque ese 
    gets(veh.numMotor) ya espera texto real. 

    TODO: Ojo, ese problema tambien me va a aparecer en:  
    TODO: cout<<"Anio de fabricacion: "; cin>>veh.anioFabricacion;
    TODO: cout<<"Color: "; gets(veh.color);
    TODO: cout<<"Tipo de combustible: "; gets(veh.tipoCombustible);


    *FORMA 2
        char temp[2];
        cout <<"Ingreso de nuevo auto \n";
        cout<<"Digite datos del auto \n";
        
        cout<<"Codigo del vehiculo: "; cin>>veh.codigoVehiculo;
        gets(temp);
        cout<<"Numero de chasis: "; gets(veh.numChasis);
        cout<<"Numero de motor: "; gets(veh.numMotor);
    
    Yo vengo de menuVehiculo -> registrarVehiculo.
    En menuVehiculo presioné la opción 2. y puse enter, pero deja el ENTER en
    el bufer (es un espacio de memoria temporal usado para almacenar datos 
    mientras se transfieren de un lugar a otro).
    Entonces, cuando entras al módulo de registrarVehiculo, inmediatamente entra
    a un cin>> primero, ese cin>> ignora automáticamente ese ENTER del menú.
    Por eso no ves un espacio raro para escribir antes del código, a dif. del 1.

    Entonces, lo primero que pasa cuando entro al módulo es que me pide:
    Codigo del vehiculo: 
    !El cursos está directamente después del texto. No aparece ese espacio donde
    !podía escribir "cualquier cosa" como en la FORMA 1
    Ahora escribo -> Codigo del vehiculo: 123...Presiono ENTER
    
    El gets(temp) se come el ENTER que dejó el cin, interpreta que la línea está 
    vacía, guarda "" en temp y limpia el buffer para que el siguiente gets() 
    funcione normal.
    Despues de ese gets(temp) ya viene el...
    Numero de chasis: 
    Y ahora sí me deja escribir de forma normal.


    TODO: Hasta llegar a..
    TODO: cout<<"Marca: "; gets(veh.marca);
    TODO: cout<<"Modelo: "; gets(veh.modelo);
    TODO: cout<<"Anio de fabricacion: "; cin>>veh.anioFabricacion;
    ? gets(temp); DEBO PONERLO
    TODO: cout<<"Color: "; gets(veh.color);
    TODO: cout<<"Tipo de combustible: "; gets(veh.tipoCombustible);

 */



void registrarVehiculo(FILE* V, Vehiculo veh) {

    char temp[2];
    cout <<"Ingreso de nuevo auto \n";
    cout<<"Digite datos del auto \n";
    
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
        if(!ferror(V))
            fclose(V);
        else
            cout << "Error al escribir en Autos.txt\n";
    }
    else {
        cout << "No se pudo abrir Autos.txt\n";
    }
}
