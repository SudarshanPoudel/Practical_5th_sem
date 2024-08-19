#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform the KS test
float ksTest(float data[], int n) {
    // Sort the data array using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                float temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    // Perform KS test
    float D = 0.0;
    for (int i = 0; i < n; i++) {
        float F_empirical = (i + 1) / (float)n;
        float F_theoretical = data[i];
        float diff = fabs(F_empirical - F_theoretical);
        if (diff > D) D = diff;
    }
    return D;
}

int main() {
    printf("\n\n\n");
    int n;
    printf("Enter the number of random numbers: ");
    scanf("%d", &n);

    float data[n];
    printf("Enter the random numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &data[i]);
    }

    float D = ksTest(data, n);
    float D_critical = 1.36 / sqrt(n);

    printf("KS Test Statistic: %f\n", D);
    printf("Critical Value at alpha = 0.05: %f\n", D_critical);
    if (D > D_critical) {
        printf("Reject the null hypothesis (the data does not follow a uniform distribution).\n\n\n");
    } else {
        printf("Fail to reject the null hypothesis (the data follows a uniform distribution).\n\n\n");
    }
    return 0;
}
