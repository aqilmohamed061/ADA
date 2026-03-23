#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *b = *a;
    *a = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // swap arr[i+1] and arr[high]
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Seed for random numbers
    srand(time(0));

    // Generate random numbers
    printf("Generated array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // numbers between 0–99
        printf("%d ", arr[i]);
    }

    // Sort the array
    quickSort(arr, 0, n - 1);

    // Display sorted array
    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
