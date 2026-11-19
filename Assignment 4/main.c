#include <stdio.h>

int next_token(void);
int auto_token(void);
int external_token(void);

int main(void) {
    int s1 = next_token(), s2 = next_token(), s3 = next_token();
    int a1 = auto_token(), a2 = auto_token(), a3 = auto_token();
    int e1 = external_token(), e2 = external_token(), e3 = external_token();

    printf("static: %d %d %d\n", s1, s2, s3);
    printf("auto  : %d %d %d\n", a1, a2, a3);
    printf("extern: %d %d %d\n", e1, e2, e3);

    printf("register loop: ");
    for (register int i = 1; i <= 3; i++)
        printf("%d ", i);
    printf("\n");

    return 0;
}

int auto_token(void) {
    int token = 1000;
    return ++token;
}
