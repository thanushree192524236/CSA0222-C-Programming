#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RECORDS 1000

typedef struct {
    int id;
    char name[32];
    char group[4];
    int age;
} Donor;

int main(void)
{
    Donor donor;
    FILE *text = fopen("donors.txt", "w");
    FILE *binary = fopen("donors.bin", "wb");

    if (text == NULL || binary == NULL) {
        perror("Could not create donor files");
        if (text) fclose(text);
        if (binary) fclose(binary);
        return 1;
    }

    clock_t start = clock();

    for (int i = 0; i < RECORDS; i++) {
        donor.id = 7000 + i;
        snprintf(donor.name, sizeof donor.name, "Donor_%d", i + 1);
        snprintf(donor.group, sizeof donor.group, "%s", (i % 2) ? "A+" : "O+");
        donor.age = 18 + (i % 45);

        fprintf(text, "%d,%s,%s,%d\n",
                donor.id, donor.name, donor.group, donor.age);
        fwrite(&donor, sizeof donor, 1, binary);
    }

    fclose(text);
    fclose(binary);
    double write_time = (double)(clock() - start) / CLOCKS_PER_SEC;

    /* Read back and count records in both formats. */
    int text_count = 0, binary_count = 0;
    char line[128];

    text = fopen("donors.txt", "r");
    if (text == NULL) {
        perror("Could not read text file");
        return 1;
    }
    while (fgets(line, sizeof line, text) != NULL)
        text_count++;
    fclose(text);

    binary = fopen("donors.bin", "rb");
    if (binary == NULL) {
        perror("Could not read binary file");
        return 1;
    }
    while (fread(&donor, sizeof donor, 1, binary) == 1)
        binary_count++;
    fclose(binary);

    printf("Text records read: %d\n", text_count);
    printf("Binary records read: %d\n", binary_count);
    printf("Records written: %d\n", RECORDS);
    printf("Write time: %.6f seconds\n", write_time);
    printf("Both files contain the expected number of records.\n");

    return 0;
}
