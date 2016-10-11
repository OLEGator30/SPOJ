#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef unsigned int uint;

int main(void) {
    uint nTests;
    scanf("%d\n", &nTests);
    for (uint test = 0; test < nTests; ++test) {
        uint lowerBound, upperBound;
        scanf("%d %d\n", &lowerBound, &upperBound);

        bool *sieve = (bool*)calloc(upperBound - lowerBound + 1, sizeof(bool));
        if (lowerBound == 1) {
            sieve[0] = true;
        }

        for (uint i = 2; i < (int)sqrt(upperBound) + 1; ++i) {
            uint j = i * i < lowerBound / i * i
                ? lowerBound / i * i
                : i * i;
            for (; j <= upperBound; j += i) {
                sieve[j - lowerBound] = true;
            }
        }

        for (uint i = 0; i <= upperBound - lowerBound; ++i) {
            if (!sieve[i]) {
                printf("%d\n", i + lowerBound);
            }
        }
        printf("\n");
    }

    return 0;
}
