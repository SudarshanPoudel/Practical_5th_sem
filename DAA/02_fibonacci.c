// C program to find nth fibonacci number using recursion

#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int terms;

    printf("Enter number of terms: ");
    scanf("%d", &terms);

    printf("Fibonacci sequence:\n");
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n\n\n");

    return 0;
}
