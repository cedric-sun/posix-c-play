#include <stdio.h>

// "Overflow detection" is not good enough, since if overflow happends, we are
// already having UB. Correct speak is to avoid or prevent.
//
// for manually avoid such overflow rather than using compiler builtins, see:
// https://stackoverflow.com/questions/55468823/how-to-detect-integer-overflow-in-c
int main() {
    int a = 0x7ffffffe;
    int b = 2;
    int result = 42;
    if (__builtin_sadd_overflow(a, b, &result)) {
        printf("%d + %d signed overflows!\n", a, b);
        printf("result = %d\n", result);
        if (result != 42) {
            puts("result is modified.");
        }
    }
    return 0;
}
