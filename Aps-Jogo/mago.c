#include <stdio.h>
#include <stdlib.h>
#include "Personagem.h"
#include "Monstros.h"

static void subir_lvl_mago(struct personagem *mago){

    static int hp=0, dano=0, armor=0, inte=0, agili=0;
    int i, numeroDeUps = 5;
    char escolha;

    mago->lvl++;
    mago->HP = 14 + hp;
    mago->forca = 5 + dano;
    mago->armadura = 3 + armor;
    mago->inteligencia = 5 + inte;
    mago->agilidade = 5 + agili;

    printf("Parabens!!!\nVoce Subiu de lvl\n\n");

    for(i = 0; i < 5; i++){

        printf("Voce possui: %d pontos para upar\n\n", numeroDeUps);
        printf("1- Mais 1 de HP\n");
        printf("2- Mais 1 de Forca\n");
        printf("3- Mais 1 de armadura\n");
        printf("4- Mais 1 de inteligencia\n");
        printf("5- Mais 1 de agilidade\n");

        printf("Digite sua escolha: ");
        escolha = getch();
        printf("\n");

        while(escolha <  49 || escolha > 53){

            printf("Nao existe esta opcao!!!\n");
            printf("Escolha uma opcao valida\n");
            escolha = getch();
            printf("\n");

        }

        if(escolha == '1'){
            mago->HP++;
            printf("\nHP = %d\n", mago->HP);
            hp++;
        }
        if(escolha == '2'){
            mago->forca++;
            printf("\nForca = %d\n", mago->forca);
            dano++;
        }
        if(escolha == '3'){
            mago->armadura++;
            printf("\nArmadura = %d\n", mago->armadura);
            armor++;
        }
        if(escolha == '4'){
            mago->inteligencia++;
            printf("\nIntelifencia = %d\n", mago->inteligencia);
            inte++;
        }
        if(escolha == '5'){
            mago->agilidade++;
            printf("\aAgilidade = %d\n", mago->agilidade);
            agili++;
        }
        numeroDeUps--;
        limpa_tela();
    }
    mago->aventureiro_nome(mago);
}

static void menu_mago(struct personagem *mago){

    printf("Seu turno \n\n");
    printf("Escolha o seu ataque:\n");
    printf("1-Bola de fogo\t");
    printf("2-Inferno\n");
    printf("3-Meteoro arcano\t");
    printf("4-Suspiro do Drag�o\n");
    printf("5-Descansar\n");
    printf("\n");

}

static void nome_mago(struct personagem *mago){

    printf("Nome = %s\n", mago->nome);
    printf("Classe = %s\n", mago->classe);
    printf("LVL = %d\n", mago->lvl);
    printf("HP = %d\n", mago->HP);
    printf("Forca = %d\n", mago->forca);
    printf("Armadura = %d\n", mago->armadura);
    printf("Inteligencia = %d\n", mago->inteligencia);
    printf("Agilidade = %d\n", mago->agilidade);
    printf("Staminia = %d\n", mago->staminia);
    printf("\n");

}

static int mago_ataque_fraco(struct personagem *mago){

    int X;

    if(mago->staminia < 2){

        printf("Voce nao conseguiu atacar\n");
        return -1;
    }

    if(mago->staminia >= 2){

        X = rand() % mago->inteligencia;

        printf("Bola de Fogo = %d\n", X);

        mago->staminia = mago->staminia - 2;

        return X;
    }
}

static int mago_ataque_forte(struct personagem *mago){

    int X;

    if(mago->staminia < 4){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(mago->staminia >= 4){

    X = mago->forca + rand() % mago->inteligencia;

    printf("�rea Infernal = %d\n", X);

    mago->staminia = mago->staminia - 4;

    return X;

    }

}

static int mago_magia1(struct personagem *mago){

    int X, Y, Z;

    if(mago->staminia <= 0){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(mago->staminia == 1){

        X = mago->lvl + rand() % 4;
        printf("1 Meteoros Arcanos = %d\n", X);
        mago->staminia = mago->staminia - 1;
        return X;

    }

    if(mago->staminia == 2){

        X = mago->lvl + rand() % 4;
        Y = mago->lvl + rand() % 3;
        printf("2 Meteoros Arcanos = %d\n", X);
        mago->staminia = mago->staminia - 2;
        return X + Y;

    }

    if(mago->staminia >= 3){

    X = mago->lvl + rand() % 4;
    Y = mago->lvl + rand() % 3;
    Z = mago->lvl + rand() % 2;

    X = X + Y + Z;

    printf("3 Meteoros Arcanos = %d\n", X);

    mago->staminia = mago->staminia - 3;

    return X;

    }
}


static int mago_magia2(struct personagem *mago){

    int X;

    if(mago->staminia < 5){

        printf("Voce nao conseguiu atacar\n");
        return -1;

    }

    if(mago->staminia >= 5){

    X = rand() % mago->inteligencia * mago->lvl;

    printf("Suspiro do Drag�o = %d\n", X);

    mago->staminia = mago->staminia - 5;

    return X;

    }

}

static void mago_passiva(struct personagem *mago, struct monstros *monstro){



}

static void mago_descanso(struct personagem *mago){

    if(mago->staminia == 10){
        printf("Voce ja esta descansado\n");
    }

    if(mago->staminia == 9){
        mago->staminia++;
        printf("Voce recuperou 1 de stamina\n");
    }
    if(mago->staminia < 9){
        mago->staminia = mago->staminia + 2;
        printf("Voce recuperou 2 de stamina\n");
    }
}

PERSONAGEM *new_mago(char *nome, char *classe, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    //-> ponteiro do tipo de uma estrutura que esta recebendo tal valor

    PERSONAGEM *mago = (PERSONAGEM *) malloc(sizeof(PERSONAGEM));

    mago->nome = nome;
    mago->classe = classe;
    mago->lvl = lvl;
    mago->HP = HP;
    mago->forca = forca;
    mago->armadura = armadura;
    mago->inteligencia = inteligencia;
    mago->agilidade = agilidade;
    mago->staminia = 10;

    mago->subir_lvl = subir_lvl_mago;
    mago->aventureiro_menu = menu_mago;
    mago->aventureiro_nome = nome_mago;
    mago->ataque_fraco = mago_ataque_fraco;
    mago->ataque_forte = mago_ataque_forte;
    mago->aventureiro_magia1 = mago_magia1;
    mago->aventureiro_magia2 = mago_magia2;
    mago->aventureiro_passiva = mago_passiva;
    mago->descansar = mago_descanso;

    return mago;

}
