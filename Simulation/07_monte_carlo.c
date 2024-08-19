// Estimate value of pi using monte carlo

#include <stdio.h>
#include <stdlib.h>


float estimatePi(int numIterations) {
    int insideCircle = 0;

    for (int i = 0; i < numIterations; i++) {
        float x = (float)rand() / RAND_MAX;
        float y = (float)rand() / RAND_MAX;

        if ((x * x + y * y) <= 1.0) {
            insideCircle++;
        }
    }
    return (4.0 * insideCircle) / numIterations;
}

int main() {
    int numIterations;
    printf("Enter the number of iterations: ");
    scanf("%d", &numIterations);

    float pi = estimatePi(numIterations);
    printf("Estimated value of pi: %f\n\n\n", pi);

    return 0;
}
