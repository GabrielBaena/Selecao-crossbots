#include <stdio.h>

float converte_temperatura(float F){
    float C;
    C = (F-32) * 5 / 9;
    return C;
}

int main()
{
    float C = converte_temperatura(77.2);
    printf("%f", C);

    return 0;
}