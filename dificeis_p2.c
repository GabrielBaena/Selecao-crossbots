#include <stdio.h>
#include <stdlib.h>

int check_empty_board(char tabuleiro[8][8]){
    int i = 0, j = 0;
    for(i; i < 8; i++){
        for(j; j < 8; j++){
            if(tabuleiro[i][j] != '.'){
                return 1;
            }
        }
    }
    return 0;
}

int check_pawn(char tabuleiro[8][8], int y, int x, int jogo){

    if(tabuleiro[y][x] == 'P'){    //define qual peça procurar (rei branco ou preto)
        char alvo = 'k';
        if(tabuleiro[y-1][x-1] == alvo || tabuleiro[y-1][x+1] == alvo){   //verifica se o peão mata o rei inimigo
            printf("Jogo %d: rei %c esta em cheque.\n", jogo, alvo);
            return 0;
        }
    }
    else if(tabuleiro[y][x] == 'p'){
        char alvo = 'K';
        if(tabuleiro[y+1][x-1] == alvo || tabuleiro[y+1][x+1] == alvo){   //verifica se o peão mata o rei inimigo
            printf("Jogo %d: rei %c esta em cheque.\n", jogo, alvo);
            return 0;
        }
    }
    else return 1;    //nao pode matar o rei
}

int check_rook(char tabuleiro[8][8], int y, int x, int jogo){
    int i = 0, c;
    
    if(tabuleiro[y][x] == 'R' || tabuleiro[y][x] == 'Q'){   //define qual peça procurar (rei branco ou preto)
        c = 107;
    }  //coloquei a opção para o Q tambem para já preparar para a função da rainha
    else if(tabuleiro[y][x] == 'r' || tabuleiro[y][x] == 'q'){
        c = 75;
    }
    
    char alvo = c;
    
    do{ 
        i++;
        if(tabuleiro[y+i][x] == alvo){   //verifica se o rei está acima da torre
           printf("Jogo %d: rei %c esta em cheque.\n", jogo, alvo);
           return 0;
        }
    }while(y+i < 8 && tabuleiro[y+i][x] == '.');
    
    i = 0;
    
    do{ i++;
        if(tabuleiro[y-i][x] == alvo){   //verifica se o rei está abaixo da torre
           printf("Jogo %d: rei %c esta em cheque.\n", jogo, alvo);
           return 0;
        }
    }while(y-i > 0 && tabuleiro[y-i][x] == '.');
    
    i = 0;
    
    do{
        i++;
        if(tabuleiro[y][x+i] == alvo){   //verifica se o rei está na direita da torre
           printf("Jogo %d: rei %c esta em cheque.\n", jogo, alvo);
           return 0;
        }
    }while(x+i < 8 && tabuleiro[y][x+i] == '.');
    
    i = 0;
    
    do{
        i++;
        if(tabuleiro[y][x-i] == alvo){   //verifica se o rei está na esquerda da torre
           printf("Jogo %d: rei %c esta em cheque.\n", jogo, alvo);
           return 0;
        }
    }while(x-i > 0 && tabuleiro[y][x-i] == '.');
    
    return 1;   //nao pode matar o rei
}

int check_knight(char tabuleiro[8][8], int y, int x, int jogo){
     int c;
     
    if(tabuleiro[y][x] == 'N'){   //define qual peça procurar (rei branco ou preto)
        c = 107;
    }  //coloquei a opção para o Q tambem para já preparar para a função da rainha
    else if(tabuleiro[y][x] == 'n'){
        c = 75;
    }
    
    char alvo = c;
    
    if(tabuleiro[y+1][x+2] == alvo || tabuleiro[y+1][x-2] == alvo || tabuleiro[y-1][x+2] == alvo || 
    tabuleiro[y-1][x-2] == alvo || tabuleiro[y+2][x+1] == alvo || tabuleiro[y+2][x-1] == alvo || 
    tabuleiro[y-2][x+1] == alvo || tabuleiro[y-2][x-1] == alvo){  //procura nas oito posições que o cavalo pode ir
        printf("Jogo %d: rei %c esta em cheque.\n", jogo, alvo);
        return 0;
    }
    else return 1;  //nao pode matar o rei
}

int check_bishop(char tabuleiro[8][8], int y, int x, int jogo){
    
    int i = 0, c;
    if(tabuleiro[y][x] == 'B' || tabuleiro[y][x] == 'Q'){   //define qual peça procurar (rei branco ou preto)
        c = 107;
    }  //coloquei a opção para o Q tambem para já preparar para a função da rainha
    else if(tabuleiro[y][x] == 'b' || tabuleiro[y][x] == 'q'){
        c = 75;
    }
    
    char alvo = c;
    
    do{
        i++;
        if(tabuleiro[y+i][x+i] == alvo){   //verifica se o rei está na diagonal direita superior do bispo
           printf("Jogo %d: rei %c esta em cheque.\n", jogo, alvo);
           return 0;
        }
        
    }while(y+i < 8 && x+i < 8 && tabuleiro[y+i][x+i] == '.');
    
    i = 0;
    
    do{
        i++;
        if(tabuleiro[y-i][x+i] == alvo){   //verifica se o rei está na diagonal direita inferior do bispo
           printf("Jogo %d: rei %c esta em cheque.\n", jogo, alvo);
           return 0;
        }
    }while(y-i > 0 && x+i < 8 && tabuleiro[y-i][x+i] == '.');
    
    i = 0;
    
    do{  
        i++;
        if(tabuleiro[y+i][x-i] == alvo){   //verifica se o rei está na diagonal esquerda superior do bispo
           printf("Jogo %d: rei %c esta em cheque.\n", jogo, alvo);
           return 0;
        }
    }while(y+i < 8 && x-i > 0 && tabuleiro[y+i][x-i] == '.');
    
    i = 0;
    
    do{
        i++;
        if(tabuleiro[y-i][x-i] == alvo){   //verifica se o rei está na diagonal esquerda inferior do bispo
           printf("Jogo %d: rei %c esta em cheque.\n", jogo, alvo);
           return 0;
        }
    }while(y-i > 0 && x-i > 0 && tabuleiro[y-i][x-i] == '.');
    
    return 1; //nao pode matar o rei
}

int check_queen(char tabuleiro[8][8], int y, int x, int jogo){  //como a rainha e a juncao do movimento do bispo e 
                                                               //da torre, logo,vou apenas vou chamar as funcoes deles
    if(check_rook(tabuleiro, y, x, jogo) == 0){  //procura os lados
        return 0;
    }
    
    else if(check_bishop(tabuleiro, y, x, jogo) == 0){  //procura as diagonais
        return 0;
    }
    
    else return 1;
}

void checkmate(){
    char tabuleiro[8][8];
     int jogo = 1, i = 0, j = 0, check = 2;
    while(1==1){
        char k;
        for(i = 0; i < 8; i++){     //le o input do tabuleiro
            for(j = 0; j < 8; j++){
                scanf("%c", &k);
                tabuleiro[i][j] = k;
            }
        }
        getchar();    //retira o \n inserido pelo scanf()
        if(check_empty_board(tabuleiro) == 0){
            printf("Foi inserido um tabuleiro vazio\n  Encerrando programa...");
            break;
        }

        check = 2;
        
        for(i = 0; i < 8; i++){     //passa por cada casa e verifica de acordo com a peça
            for(j = 0; j < 8; j++){
                if(tabuleiro[i][j] == 'p' || tabuleiro[i][j] == 'P'){
                    if (check_pawn(tabuleiro, i, j, jogo) == 0){
                        check = 0;
                    }
                }
                else if(tabuleiro[i][j] == 'r' || tabuleiro[i][j] == 'R'){
                    if (check_rook(tabuleiro, i, j, jogo) == 0){
                        check = 0;
                    }
                }
                else if(tabuleiro[i][j] == 'n' || tabuleiro[i][j] == 'N'){
                    if (check_knight(tabuleiro, i, j, jogo) == 0){
                        check = 0;
                    }
                }
                else if(tabuleiro[i][j] == 'b' || tabuleiro[i][j] == 'B'){
                    if (check_bishop(tabuleiro, i, j, jogo) == 0){
                        check = 0;
                    }
                }
                else if(tabuleiro[i][j] == 'q' || tabuleiro[i][j] == 'Q'){
                    if (check_queen(tabuleiro, i, j, jogo) == 0){
                        check = 0;
                    }
                }
            }
        }
        if(check != 0){      //caso nenhuma peça possa matar algum rei
            printf("Jogo %d: nenhum rei esta em cheque.\n", jogo);
        jogo++;
    }   
    }
}

int main()
{
        checkmate();
        
    return 0;
}
