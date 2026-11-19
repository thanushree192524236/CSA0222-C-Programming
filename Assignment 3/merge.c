#include <stdio.h>

/* Combine two descending merit lists without sorting them again. */
int merge(const int a[], int na, const int b[], int nb, int out[]) {
    int i = 0, j = 0, k = 0;

    while (i < na && j < nb) {
        if (a[i] >= b[j]) out[k++] = a[i++];
        else out[k++] = b[j++];
    }
    while (i < na) out[k++] = a[i++];
    while (j < nb) out[k++] = b[j++];
    return k;
}

int main(void) {
    int campus_a[] = {98, 91, 85, 72};
    int campus_b[] = {95, 91, 80};
    int result[7];
    int count = merge(campus_a, 4, campus_b, 3, result);

    puts("COMBINED CAMPUS MERIT LIST");
    for (int i = 0; i < count; i++) printf("%d ", result[i]);
    putchar('\n');
    return 0;
}
