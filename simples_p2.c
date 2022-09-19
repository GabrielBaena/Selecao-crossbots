include <stdio.h>
#include <math.h>

int numero_perfeito(float num){
    int soma_div = 0;
    printf("0 ");
    for(int i = 1; i < num; i++){
        if (ceil(num/i) == floor(num/i)){
            soma_div += i;
            printf("+ %d ", i);
        }
    }
    printf("= %d\n", soma_div);
    if(soma_div == num){
        return 0;
    }
    else return 1;
}
int main()
{
    printf("%d", numero_perfeito(28));
    return 0;
}