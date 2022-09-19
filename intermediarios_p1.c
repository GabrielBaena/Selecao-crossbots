#include <stdio.h>
#include <math.h>

float distancia(int p1[], int p2[]){
    float dist;
    dist = sqrt(pow((p2[0] - p1[0]), 2) + pow((p2[1] - p1[1]),2));
    return dist;
}

float angulo_ABC(int *pA, int *pB, int *pC){
    float a, b, c, cosseno, angulo;    //a é a distandia dos pontos AB, b é a distancia dos pontos BC e c é a distancia dos pontos case
    a = distancia(pA, pB);
    b = distancia(pB, pC);
    c = distancia(pC, pA);
    cosseno = (pow(a, 2) + pow(b, 2) - pow(c, 2))/(2*a*b);   //usa a lei dos cossenos par adescobrir o cosseno do angulo
    angulo = acos(cosseno);    
    return angulo;
}

int main()
{
    int pA[2] = {1,1}, pB[2] = {0,0}, pC[2] = {0,1};
    printf("%f\n", angulo_ABC(pA, pB, pC));
    return 0;
}
