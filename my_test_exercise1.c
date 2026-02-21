# include <stdio.h>
# include <math.h>
# include "include/taylor_sine.h"

int main() {
    // pi
    double pi = 3.14;
    printf("taylor_sine(3.14, 1) = %f\n", taylor_sine(pi, 1));
    printf("taylor_sine(3.14, 4) = %f\n", taylor_sine(pi, 4));
    printf("taylor_sine(3.14, 9) = %f\n", taylor_sine(pi, 9));
    printf("taylor_sine(3.14, 14) = %f\n", taylor_sine(pi, 14));
    printf("sin(pi) = %f\n", sin(3.14));
    return 0;
}