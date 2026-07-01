#include <stdio.h>

void espacamento(){
    printf("....\n");
}

void movimentacao_torre(int mov_torre_horizontal, int mov_torre_vertical){
    //movimentação da torre com FOR
    printf("MOVIMENTAÇÃO DA TORRE:\n");
    if(mov_torre_horizontal>0 || mov_torre_vertical > 0){//Se o numero positivo ele faz esse for de baixo
        for(int i = 1; i<=mov_torre_horizontal || i<=mov_torre_vertical; i++){
            if(mov_torre_horizontal>0){
                printf("CIMA\n");
            }else if(mov_torre_vertical>0){
                printf("DIREITA\n");
            }
        }
    }else{//se o numero for negativo ele faz esse for de baixo
        for(int i = 0; i>mov_torre_horizontal || i>mov_torre_vertical; i--){
            if(mov_torre_horizontal<0){
                printf("BAIXO\n");
            }else if(mov_torre_vertical<0){
                printf("ESQUERDA\n");
            }
        }
    }
}

void movimentacao_bispo(int mov_bispo_horizontal, int mov_bispo_vertical){
    printf("MOVIMENTAÇÃO DO BISPO:\n");
    int cima=0, direita=0, baixo=0, esquerda=0;
    do{
        if(mov_bispo_horizontal>0){
            if(mov_bispo_vertical>0){
                printf("DIREITA\n");
                printf("CIMA\n");
                baixo--, direita++;
            }else{
                printf("DIREITA\n");
                printf("BAIXO\n");
                cima++, esquerda--;
            }
        }else{
            if(mov_bispo_vertical>0){
                printf("ESQUERDA\n");
                printf("CIMA\n");
                cima++, direita++;
            }else{
                printf("ESQUERDA\n");
                printf("BAIXO\n");
                baixo--, esquerda--;
            }
        }
    }while((mov_bispo_horizontal != cima && mov_bispo_horizontal != baixo) && (mov_bispo_vertical != direita && mov_bispo_vertical != esquerda));//vai fazer o ciclo ENQUANTO as váriaveis não derem match.
    

}

void movimentacao_rainha(int mov_rainha_horizontal, int mov_rainha_vertical){
    printf("MOVIMENTAÇÃO DA RAINHA:\n");
    int rainha_cima = 0 , rainha_baixo = 0 , rainha_direita = 0 , rainha_esquerda = 0;    
    while(!(mov_rainha_horizontal == rainha_cima || mov_rainha_horizontal == rainha_baixo) && (mov_rainha_vertical == rainha_direita || mov_rainha_vertical == rainha_esquerda)){
        if(mov_rainha_horizontal > 0 ){
            printf("DIREITA\n");
            rainha_cima++;
        }else if(mov_rainha_horizontal < 0){
            printf("ESQUERDA\n");
            rainha_baixo--;
        }         
        if(mov_rainha_vertical > 0){
            printf("CIMA\n");
            rainha_direita++;
        }else if(mov_rainha_vertical < 0){
            printf("BAIXO\n");
            rainha_esquerda--;
        }
    }
}

void movimentacao_cavalo(int mov_cavalo_horizontal, int mov_cavalo_vertical){
    printf("MOVIMENTAÇÃO DO CAVALO:\n");
    //movimentação horizontal
    if(mov_cavalo_horizontal>0){    
        for(int i = 0; i<mov_cavalo_horizontal; i++){
            printf("DIREITA\n");
        }
    }else{
        for(int i = 0; i>mov_cavalo_horizontal; i--){
            printf("ESQUERDA\n");
        }
    }
    //movimentação vertical
    if(mov_cavalo_vertical>0){    
        for(int i = 0; i<mov_cavalo_vertical; i++){
            printf("CIMA\n");
        }
    }else{
        for(int i = 0; i>mov_cavalo_vertical; i--){
            printf("BAIXO\n");
        }
    }
    
}

int main(){
    //lógica de movimentação das peças:
    /* Vão haver duas varíaveis, uma para a movimentação horizontal e outra para a movimentação vertical.
    Quando o valor da variavel for positivo ela vai para direita ou para cima, quando for negativo ela vai para a esquerda ou para baixo.
    O usuario vai explicar qual casa ele quer e o sistema vai fazer a movimentação da peça. */

    //declaração das variáveis: (vão ser sempre numeros inteiros)
    int mov_torre_horizontal = 5,
        mov_bispo_horizontal = 5,
        mov_rainha_horizontal = -8,
        mov_cavalo_horizontal = 1;

    int mov_torre_vertical = 0,
        mov_bispo_vertical = -5,
        mov_rainha_vertical = 0,
        mov_cavalo_vertical = -2;

    //movimentação da torre com FOR e recursividade
    movimentacao_torre(mov_torre_horizontal, mov_torre_vertical);

    espacamento();

    //movimentação bisco com WHILE
    movimentacao_bispo(mov_bispo_horizontal, mov_bispo_vertical);

    espacamento();
    
    //Movimentação da rainha com WHILE
    movimentacao_rainha(mov_rainha_horizontal, mov_rainha_vertical);

    espacamento();

    //movimentação do cavalo.
    movimentacao_cavalo(mov_cavalo_horizontal, mov_cavalo_vertical);
    

}