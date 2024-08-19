// Practical 2
// program to simulate markov chain problem with coke pepsi example

#include<stdio.h>

void multiplyMatrices(float A[2][2], float B[2][2], float C[2][2]) {
    int i, j, k;

    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            C[i][j] = 0;
        }
    }

    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            for (k = 0; k < 2; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(){
    float p[2][2], p1[2][2], p2[2][2];

    printf("Enter probability of purchasing coke again after purchasing coke : ");
    scanf("%f", &p[0][0]);
    p[0][1] = 1 - p[0][0];
    printf("Enter probability of purchasing pepsi again after purchasing pepsi : ");
    scanf("%f", &p[1][1]);
    p[1][0] = 1 - p[1][1];

    multiplyMatrices(p, p, p1);
    multiplyMatrices(p, p1, p2);

    printf("\nProbability of current coke purchaser purchasing coke after 2 purchases : %.2f\n", p2[0][0]);
    printf("Probability of current coke purchaser purchasing pepsi after 2 purchases : %.2f\n", p2[0][1]);
    printf("Probability of current pepsi purchaser purchasing coke after 2 purchases : %.2f\n", p2[1][0]);
    printf("Probability of current pepsi purchaser purchasing pepsi after 2 purchases : %.2f\n\n", p2[1][1]);

    return 0;
}

