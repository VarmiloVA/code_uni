#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    //Declaramos variables
    char vocales[5] = ("AEIOU");
    char word1[50], word2[50];
    int i, e;

    //Solicita la palabra al usuraio y la pasa a may�sculas
    printf("Introduce una palabra: ");
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = '\0';

    strupr (word1);
    printf("\n%s", word1);

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
    printf("\n%s", word1);
}
