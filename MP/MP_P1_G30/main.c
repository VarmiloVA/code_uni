/*  Asigantura: Metodolog�a de la programaci�n Curso: 1
    Tarea que realiza el programa: Gesti�n de clientes, habitaciones y reservas de un hotel
    Alumno 1: Atanasov Angelov, Daniel
    Alumno 2: Sanz Tom�, Ra�l
    Grupo de laboratorio: 30
    Fecha: 24/02/2025 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu_princ();
void gest_clientes();

int main()
{
    setlocale(LC_ALL, "spanish");
    printf("�Bienvenido a la aplicaci�n GEST_HOTEL!\n");
    system("pause");
    system("cls");
    menu_princ();
    return 0;
}

/********************************************************************************/
/*Subprograma:              Men� principal                                      */
/*Tipo:                     Procedimiento (funci�n tipo void)                   */
/*Par�metros de entrada:    ---                                                 */
/*Par�metros de salida:     ---                                                 */
/*Prerrequisitos:           ---                                                 */
/*Objetivo:                 Muestra por pantalla el men� principal del programa */
/********************************************************************************/
void menu_princ(){
    int opc;
    do{
        printf("\tMEN� PRINCIPAL\n");
        printf("-----------------------------");
        printf("\n\t1.- Gesti�n de Clientes");
        printf("\n\t2.- Gesti�n de Habitaciones");
        printf("\n\t3.- Gesti�n de Reservas");
        printf("\n\t4.- Informes Econ�micos");
        printf("\n\t5.- Importar Habitaciones desde Fichero");
        printf("\n\t0.- Salir\n");

        printf("\nSelecciona una opci�n: ");
        scanf("%d", &opc);

        system("pause");
        system("cls");

        switch(opc){
            case 1:
                gest_clientes();
                break;
            case 2:
                printf("\n\tHabitaciones\n\n");
                system("pause");
                system("cls");
                break;
            case 3:
                printf("\n\tReservas\n\n");
                system("pause");
                system("cls");
                break;
            case 4:
                printf("\n\tInformes\n\n");
                system("pause");
                system("cls");
                break;
            case 5:
                printf("\n\tImportar\n\n");
                system("pause");
                system("cls");
                break;
            case 0:
                printf("\n\tGracias por usar nuestro programa\n\n");
                printf("-------------------------");
                break;
        }
    }while(opc != 0);
}

/********************************************************************************************/
/*Subprograma:              Gesti�n clientes                                                */
/*Tipo:                     Procedimiento (funci�n tipo void)                               */
/*Par�metros de entrada:    ---                                                             */
/*Par�metros de salida:     ---                                                             */
/*Prerrequisitos:           ---                                                             */
/*Objetivo:                 Se encarga de todas las opciones relacionadas con los clientes  */
/********************************************************************************************/
void gest_clientes(){
    void submenu();

    submenu();

    system("pause");
    system("cls");
}

void submenu(){
    int opc;
    do{
        printf("\GESTI�N DE CLIENTES\n");
        printf("-----------------------------");
        printf("\n\t1.- Alta");
        printf("\n\t2.- Baja");
        printf("\n\t3.- Modificaci�n");
        printf("\n\t4.- Consulta");
        printf("\n\t5.- Listado General");
        printf("\n\t6.- Listado por Categor�a");
        printf("\n\t0.- Salir\n");

        printf("\nSelecciona una opci�n: ");
        scanf("%d", &opc);

        system("pause");
        system("cls");

        switch(opc){
            case 1:
                printf("\n\tAltas\n\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("\n\tBajas\n\n");
                system("pause");
                system("cls");
                break;
            case 3:
                printf("\n\tModificaci�n\n\n");
                system("pause");
                system("cls");
                break;
            case 4:
                printf("\n\tConsulta\n\n");
                system("pause");
                system("cls");
                break;
            case 5:
                printf("\n\Listado\n\n");
                system("pause");
                system("cls");
                break;
            case 6:
                printf("\n\tListado-categoria\n\n");
                system("pause");
                system("cls");
                break;
            case 0:
                break;
        }
    }while(opc != 0);
}
