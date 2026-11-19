#include <stdio.h>
#include <string.h>
#include <errno.h>

/* Read a name safely without writing past the array. */
int main(void)
{
    char name[40];

    printf("Enter donor name: ");
    if (fgets(name, sizeof name, stdin) == NULL) {
        printf("No input was received.\n");
        return 1;
    }

    /* Remove the newline if the user pressed Enter. */
    name[strcspn(name, "\n")] = '\0';

    printf("Donor name: %s\n", name);

    /* Demonstrate a file-open error without stopping unexpectedly. */
    FILE *fp = fopen("missing_donor_data.txt", "r");
    if (fp == NULL) {
        perror("Could not open donor data file");
    } else {
        fclose(fp);
    }

    return 0;
}
