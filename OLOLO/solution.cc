#include <stdio.h>

typedef unsigned int uint;

int main(void) {
    uint nNumbers;
    scanf("%d\n", &nNumbers);

    uint result = 0;
    for (uint i = 0; i < nNumbers; ++i) {
        uint number;
        scanf("%d\n", &number);

        result ^= number;
    }

    printf("%d\n", result);

    return 0;
}
