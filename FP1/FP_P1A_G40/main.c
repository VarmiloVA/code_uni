#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("cls");
    //Declaramos las variables
    char nombre[40], tipo[30];
    int edad;
    float peso;

    //Solicitamos al usuario los datos de su mascota
    printf("Introduce el nombre de tu mascota: ");
    fgets(nombre, sizeof(nombre), stdin);

    printf("Introduce el tipo de mascota (perro, gato, pajaro...): ");
    fgets(tipo, sizeof(tipo), stdin);

    printf("introduce la edad de tu mascota: ");
    scanf("%d", &edad);

    printf("Introduce el peso de tu mascota: ");
    scanf("%f", &peso);

    //Elabora la ficha de la mascota
    printf("\n\tFICHA DE TU MASCOTA\n");
    printf("Nombre:\t %s", nombre);
    printf("Tipo:\t %s", tipo);
    printf("Edad:\t %d a�os\n", edad);
    printf("Peso:\t %.2f kg\n", peso);

    //Para la frase necesito quitar el salto de l�nea de la variable tipo
    tipo[strcspn(tipo, "\n")] = '\0';

    //Frase seg�n el tipo de mascota
    if (strcmp(tipo, "Perro")== 0){
        printf("Tu perro es muy alegre\n");
    } else if (strcmp(tipo, "Gato") == 0){
        printf("Tu gato es un dormil�n\n");
    } else if (strcmp(tipo, "Pajaro") == 0){
        printf("A tu pajaro le gusta cantar\n");
    } else if (strcmp(tipo, "Tortuga") == 0){
        printf("Tu tortuga es muy tranquila\n");
    } else{
        printf("Tu mascota es muy original\n");
    }

    printf("Pulse <Intro> para continuar...");
    return 0;
}
