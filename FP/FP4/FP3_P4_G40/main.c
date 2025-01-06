/********************************************************
Programa:           registro.c
Tarea que realiza:  Un programa que almacena los datos de
                    libros prestados y de los usuarios, despu�s
                    muestra un men� de opciones.
Autores:            Daniel Atanasov y Raul Sanz
Fecha:              03/01/2025
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Ponemos valores m�ximos para la cantidad de libros y usuarios
#define MAX_LIBROS 15
#define MAX_USUARIOS 10

//Declaramos los registros y el array bidimensional
typedef struct{
    char titulo[50];
    char autor[50];
    int anio;
}Libro;

typedef struct{
    char nombre[50];
    int num;
    char dir[50];
}Usuario;

int prestamos[MAX_USUARIOS][MAX_LIBROS];

//Declaramos subprogramas
void registrarLibros(Libro libros[], int *numLibros);
void registrarUsuarios(Usuario usuarios[], int *numUsuarios);
void registrarPrestamos(Libro libros[], Usuario usuarios[], int prestamos[MAX_USUARIOS][MAX_LIBROS], int numLibros, int numUsuarios);
void Libros(Libro libros[], int numLibros);
void mostrarUsuarios(Usuario usuarios[], int numUsuarios);
void infPrestamos(Usuario usuarios[], Libro libros[], int prestamos[MAX_USUARIOS][MAX_LIBROS], int numUsuarios, int numLibros);
void masPrestado();
void totalPrestamos();
void anoPublicacion();
void menosPrestamos();

int main()
{
    Libro libros[MAX_LIBROS];
    Usuario usuarios[MAX_USUARIOS];
    int prestamos[MAX_USUARIOS][MAX_LIBROS] = {0};
    int numLibros, numUsuarios;
    int opc;

    setlocale(LC_ALL, "spanish");

    registrarLibros(libros, &numLibros);
    registrarUsuarios(usuarios, &numUsuarios);
    registrarPrestamos(libros, usuarios, prestamos, numLibros, numUsuarios);


    //Despu�s de registrar todos los libros, usuarios y pr�stamos muestra el men�
    do{
        printf("\n********************************************\n");
        printf("\t.- MEN�\n");
        printf("********************************************\n");
        printf("\n\t1. Listado de libros");
        printf("\n\t2. Listado de usuarios");
        printf("\n\t3. Informe de pr�stamos");
        printf("\n\t4. Libro m�s prestado");
        printf("\n\t5. Total de pr�stamos por usuario");
        printf("\n\t6. A�o de publicaci�n de un libro");
        printf("\n\t7. Usuarios con menos pr�stamos");
        printf("\n\t0. Finalizar programa\n");

        fflush(stdin);
        printf("\n\tSelecciona una opci�n: ");
        scanf("%d", &opc);

        system("pause");
        system("cls");

        switch (opc){
            case 1:
                Libros(libros, numLibros);
                break;
            case 2:
                mostrarUsuarios(usuarios, numUsuarios);
                break;
            case 3:
                infPrestamos(usuarios, libros, prestamos, numUsuarios, numLibros);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 0:
                printf("\n\tGracias por usar nuestro programa\n");
                break;
        }

    }while(opc != 0);
}

/*********************************************************************************
Subprograma:        registrarLibros
Tarea:              Pide los datos de los libros
                    y los guarda en el registro.
Par�metros de S/:   titulo, autor (cadenas de caracteres) y a�o, numero de libros(enteros)
*********************************************************************************/
void registrarLibros(Libro libros[], int *numLibros){
    //Muestra una cabezera
    printf("\n*****************************************************************\n");
    printf("\t.- REGISTRO DE LIBROS\n");
    printf("*******************************************************************\n");

    //Pide la cantidad de libros
    printf("\t�Cu�ntos libros desea ingresar (m�ximo %d)? ", MAX_LIBROS);
    scanf("%d", numLibros);
    while (*numLibros < 1 || *numLibros > MAX_LIBROS) {
        printf("\n\tN�mero inv�lido. Ingrese un valor entre 1 y %d: ", MAX_LIBROS);
        scanf("%d", numLibros);
    }

    //Pide los datos de los libros
    for (int i = 0; i < *numLibros; i++) {
        fflush(stdin);
        printf("\n\tLibro %d:\n", i + 1);
        printf("\tT�tulo: ");
        fgets(libros[i].titulo, sizeof(libros[i].titulo), stdin);
        strtok(libros[i].titulo, "\n"); // Eliminar salto de l�nea
        printf("\tAutor: ");
        fgets(libros[i].autor, sizeof(libros[i].autor), stdin);
        strtok(libros[i].autor, "\n");
        printf("\tA�o: ");
        scanf("%d", &libros[i].anio);
    }

    printf("\n");
    system("pause");
    system("cls");
}

/**********************************************************************************************
Subprograma:        registrarUsuarios
Tarea:              Pide los datos de los usuarios
                    y los guarda en el registro.
Par�metros de S/:   nombre, direcci�n (cadenas de caracteres) y n�mero de carnet, numero de usuarios(enteros)
**********************************************************************************************/
void registrarUsuarios(Usuario usuarios[], int *numUsuarios){
    //Muestra una cabezera
    printf("\n********************************************\n");
    printf("\t.- REGISTRO DE USUARIOS\n");
    printf("********************************************\n");

    //Pide la cantidad de usuarios
    printf("�Cu�ntos usuarios desea ingresar (m�ximo %d)? ", MAX_USUARIOS);
    scanf("%d", numUsuarios);
    while (*numUsuarios < 1 || *numUsuarios > MAX_USUARIOS) {
        printf("N�mero inv�lido. Ingrese un valor entre 1 y %d: ", MAX_USUARIOS);
        scanf("%d", numUsuarios);
    }

    fflush(stdin);

    //Pide los datos de los usuarios
    for (int i = 0; i < *numUsuarios; i++) {
        printf("\n\tUsuario %d:\n", i + 1);
        printf("\tNombre: ");
        fgets(usuarios[i].nombre, sizeof(usuarios[i].nombre), stdin);
        strtok(usuarios[i].nombre, "\n"); // Eliminar salto de l�nea
        printf("\tCarnet: ");
        scanf("%d", &usuarios[i].num);
        fflush(stdin);
        printf("\tDirecci�n: ");
        fgets(usuarios[i].dir, sizeof(usuarios[i].dir), stdin);
        strtok(usuarios[i].dir, "\n");
    }

    printf("\n");
    system("pause");
    system("cls");
}

/****************************************************
Subprograma:        registrarPr�stamos
Tarea:              Muestra los libros que hay en el registro
                    y guarda la cantidad de veces que cada usuario
                    ha cogido prestado cada uno.
Par�metros de S/:   libros prestados por usuario (array bidimensional de enteros)
*****************************************************/
void registrarPrestamos(Libro libros[], Usuario usuarios[], int prestamos[MAX_USUARIOS][MAX_LIBROS], int numLibros, int numUsuarios) {
    //Muestra una cabezera
    printf("\n********************************************\n");
    printf("\t.- REGISTRO DE PR�STAMOS\n");
    printf("********************************************\n");

    //Para cada usuario, pide los libros prestados
    for (int i = 0; i < numUsuarios; i++){
        printf("\n\tUsuario/a: %d.- %s\n", i + 1, usuarios[i].nombre);
        printf("\n\tPor favor, introduzca el n�mero de veces que ha cogido cada libro: \n");
        printf("\n\t| Libro\t\t\t| Veces prestado|\n");
        printf("\t--------------------------------------------------\n");
        for (int j = 0; j < numLibros; j++){
            printf("\t|%-15s\t|", libros[j].titulo);
            scanf("%d", &prestamos[i][j]);
        }
        printf("\n**Pr�stamos del usuario %d registrados**\n", i + 1);
        printf("Pulse <Intro> para continuar...\n");
    }

    system("pause");
    system("cls");
}

/****************************************************
Subprograma:        listadoLibros
Tarea:              Muestra los libros que hay en el registro
Par�metros de E/:   titulo, autor (cadenas de caracteres) y a�o, numero de libros(enteros)
*****************************************************/
void Libros(Libro libros[], int numLibros){
    //Muestra una cabezera
    printf("\n********************************************\n");
    printf("\t1.- Listado de libros\n");
    printf("********************************************\n");

    //Muestra los libros a modo de tabla
    printf("\n\t|T�tulo\t\t|A�o de publicaci�n\t|Autor\t\t\t|\n");
    printf("\t-----------------------------------------------------------------\n");
    for(int i = 0; i < numLibros; i++){
        printf("\t|%-10s\t|%d\t\t\t|%-20s\t|\n", libros[i].titulo, libros[i].anio, libros[i].autor);
    }

    printf("\n");
    system("pause");
    system("cls");
}

/****************************************************
Subprograma:        listadoUsuarios
Tarea:              Muestra los usuarios que hay en el registro
Par�metros de E/:   nombre, direcci�n (cadenas de caracteres) y n�mero de carnet, numero de usuarios(enteros)
*****************************************************/
void mostrarUsuarios(Usuario usuarios[], int numUsuarios){
    //Muestra una cabezera
    printf("\n********************************************\n");
    printf("\t2.- Listado de usuarios\n");
    printf("********************************************\n");

    //Muestra los usuarios a modo de tabla
    printf("\n\t|Nombre\t\t|N�mero de Carnet\t|Direcci�n\t\t|\n");
    printf("\t-----------------------------------------------------------------\n");
    for(int i = 0; i < numUsuarios; i++){
        printf("\t|%-10s\t|%d\t\t\t|%-20s\t|\n", usuarios[i].nombre, usuarios[i].num, usuarios[i].dir);
    }

    printf("\n");
    system("pause");
    system("cls");
}

/**************************************************************************************
Subprograma:        informePrestamos
Tarea:              Muestra un informe con los pr�stamos realizados por cada usuario
Par�metros de E/:   nombre, direcci�n (cadenas de caracteres) y n�mero de carnet, numero de usuarios(enteros)
**************************************************************************************/
void infPrestamos(Usuario usuarios[], Libro libros[], int prestamos[MAX_USUARIOS][MAX_LIBROS], int numUsuarios, int numLibros){
    //Muestra una cabezera
    printf("\n********************************************\n");
    printf("\t3.- Informe de Pr�stamos\n");
    printf("********************************************\n");

    //Muestra los pr�stamos a modo de tabla
    printf("\n\t|Usuario/a\t\t|Libros prestados\t\t|Pr�stamos (por libro)\t|\n");
    printf("\t|-----------------------|-------------------------------|-----------------------|\n");
    for(int i = 0; i < numUsuarios; i++){
        printf("\t|%-10s\t\t|", usuarios[i].nombre);
        int contador = 0;
        int total = 0;
        for(int j = 0; j < numLibros; j++){
            if (prestamos[i][j] && contador == 0){
                printf("%-10s\t\t\t|%d\t\t\t|\n", libros[j].titulo, prestamos[i][j]);
                contador = contador + 1;
                total = total + prestamos[i][j];
            } else if(prestamos[i][j] && contador != 0){
                printf("\t|\t\t\t|%-10s\t\t\t|%d\t\t\t|\n", libros[j].titulo, prestamos[i][j]);
                contador = contador + 1;
                total = total + prestamos[i][j];
            }
        }
        printf("\t|                       |                               |                       |\n");
        printf("\t|\t\t\t|Total Pr�stamos:\t\t|%d\t\t\t|\n", total);
        printf("\t|-----------------------|-------------------------------|-----------------------|\n");
    }

    printf("\n");
    system("pause");
    system("cls");
}




