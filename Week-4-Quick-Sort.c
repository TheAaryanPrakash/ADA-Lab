#include <stdio.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place the pivot in the correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Pivot is the first element
    int i = low + 1;      // Pointer for elements less than pivot
    int j = high;         // Pointer for elements greater than pivot

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            i++;                                  //Looking for i greater than Pivot
        }
        while (arr[j] > pivot) {
            j--;                                  //Looking for j less than Pivot
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Given array: ");
    printArray(arr, n);

    // Timing starts
    clock_t start = clock();

    quickSort(arr, 0, n - 1);

    // Timing ends
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    printArray(arr, n);

    printf("Time taken to sort %d elements = %.6f seconds\n", n, time_taken);

    return 0;
}
