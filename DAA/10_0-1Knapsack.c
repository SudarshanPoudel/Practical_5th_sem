#include <stdio.h>

int knapsack(int W, int w[], int v[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;  
            else if (w[i - 1] <= j)
                dp[i][j] = (v[i - 1] + dp[i - 1][j - w[i - 1]] > dp[i - 1][j]) ? 
                            v[i - 1] + dp[i - 1][j - w[i - 1]] : dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main() {
    int v[] = {60, 100, 120};
    int w[] = {10, 20, 30};
    int W = 50;  
    int n = sizeof(v) / sizeof(v[0]);

    int maxValue = knapsack(W, w, v, n);

    printf("Maximum v in Knapsack = %d\n", maxValue);

    return 0;
}
