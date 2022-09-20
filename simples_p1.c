#include <stdio.h>

int soma_valores_vetor(){
    int vetor[10];
    int i, x, y, result;
    
    for(i = 0; i < 10; i++){    //pega os valores da lista
        printf("Valor do %d valor da lista: ", i);
        scanf("%d", &vetor[i]);
    }
    do{printf("Valor de X: ");
    scanf("%d", &x);
    } while(x<0 || x>9);    //verifica se a posição x está dentro do vetor
    do{printf("Valor de Y: ");
    scanf("%d", &y);
    } while(y<0 || y>9);    //verifica se a posição y está dentro do vetor
    result = vetor[x] + vetor[y];
    return result; 
}

int main()
{
    printf("%d", soma_valores_vetor());

    return 0;
}
