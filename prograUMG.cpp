#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>
using namespace std;

/*
 * Programa que INSERTE, LEE, ACTUALICE Y ELIMINE DATOS de un GYM
 * DETALLAR LOS DATOS Y FECHAS DE PAGO DE CLIENTES
 *
 */

FILE *pArchivo;
FILE *pTemporal;

struct clienteGym
{
    int precio;
    int codigo;
    char nombre[30];
    int edad;
    char direccion[30];
    int fecha[3];
}dtCliente;



void guardarCliente()
{

    cout<<"---------------------------------------------------------------"<<endl;
    fflush(stdin);
    cout<<"Ingresar nombre: ";
    gets(dtCliente.nombre);
    cout<<"Ingrese una edad: ";
    cin>>dtCliente.edad;
    fflush(stdin);
    cout<<"Ingrese su direccion: ";
    gets(dtCliente.direccion);
    cout<<"Ingresar fecha (dd/mm/yyyy)"<<endl;
    for (int i = 0; i < 3; ++i) {
        cout<<"Dia: ";
        cin>>dtCliente.fecha[i];
        i++;
        if(i>0){
            cout<<"mes: ";
            cin>>dtCliente.fecha[i];
            i++;
            if (i>1){
                cout<<"anio: ";
                cin>>dtCliente.fecha[i];
            }
        }
    }

    cout<<"Precio a pagar: Q";
    cin>>dtCliente.precio;

    srand(time(NULL));

    for (int num = 0; num < 1; ++num) {

        dtCliente.codigo = rand();
        cout<<"Codigo del cliente: "<<dtCliente.codigo;
    }



    pArchivo = fopen("C:\\Ejemplo Archivos\\CLIENTES.txt", "a+");
    fwrite(&dtCliente, sizeof(dtCliente), 1, pArchivo);
    fclose(pArchivo);
    getch(); // pausa
    cout<<"Cliente Guardado en el Sistema!"<<endl;
}

void mostrarCliente()
{
    pArchivo = fopen("C:\\Ejemplo Archivos\\CLIENTES.txt", "r+");

    while(fread(&dtCliente, sizeof(dtCliente), 1, pArchivo))
    {
        cout<<"---------------------------------------------------------------"<<endl;
        cout<<"Nombre :"<<dtCliente.nombre<<"\nEdad :"<<dtCliente.edad;
        cout<<"\nDireccion: "<<dtCliente.direccion;
        cout<<"\nCodigo de cliente: "<<dtCliente.codigo;
        cout<<"\nFecha de ingreso: "<<dtCliente.fecha[0]<<"/"<<dtCliente.fecha[1]<<"/"<<dtCliente.fecha[2];
        cout<<"\nTotal pago: Q"<<dtCliente.precio<<endl;
        cout<<"---------------------------------------------------------------"<<endl;
    }
    fclose(pArchivo);
    getch(); // pausa
}


void editarCliente()
{
    int matri;

    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"Ingrese codigo de cliente para editar: ";
    cin>>matri;

    pArchivo = fopen("C:\\Ejemplo Archivos\\CLIENTES.txt", "r+");
    pTemporal = fopen("C:\\Ejemplo Archivos\\TEMPORAL.txt", "a+");

    while(fread(&dtCliente, sizeof(dtCliente), 1, pArchivo))
    {
        if(matri == dtCliente.codigo)
        {
            cout<<"Ingrese un nuevo nombre: ";
            fflush(stdin);
            gets(dtCliente.nombre);
            cout<<"Ingrese una nueva edad: ";
            cin>>dtCliente.edad;
            cout<<"Ingrese una nueva direccion: ";
            cin>>dtCliente.direccion;
            cout<<"Ingrese un nuevo pago: Q";
            cin>>dtCliente.precio;

            fwrite(&dtCliente, sizeof(dtCliente), 1, pTemporal);
        }
        else
        {
            fwrite(&dtCliente, sizeof(dtCliente), 1, pTemporal);
        }
    }
    fclose(pArchivo);
    fclose(pTemporal);

    remove("C:\\Ejemplo Archivos\\CLIENTES.txt");
    rename("C:\\Ejemplo Archivos\\TEMPORAL.txt", "C:\\Ejemplo Archivos\\CLIENTES.txt" );

    cout<<"Datos de cliente actualizado!";
    getch();

}

void eliminarCliente()
{
    int matri;

    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"Ingrese codigo de cliente para eliminar: ";
    cin>>matri;

    pArchivo = fopen("C:\\Ejemplo Archivos\\CLIENTES.txt", "r+");
    pTemporal = fopen("C:\\Ejemplo Archivos\\TEMPORAL.txt", "a+");

    while(fread(&dtCliente, sizeof(dtCliente), 1, pArchivo))
    {
        if(matri == dtCliente.codigo)
        {

        }
        else
        {
            fwrite(&dtCliente, sizeof(dtCliente), 1, pTemporal);
        }
    }
    fclose(pArchivo);
    fclose(pTemporal);

    remove("C:\\Ejemplo Archivos\\CLIENTES.txt");
    rename("C:\\Ejemplo Archivos\\TEMPORAL.txt", "C:\\Ejemplo Archivos\\CLIENTES.txt" );

    cout<<"Cliente eliminado del sistema!";
    getch();
}

int main()
{
    setlocale(LC_ALL, "Spanish");
    int opc;



    do
    {

        system("cls");//clean screen
        cout<<"---------------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"                          GIMNASIO (nombre)   "<<endl;
        cout<<endl;
        cout<<"---------------------------------------------------------------"<<endl;

        cout<<" CONTROL DE CLIENTES "<<endl;
        cout<<"---------------------------------------------------------------"<<endl;
        cout<<"\n1. Guardar cliente en el sistema";
        cout<<"\n2. Mostrar clientes";
        cout<<"\n3. Actualizar datos de clientes";
        cout<<"\n4. Eliminar clientes del sistema";
        cout<<"\n5. Salir";
        cout<<"\nQue desea hacer?: ";
        cin>>opc;

        switch(opc)
        {
            case 1:
                guardarCliente();
                break;

            case 2:
                mostrarCliente();
                break;

            case 3:
                editarCliente();
                break;

            case 4:
                eliminarCliente();
                break;

            case 5:
                cout<<"Gracias por utilizar este programa";
                break;
            default:
                cout<<"Opcion invalida!!"<<endl;
        }
    }while(opc != 5);
}
