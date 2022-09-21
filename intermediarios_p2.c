#include <stdio.h>
#include <stdlib.h>


int verifica_num_em_array(int *array, int num, int size){
    int i = 0;
    for (i; i < size; i++){
        if(array[i] == num){
            return 1;
        }
    }
    return 0;
}

int * sem_repeticoes(int * lista, int size){
    int i = 0, j = 0, num_nao_repetidos = size, num_usados;
    
    for(i = 0; i < size; i++){    //loop para ver quantos numeros nao repetidos tem
        for(j = 0; j < size; j++){
            if(j != i){
                if(lista[i] != lista[j]){
                    num_nao_repetidos--;
                }
            }
        }
    }
    int *array; 
    array = malloc(num_nao_repetidos*sizeof(int));
    for(i = 0; i < size; i++){
        if(verifica_num_em_array(array, lista[i], num_usados) == 0){
            array[num_usados] = lista[i];
            printf("%d", array[num_usados]);
            num_usados++;
            
        }
    }
    return array;
}

int main()
{
    int lista1[] = {1, 1, 1, 1, 1, 2, 5, 2, 8, 7, 1, 6, 4, 5};
    int size = sizeof(lista1)/sizeof(lista1[0]), i = 0;
    int *lista2 = sem_repeticoes(lista1, size);

    return 0;
}
