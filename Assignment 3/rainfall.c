#include <stdio.h>

#define DISTRICTS 38
#define MONTHS 12

int main(void) {
    /* Sample rainfall values in mm. The same layout can hold entered data. */
    int rain[DISTRICTS][MONTHS];
    int annual[DISTRICTS] = {0};
    int monthly_total[MONTHS] = {0};
    int grand_total = 0, wettest = 0, wet_district = 0, wet_month = 0;

    /* Create easy-to-test sample values for all 38 districts and 12 months. */
    for (int i = 0; i < DISTRICTS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            rain[i][j] = 40 + (i * 7 + j * 11) % 160;
        }
    }

    for (int i = 0; i < DISTRICTS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            annual[i] += rain[i][j];
            monthly_total[j] += rain[i][j];
            grand_total += rain[i][j];
            if (rain[i][j] > wettest) {
                wettest = rain[i][j];
                wet_district = i + 1;
                wet_month = j + 1;
            }
        }
    }

    double state_average = (double)grand_total / (DISTRICTS * MONTHS);
    puts("DISTRICT RAINFALL SUMMARY");
    printf("State monthly average: %.2f mm\n", state_average);
    printf("Wettest record: District %d, Month %d = %d mm\n", wet_district, wet_month, wettest);
    printf("Annual totals for first 5 districts:\n");
    for (int i = 0; i < 5; i++) printf("District %d: %d mm\n", i + 1, annual[i]);

    printf("Districts below 60%% of state average (annual total check):\n");
    for (int i = 0; i < DISTRICTS; i++) {
        if (annual[i] < 0.60 * state_average * MONTHS)
            printf("District %d ", i + 1);
    }
    putchar('\n');
    return 0;
}
