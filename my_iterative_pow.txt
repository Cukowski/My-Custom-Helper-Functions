#include <stdio.h>

int my_iterative_pow(int param_1, int param_2)
{
    int pow = 1;

    if (param_2 == 0)
        return pow;

    for (int i = 0; i < param_2; i++) {
        pow = pow * param_1;
    }
    return pow;
}
