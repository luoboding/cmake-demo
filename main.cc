#include <stdio.h>
#include <stdlib.h>

#include "config.h"

#ifdef USE_MYMATH
    #include "math/math.h"
#else
    #include <math.h>
#endif


int main(int argc, char *argv[]) {
    printf(" argc is %d \n", argc);
    printf("Usage: %s base exponent \n", argv[1]);
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    double result = pow(base, exponent);
    printf("%g ^ %d is %g\n", base, exponent, result);
    return 0;
}