
#include <stdio.h>
#include <string.h>

int encontra_letra(char letra, char *string){
    int size = strlen(string), i = 0, num_letra = 0;
    for(i; i < size; i++){
        if(string[i] == letra){
            num_letra++;
        }
    }
    return num_letra;
}

int main()
{
    printf("%d", encontra_letra('a', "uma frase generica de questões de programação"));

    return 0;
}
