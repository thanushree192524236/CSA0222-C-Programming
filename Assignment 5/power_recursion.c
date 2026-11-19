#include <stdio.h>

/* Counts how many times each power function is called. */
long long calls = 0;

/* Simple recursive power: one call for every step. */
long long power_linear(long long base, int exp)
{
    calls++;

    if (exp == 0)
        return 1;

    return base * power_linear(base, exp - 1);
}

/* Faster recursive power: divide the exponent by two each time. */
long long power_fast(long long base, int exp)
{
    calls++;

    if (exp == 0)
        return 1;

    long long half = power_fast(base, exp / 2);
    long long result = half * half;

    if (exp % 2 != 0)
        result *= base;

    return result;
}

/* Digital root using recursion. */
int digital_root(int number)
{
    if (number < 10)
        return number;

    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    return digital_root(sum);
}

int main(void)
{
    calls = 0;
    long long a = power_linear(2, 30);
    printf("linear: %lld in %lld calls\n", a, calls);

    calls = 0;
    long long b = power_fast(2, 30);
    printf("fast : %lld in %lld calls\n", b, calls);

    printf("digital root of 9875: %d\n", digital_root(9875));
    return 0;
}
