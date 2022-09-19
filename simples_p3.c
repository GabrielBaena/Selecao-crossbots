
#include <stdio.h>
#include <stdlib.h>


int check_num_primo(int num){
    int metade = num/2;
    if(num == 1 || num == 0){
        return 1;
    }
    for(int i = 2; i <= metade; i++){   //verifica de o numero tem algum divisor entre 2 e a metade do valor
        if(num % i == 0){
            return 1;   // achou um divisor e retorna 1
        }
    }
    return 0;  //nao achou divisor e retorna 0
}

void num_primo(int *num, int size){
    int i = 0;


    for(i; i < size; i++){    //passa por todos os números da array e imprime os pares
        if(check_num_primo(num[i]) == 0){
            printf("%d ", num[i]);
        }
   }
}

int main()
{
    int num[]= {1,2,3,4,5, 13, 7};
    num_primo(num, 7);

    return 0;
}
