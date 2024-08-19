// Program to simulate markov chain for given rain and not rain case and answer probability of not
// rainy day after tomorrow and rainy after 3 days if its not raining today.
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
    float r_after_r = 0.6;
    float nr_after_nr = 0.8;
    float nr_after_r = 1 - r_after_r;
    float r_after_nr = 1 - nr_after_nr;
    
    float p[2][2] = {{r_after_r, nr_after_r}, {r_after_nr, nr_after_nr}}, p1[2][2], p2[2][2];

    multiplyMatrices(p, p, p1);
    multiplyMatrices(p, p1, p2);

    printf("If it's not raining today\n");
    printf("Probability of not rainy after tomorrow: %.2f\n", p1[1][1]);
    printf("nProbability of rainy after 3 days: %.2f\n\n\n", p2[1][0]);

    return 0;
}

