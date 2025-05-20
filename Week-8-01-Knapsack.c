#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 0/1 Knapsack implementation using Dynamic Programming
int knapsack(int n, int W, int w[], int v[]) {
    int V[MAX_ITEMS + 1][MAX_CAPACITY + 1];

    // Build table V[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                V[i][j] = 0;  // Base case: no items or 0 capacity
            } else if (j - w[i - 1] >= 0) {
                // Include or exclude the current item
                V[i][j] = max(V[i - 1][j], v[i - 1] + V[i - 1][j - w[i - 1]]);
            } else {
                // Cannot include the item, too heavy
                V[i][j] = V[i - 1][j];
            }
        }
    }

    return V[n][W]; // The maximum value with all items and full capacity
}

int main() {
    int n, W;
    int weights[MAX_ITEMS], values[MAX_ITEMS];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    printf("Enter weights of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter values of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    int result = knapsack(n, W, weights, values);
    printf("Maximum value that can be put in the knapsack = %d\n", result);

    return 0;
}
