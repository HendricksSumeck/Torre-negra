#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Monstros.h"
#include "Personagem.h"

void historia_incio(void){

    FILE *arquivo1;
    char f;

    char frase[1000];

    arquivo1 = fopen("textos/historia_inicio.txt", "r");

    while(fscanf(arquivo1, "%c", &f) != EOF){

        printf("%c", f);

    }

    fclose(arquivo1);

}
