#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function used by Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Recursive Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // pi = partition index

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[MAX], n;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements (N): ");
    scanf("%d", &n);

    // Generate random elements
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    start = clock(); // Start time

    quickSort(arr, 0, n - 1);

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
