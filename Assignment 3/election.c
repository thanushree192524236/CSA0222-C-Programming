#include <stdio.h>

#define CANDIDATES 5
#define VOTE_COUNT 15

int main(void) {
    /* Each number represents one vote for that candidate. */
    int votes[VOTE_COUNT] = {1, 2, 3, 1, 5, 2, 1, 4, 3, 2, 0, 6, -1, 5, 4};
    int count[CANDIDATES + 1] = {0};
    int valid = 0, invalid = 0, highest = 0, winner = 0, tie = 0;

    for (int i = 0; i < VOTE_COUNT; i++) {
        if (votes[i] >= 1 && votes[i] <= CANDIDATES) {
            count[votes[i]]++;
            valid++;
        } else {
            invalid++;
        }
    }

    /* Find the largest vote count and check whether it is shared. */
    for (int i = 1; i <= CANDIDATES; i++) {
        if (count[i] > highest) {
            highest = count[i];
            winner = i;
            tie = 0;
        } else if (count[i] == highest && highest > 0) {
            tie = 1;
        }
    }

    puts("STUDENT COUNCIL ELECTION RESULT");
    printf("Valid votes: %d\nInvalid votes: %d\n", valid, invalid);
    puts("Votes per candidate (highest first):");
    for (int printed = 0; printed < CANDIDATES; printed++) {
        int best = -1;
        for (int c = 1; c <= CANDIDATES; c++) {
            if (count[c] >= 0 && (best == -1 || count[c] > count[best])) best = c;
        }
        if (best != -1) {
            printf("Candidate %d: %d\n", best, count[best]);
            count[best] = -1; /* Mark this candidate as printed. */
        }
    }
    if (tie) printf("Result: Tie at %d votes\n", highest);
    else printf("Winner: Candidate %d with %d votes\n", winner, highest);
    return 0;
}
