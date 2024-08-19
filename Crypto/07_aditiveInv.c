#include <stdio.h>

int additiveInverse(int a, int m) {
    return (m - a) % m;
}

int main() {
    int a, m, additiveInv;
    
    printf("Enter a number and modulo: ");
    scanf("%d %d", &a, &m);

    additiveInv = additiveInverse(a, m);

    printf("The additive inverse of %d mod %d is %d\n\n\n", a, m, additiveInv);

    return 0;
}
