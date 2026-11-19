#include <stdio.h>

#define SIZE 8

void print_array(const int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    putchar('\n');
}

void bubble_sort(int a[], int n) {
    int comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int changed = 0;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (a[j] > a[j + 1]) {
                int temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
                swaps++; changed = 1;
            }
        }
        if (!changed) break; /* Already in order. */
    }
    printf("Bubble sort: comparisons = %d, swaps = %d\n", comparisons, swaps);
}

void selection_sort(int a[], int n) {
    int comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (a[j] < a[smallest]) smallest = j;
        }
        if (smallest != i) {
            int temp = a[i]; a[i] = a[smallest]; a[smallest] = temp;
            swaps++;
        }
    }
    printf("Selection sort: comparisons = %d, swaps = %d\n", comparisons, swaps);
}

void insertion_sort(int a[], int n) {
    int comparisons = 0, shifts = 0;
    for (int i = 1; i < n; i++) {
        int current = a[i], j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (a[j] <= current) break;
            a[j + 1] = a[j];
            shifts++; j--;
        }
        a[j + 1] = current;
    }
    printf("Insertion sort: comparisons = %d, shifts = %d\n", comparisons, shifts);
}

int main(void) {
    int original[SIZE] = {42, 18, 35, 12, 29, 8, 50, 24};
    int a[SIZE];
    puts("EXAM SEATING REGISTER - SORTING");
    printf("Original: "); print_array(original, SIZE);

    for (int i = 0; i < SIZE; i++) a[i] = original[i];
    bubble_sort(a, SIZE); printf("Result: "); print_array(a, SIZE);

    for (int i = 0; i < SIZE; i++) a[i] = original[i];
    selection_sort(a, SIZE); printf("Result: "); print_array(a, SIZE);

    for (int i = 0; i < SIZE; i++) a[i] = original[i];
    insertion_sort(a, SIZE); printf("Result: "); print_array(a, SIZE);
    return 0;
}
