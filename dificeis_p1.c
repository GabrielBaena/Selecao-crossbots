#include <stdio.h>
#include <string.h>

int verifica_linha(char *mina){     //verifica se na linha tem os caracteres certos
    int i = 0, size = strlen(mina);
    for(i; i < size; i++){
        if(mina[i] != '.' && mina[i] != '<' && mina[i] != '>' && mina[i] != 10){
            printf("%d", mina[i]);
            return 1; 
        }
    }
    return 0;
}

int num_diamantes(){
    char mina[1000];
    fgets(mina, 1000, stdin);
    int i = 0, size = strlen(mina), num_left_side = 0, num_right_side = 0, sand_grains = 0, num_diamantes;
    if(verifica_linha(mina) == 1){
        printf("A mina que João está trabalhando possui coisas que não são areia ou diamantes");
        return 0;
    }
    for(i; i < size; i++){       //conta quantos lados e quantos grãos de areia tem
        if(mina[i] == '<'){
            num_left_side++;
        }
        else if(mina[i] == '>'){
            num_right_side++;
        }
        else if(mina[i] == '.'){
            sand_grains++;
        }
    }
    if(num_left_side >= num_right_side){    //verifica qual dos lados estao em maior quantidade
        num_diamantes = num_right_side;
    }
    else if(num_left_side < num_right_side){
        num_diamantes = num_left_side;
    }
    
    printf("João achou %d diamante no meio de %d grãos de areia", num_diamantes, sand_grains);
    
    return num_diamantes;
}

int main()
{
    num_diamantes();

    return 0;
}
