#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int multiplicativeInverse(int b, int a) {
    int t, q, r;
    int t1 = 0, t2 = 1;

    if (a == 1)
        return 0;

    while (a > 1) {
        q = a / b;
        r = a % b;
        t = t1 - t2 * q;

        t1 = t2;
        t2 = t;
        a = b;
        b = r;
    }
    return t1;
}

int main() {
    int a, m;
    
    printf("Enter a number and modulus: ");
    scanf("%d %d", &a, &m);

    if (gcd(a, m) == 1) {
        int multiplicativeInv = multiplicativeInverse(a, m);
        printf("The multiplicative inverse of %d mod %d is %d\n\n", a, m, multiplicativeInv);
    } else {
        printf("Multiplicative inverse does not exist for %d mod %d because they are not coprime.\n\n", a, m);
    }

    return 0;
}
