#include <stdio.h>

int soma_valores_vetor(){
    int vetor[10] = {13, 5, 7, 6, 4, 8, 16, 31, 9, 21} ;
    int x, y, result;
    
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