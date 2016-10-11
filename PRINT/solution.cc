#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef unsigned int uint;

int main(void) {
    uint nTests;
    scanf("%d\n", &nTests);
    for (uint test = 0; test < nTests; ++test) {
        size_t lowerBound, upperBound;
        scanf("%zu %zu\n", &lowerBound, &upperBound);

        uint *sieve = (uint*)calloc(upperBound - lowerBound + 1, sizeof(uint));

        for (size_t i = 2; i < (size_t)sqrt(upperBound) + 1; ++i) {
            size_t j = i * i < lowerBound / i * i
                ? lowerBound / i * i
                : i * i;
            for (; j <= upperBound; j += i) {
                if (j >= lowerBound) {
                    sieve[j - lowerBound] = 1;
                }
            }
        }

        for (size_t i = 0; i <= upperBound - lowerBound; ++i) {
            if (!sieve[i]) {
                printf("%zu\n", i + lowerBound);
            }
        }

        free(sieve);
    }

    return 0;
}
