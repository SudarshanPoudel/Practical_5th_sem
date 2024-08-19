#include<stdio.h>

int main(){
    int n, modulo, c, m, i, x[1000];
    float result[1000];

    printf("Enter no. of numbers and seed : ");
    scanf("%d %d", &n, &x[0]);
    printf("Enter multiplier, increment and modulo: ");
    scanf("%d %d %d", &m, &c, &modulo);

    result[0] = (float)x[0]/modulo;
    for(i = 1; i < n; i++){
        x[i] = (x[i-1] * m + c) % modulo;
        result[i] = (float)x[i]/modulo;
    }

    printf("Generated random numbers are : ");
    for(i = 0; i < n; i++){
        printf(" %.3f", result[i]);
    }
    printf("\n\n\n");
    return 0;
}