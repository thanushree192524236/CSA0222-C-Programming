#include <stdio.h>
#include <string.h>

#define MAX_NAMES 8
#define NAME_LENGTH 30

int main(void) {
    char names[MAX_NAMES][NAME_LENGTH] = {
        "Meena", "Arun", "Kavya", "Bala", "Arun", "Divya", "Hari", "Charan"
    };
    char search_name[NAME_LENGTH] = "Arun";
    char temp[NAME_LENGTH];
    int comparisons = 0;

    /* Simple bubble sort keeps the names in alphabetical order. */
    for (int i = 0; i < MAX_NAMES - 1; i++) {
        for (int j = 0; j < MAX_NAMES - i - 1; j++) {
            comparisons++;
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    puts("HOSTEL RESIDENT DIRECTORY");
    printf("Sorted names: ");
    for (int i = 0; i < MAX_NAMES; i++) printf("%s ", names[i]);
    printf("\nString comparisons during sort: %d\n", comparisons);

    /* Find the first matching name with binary search. */
    int low = 0, high = MAX_NAMES - 1, found = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int result = strcmp(names[mid], search_name);
        if (result == 0) { found = mid; break; }
        if (result < 0) low = mid + 1;
        else high = mid - 1;
    }
    if (found >= 0) printf("%s found at index %d\n", search_name, found);
    else printf("%s not found\n", search_name);

    puts("Duplicate names:");
    for (int i = 1; i < MAX_NAMES; i++) {
        if (strcmp(names[i], names[i - 1]) == 0) printf("%s\n", names[i]);
    }
    return 0;
}
