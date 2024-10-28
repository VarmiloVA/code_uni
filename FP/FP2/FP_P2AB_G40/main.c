#include <stdio.h>
#include <locale.h>

int main(){
    int x, y;
    int suma, resta, producto; //almacenan los resultados de los c�lculos
    int i, sumaTotal;

    setlocale(LC_ALL, "spanish");

    //Pedimos los n�meros al usuario
    printf("\n\t\t PETICI�N DE DATOS ");
    printf("\n\t\t ================== \n\n");
    printf("\n\t\t Introduzca dos n�meros enteros: ");
    scanf("%d %d", &x, &y);

    //Realizamos c�lculos
    suma = x + y;
    resta = x / y;
    producto = x * y;

    //Suma los primeros x n�meros enteros
    sumaTotal = 0;
    for (i = 1; i<= x; i++)
        sumaTotal = sumaTotal + 1;

    //Mostramos resultados en pantalla
    printf("\n\t\t RESULTADOS ");
    printf("\n\t\t =========== ");

    printf("\n\t\t La suma es %d", suma);
    printf("\n\t\t La resta es %d", resta);
    printf("\n\t\t El producto es %d", producto);
    printf("\n\t\t La suma de los %d primeros n�meros naturales es: %d", x, sumaTotal);

    printf("\n\n\t\t Pulse <Intro> para finalizar... \n\n");
    getchar();
}
