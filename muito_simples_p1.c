#include <stdio.h>
#include <math.h>
float distancia(int p1[], int p2[]){
    float dist;
    dist = sqrt(pow((p2[0] - p1[0]), 2) + pow((p2[1] - p1[1]),2));
    return dist;
}

int main()
{
    int p1[] = {1, 2};
    int p2[] = {5, 6};
    float dist;
    dist = distancia(p1, p2);
    printf("%f",dist);

    return 0;
}