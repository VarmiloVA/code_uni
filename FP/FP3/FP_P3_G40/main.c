/********************************************************
Programa:           subprogramas.c
Tarea que realiza:  Un menu principal que da acceso a
                    programas que a su vez contienen a
                    otros programas.
Autores:            Daniel Atanasov y Raul Sanz
Fecha:              13/11/2024
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void triangulo();
void pascal();
void caracteres();
void arrays();

int main(){

    int opt;
    setlocale(LC_ALL, "spanish");

    do {
        printf("--------------------------------------------------------------------------\n");
        printf("\n\t\tMEN� PRINCIPAL\n");
        printf("\n--------------------------------------------------------------------------\n");
        printf("\n\t1. C�lculos sobre un tri�ngulo\n");
        printf("\n\t2. Dibujar tri�ngulo de Pascal\n");
        printf("\n\t3. Procesar cadena de caracteres\n");
        printf("\n\t4. Procesar arrays de n�meros enteros\n");
        printf("\n\t0. Salir\n");


        do{
            printf("\n\n\tSeleccione una opci�n: ");
            scanf("%d", &opt);
        }while (opt <0 || opt >4);

        system("pause");
        system("cls");

        switch(opt){
            case 1:
                triangulo();
                break;
            case 2:
                pascal();
                break;
            case 3:
                caracteres();
                break;
            case 4:
                arrays();
                break;
            case 0:
                printf("\n\tSaliendo del programa...\n");
                break;
        }
    } while (opt != 0);

    return 0;
}

// SUBPROGRAMA TRI�NGULO
void triangulo() {
    //Definimos los subprogramas de esta opci�n
    void leerCateto(int *c1, int *c2);
    void calcularHipotenusa(int c1, int c2, float *h);
    void calcularArea(int c1, int c2, float *A);
    void calcularPerimetro(int c1, int c2, float h, int *P);
    void mostrarResultado(int c1, int c2, float h, float A, int P);

    //Muestra el men� del subprograma
    printf("--------------------------------------------------------------------------\n");
    printf("\n\t\tC�LCULOS SOBRE UN TRIANGULO\n");
    printf("\n--------------------------------------------------------------------------\n");

    //Definimos variables y llamamos a los subprogramas
    int c1, c2, P;
    float A, h;
    leerCateto(&c1, &c2);
    calcularHipotenusa(c1, c2, &h);
    calcularArea(c1, c2, &A);
    calcularPerimetro(c1, c2, h, &P);
    mostrarResultado(c1, c2, h, A, P);

    system("pause");
    system("cls");
}

//SUBPROGRAMAS DEL TRI�NGULO
/****************************************************
Subprograma:        leerCateto
Tarea:              Pide un n�mero que ser� el valor
                    del cateto.
Par�metros de S/:   c1 (entero) y c2(entero)
*****************************************************/
void leerCateto(int *c1, int *c2){
    do{
        printf("\n\tIntroduce el valor del primer cateto: ");
        scanf("%d", c1);
    }while(c1<=0);
    do{
        printf("\n\tIntroduce el valor del segundo cateto: ");
        scanf("%d", c2);
    }while(c2<=0);
}

/*****************************************************
Subprograma:        calcularHipotenusa
Tarea:              Calcula y devuelve el valor de la
                    hipotenusa del triangulo
Par�metros de E/:   c1 (entero) y c2(entero)
Par�metros de S/:   h(real)
*****************************************************/
void calcularHipotenusa(int c1, int c2, float *h){
    *h = sqrt((c1*c1)+(c2*c2));
}

/*****************************************************
Subprograma:        calcularArea
Tarea:              Calcula y devuelve el valor del �rea
                    del triangulo
Par�metros de E/:   c1 (entero) y c2(entero)
Par�metros de S/:   A(real)
*****************************************************/
void calcularArea(int c1, int c2, float *A){
    *A = (c1*c2)/2;
}

/*****************************************************
Subprograma:        calcularPerimetro
Tarea:              Calcula y devuelve el valor del
                    per�metro del triangulo
Par�metros de E/:   c1 (entero), c2(entero) y h(real)
Par�metros de S/:   P(entero)
*****************************************************/
void calcularPerimetro(int c1, int c2, float h, int *P){
    *P = h + c1 + c2;
}

/*****************************************************
Subprograma:        mostrarResultados
Tarea:              Obtiene los datos de los otros subprogramas
                    y los muestra por pantalla
Par�metros de E/:   c1 (entero), c2(entero), h(real),
                    A(real) y P(entero)
*****************************************************/
void mostrarResultado(int c1, int c2, float h, float A, int P){
    printf("\n\n\tEl valor de los catetos es: %d y %d.\n", c1, c2);
    printf("\n\tEl valor de la hipotenusa es: %.2f.\n", h);
    printf("\n\tEl �rea del tri�ngulo es: %.2f.\n", A);
    printf("\n\tEl per�metro del tri�ngulo es de: %d.\n\n", P);
}

// SUBPROGRAMA TRI�NGULO DE PASCAL
void pascal() {
    //Declaramos los subprogramas
    void pedirNumero(int *filas);
    void dibujarTrianguloPascal(int filas);

    //Muestra el men� del subprograma
    printf("--------------------------------------------------------------------------\n");
    printf("\n\t\tDIBUJAR TRI�NGULO DE PASCAL\n");
    printf("\n--------------------------------------------------------------------------\n");


    int filas;
    pedirNumero(&filas);
    dibujarTrianguloPascal(filas);

    system("pause");
    system("cls");
}


// SUBPROGRAMAS DEL TRI�NGULO DE PASCAL
/**********************************************************************
Subprograma:        pedirNumero
Tarea que realiza:  Solicita al usuario un n�mero entero mayor que 2
                    y ser� el n�mero de filas del tri�ngulo de Pascal.
Par�metros de S/:   filas(entero)
***********************************************************************/
void pedirNumero(int *filas) {
    printf("\n\tIntroduce la cantidad de filas para el tri�ngulo de Pascal: ");
    scanf("%d", filas);
}

/**********************************************************************
Subprograma:        dibujarTrianguloPascal
Tarea que realiza:  Dibuja un triangulo de Pascal con el numero de filas
                    que haya introducido el usuario en el subprograma
                    pedirNumero()
Par�metros de E/:   filas(entero)
***********************************************************************/
void dibujarTrianguloPascal(int filas) {
    printf("\n");
    for (int i = 0; i < filas; i++) {
        int valor = 1;

        for (int j = 0; j < filas -i - 1; j++) {
            printf("   ");
        }

        for (int j = 0; j <= i; j++) {
            printf("%6d", valor);
            valor = valor * (i - j) / (j + 1);
        }
        printf("\n");
    }
    printf("\n\n");
}


// SUBPROGRAMA CARACTERES
void caracteres() {
    char c1[50];

    //Declaramos subprogramas
    void anagramaCadenas();
    void convertirMayuscConsonantes();
    void cadena(char *c1[50]);
    void crearCadenaInvertida(char c1[50]);
    void convertirCadenas();
    int opc;

    //Mostramos el men�
    do {
        printf("--------------------------------------------------------------------------\n");
        printf("\n\t\tPROCESAR CADENA DE CARACTERES\n");
        printf("\n--------------------------------------------------------------------------\n");
        printf("\n\t1. Anagrama\n");
        printf("\n\t2. Convertir a may�scula las consonantes\n");
        printf("\n\t3. Invertir cadena\n");
        printf("\n\t4. Convirtiendo cadenas\n");
        printf("\n\t0. Salir\n");


        do{
            printf("\n\n\tSeleccione una opci�n: ");
            scanf("%d", &opc);
        }while (opc <0 || opc >4);

        system("pause");
        system("cls");

        switch(opc){
            case 1:
                anagramaCadenas();
                break;
            case 2:
                convertirMayuscConsonantes();
                break;
            case 3:
                cadena(&c1);
                crearCadenaInvertida(c1);
                break;
            case 4:
                convertirCadenas();
                break;
            case 0:
                system("cls");
                break;
        }
    } while (opc != 0);
}

void arrays(){

}


// SUBPROGRAMAS PARA PROCESAR CARACTERES
/**********************************************************************
Subprograma:        anagramaCadena
Tarea que realiza:  Solicita al usuario dos palabras, comprueba si son
                    anagramas y muestra por pantalla el resultado.
Par�metros de E/:   word1(cadena caracateres) y word2(cadena caracteres)
***********************************************************************/
//Funci�n para comprobar si dos palabras son anagramas
int anagramas(char word1[], char word2[]) {
    int conteo1[256] = {0};
    int conteo2[256] = {0};

    for (int i = 0; word1[i]; i++) {
        conteo1[(unsigned char)word1[i]]++;
    }
    for (int i = 0; word2[i]; i++) {
        conteo2[(unsigned char)word2[i]]++;
    }

    // Comparar los contadores de caracteres
    for (int i = 0; i < 256; i++) {
        if (conteo1[i] != conteo2[i]) {
            return 0; // No son anagramas si los contadores no coinciden
        }
    }
    return 1;
}
void anagramaCadenas() {
    char word1[50];
    char word2[50];
    int long1, long2, i, e, j;

    printf("--------------------------------------------------------------------------\n");
    printf("\n\t\tAnagrama\n");
    printf("\n--------------------------------------------------------------------------\n");

    //Hacer que si no tienen la misma longitud o si es la misma palabra
    //vuelva a pedir introducirlas.
    fflush(stdin);
    do{
        //Pide la primera palabra y quita el salto de l�nea
        printf("\n\tIntroduce la primera palabra: ");
        fgets(word1, sizeof(word1), stdin);
        word1[strcspn(word1, "\n")] = '\0';

        //Pide la segunda palabra y quita el salto de l�nea
        printf("\tIntroduce la segunda palabra: ");
        fgets(word2, sizeof(word2), stdin);
        word2[strcspn(word2, "\n")] = '\0';

        //Calcula la longitud de cada palabra
        long1 = strlen(word1);
        long2 = strlen(word2);

        if (long1 != long2){
            printf("\n\tLas palabras tienen que tener la misma longitud.\n");
        }
    }while(long1 != long2);

    //Comprueba si las dos palabras son iguales
    j = 0;
    for (i=0; i < long1; i++){
        if ((word1[i] != "\0") && (word2[i] != "\0") && (word1[i]==word2[i])){
            j = j+1;
        }
    }

    if (j == long1){
        printf("\n\tDos palabras iguales no son anagramas\n\n");
    } else if(anagramas(word1, word2)){
        printf("\n\tSon anagramas\n\n");
    } else{
        printf("\n\tNo son anagramas\n\n");
    }

    system("pause");
    system("cls");

    return 0;
}


/**********************************************************************
Subprograma:        convertirMayusculasConsonantes
Tarea que realiza:  Solicita al usuario una palabras y pasa las
                    consonantes a may�scula
Par�metros de E/:   word1(cadena caracateres)
***********************************************************************/
void convertirMayuscConsonantes() {
    fflush(stdin);
    //Declaramos variables
    char vocales[5] = ("AEIOU");
    char word1[50], word2[50];
    int i, e;

    printf("--------------------------------------------------------------------------\n");
    printf("\n\t\tConvertir a May�sculas las Consonantes\n");
    printf("\n--------------------------------------------------------------------------\n");

    //Solicita la palabra al usuraio y la pasa a may�sculas
    printf("\n\tIntroduce una palabra: ");
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = '\0';

    strupr (word1);

    //Pasa a may�sculas las consonantes
    for (i=0; word1[i]; i++){
        for (e=0; vocales[e]; e++){
            if (word1[i] == vocales[e]){
                word1[i] = tolower(word1[i]);
                break;
            }
        }
    }

    //Muestra la palabra con las consonantes en may�scula
    printf("\n\t%s\n", word1);

    system("pause");
    system("cls");
}

/**********************************************************************
Subprograma:        cadena
Tarea que realiza:  Solicita al usuario una cadena de caracteres y la
                    almacena como par�metro
Par�metros de E/:   word1(cadena caracateres)
***********************************************************************/
void cadena(char *c1[50]){
    fflush(stdin);

    //Pide una cadena de caracteres
    printf("\n\tIntroduce una cadena de caracteres: ");
    fgets(c1, 50, stdin);

    system("pause");
    system("cls");
}

/**********************************************************************
Subprograma:        crearCadenaInnvertida
Tarea que realiza:  Recibe una cadena como par�mtero, la invierte y
                    la muestra por pantalla
Par�metros de E/:   word1(cadena caracateres)
***********************************************************************/
void crearCadenaInvertida(char c1[50]) {
    //Declaramos variables y quitamos el salto de l�nea a la cadena de caracteres
    int i, longitud;
    c1[strcspn(c1, "\n")] = '\0';

    printf("--------------------------------------------------------------------------\n");
    printf("\n\t\tInvertir Cadena Caracteres\n");
    printf("\n--------------------------------------------------------------------------\n");

    //Solicita la palabra al usuraio y la pasa a may�sculas
    printf("\n\tCadena original: %s\n", c1);

    longitud = strlen(c1);

    //Invierte la cadena
    printf("\n\tCadena invertida: ");
    for (i= longitud - 1; i >= 0; i--){
        printf("%c", c1[i]);
    }
    printf("\n\n");

    system("pause");
    system("cls");
}

void convertirCadenas() {

}
