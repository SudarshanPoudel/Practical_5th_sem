#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int modInverse(int e, int phi) {
    int t = 0, newT = 1;
    int r = phi, newR = e;

    while (newR != 0) {
        int quotient = r / newR;
        int tempT = t;
        t = newT;
        newT = tempT - quotient * newT;

        int tempR = r;
        r = newR;
        newR = tempR - quotient * newR;
    }

    if (t < 0) t = t + phi;

    return t;
}

int main() {
    int p = 61, q = 53;
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 17;
    int d = modInverse(e, phi);

    printf("Public Key: (n: %d, e: %d)\n", n, e);
    printf("Private Key: (n: %d, d: %d)\n", n, d);

    char message[100];
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    int len = strlen(message);
    int encrypted[len];

    printf("Encrypted message: ");
    for (int i = 0; i < len; i++) {
        encrypted[i] = modExp(message[i], e, n);
        printf("%d ", encrypted[i]);
    }
    printf("\n");

    printf("Decrypted message: ");
    for (int i = 0; i < len; i++) {
        char decryptedChar = (char)modExp(encrypted[i], d, n);
        printf("%c", decryptedChar);
    }
    printf("\n\n");

    return 0;
}
