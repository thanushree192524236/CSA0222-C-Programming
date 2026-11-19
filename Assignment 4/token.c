/* This file contains the shared counter used by main.c. */
static int token = 1000;
extern int shared_token;

int next_token(void) {
    return ++token;
}

int external_token(void) {
    return ++shared_token;
}
