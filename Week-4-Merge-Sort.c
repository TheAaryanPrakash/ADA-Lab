#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    // Merge the two arrays back into arr[]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int arr[MAX], n;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements (N): ");
    scanf("%d", &n);

    // Generate random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    start = clock(); // Start time
    mergeSort(arr, 0, n - 1);
    end = clock();   // End time

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken to sort %d elements = %.6f seconds\n", n, time_taken);

    return 0;
}
