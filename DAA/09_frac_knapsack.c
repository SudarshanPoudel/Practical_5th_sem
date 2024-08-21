// C program to implement Fractional Knapsack

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(int value[], int weight[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double r1 = (double)value[j] / weight[j];
            double r2 = (double)value[j + 1] / weight[j + 1];
            if (r1 < r2) {
                swap(&value[j], &value[j + 1]);
                swap(&weight[j], &weight[j + 1]);
            }
        }
    }
}

double fractionalKnapsack(int W, int value[], int weight[], int n) {
    sortItems(value, weight, n);

    double totalValue = 0.0;
    int curWeight = 0;

    for (int i = 0; i < n; i++) {
        if (curWeight + weight[i] <= W) {
            curWeight += weight[i];
            totalValue += value[i];
        } else {
            int remain = W - curWeight;
            totalValue += value[i] * ((double)remain / weight[i]);
            break;
        }
    }

    return totalValue;
}

int main() {
    int W = 50;  
    int value[] = {50, 110, 120};
    int weight[] = {20, 10, 30};
    int n = sizeof(value) / sizeof(value[0]);

    double maxValue = fractionalKnapsack(W, value, weight, n);

    printf("Maximum value in Knapsack = %.2lf\n", maxValue);
    printf("\n\n\n");
    return 0;
}
