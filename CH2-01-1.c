#define __USE_MINGW_ANSI_STDIO 1 // for long double type
// #define printf __mingw_printf // alternatively

#include <stdio.h>
#include <limits.h>
#include <float.h>

/* determine the ranges of the various fixed-point and floating-point types */
int main()
{
    // CHAR
    signed char x = 0, x_prev = 0, x_min, x_max;

    while(x <= x_prev)
    {
        x_prev = x;
        --x;
    }
    x_min = x_prev;

    x = x_prev = 0;
    while(x >= x_prev)
    {
        x_prev = x;
        ++x;
    }
    x_max = x_prev;

    printf("Range of signed char variable\n");
    printf("symbolic constants: [%d, %d];\n", SCHAR_MIN, SCHAR_MAX);
    printf("computation:        [%d, %d].\n\n", x_min, x_max);

    unsigned char x1 = 0, x1_prev = 0, x1_min, x1_max;

    while(x1 <= x1_prev)
    {
        x1_prev = x1;
        --x1;
    }
    x1_min = x1_prev;

    x1 = x1_prev = 0;
    while(x1 >= x1_prev)
    {
        x1_prev = x1;
        ++x1;
    }
    x1_max = x1_prev;

    printf("Range of unsigned char variable\n");
    printf("symbolic constants: [%u, %u];\n", 0, UCHAR_MAX);
    printf("computation:        [%u, %u].\n\n", x1_min, x1_max);


    // SHORT
    signed short x2 = 0, x2_prev = 0, x2_min, x2_max;

    while(x2 <= x2_prev)
    {
        x2_prev = x2;
        --x2;
    }
    x2_min = x2_prev;

    x2 = x2_prev = 0;
    while(x2 >= x2_prev)
    {
        x2_prev = x2;
        ++x2;
    }
    x2_max = x2_prev;

    printf("Range of signed short variable\n");
    printf("symbolic constants: [%hd, %hd];\n", SHRT_MIN, SHRT_MAX);
    printf("computation:        [%hd, %hd].\n\n", x2_min, x2_max);

    unsigned short x3 = 0, x3_prev = 0, x3_min, x3_max;

    while(x3 <= x3_prev)
    {
        x3_prev = x3;
        --x3;
    }
    x3_min = x3_prev;

    x3 = x3_prev = 0;
    while(x3 >= x3_prev)
    {
        x3_prev = x3;
        ++x3;
    }
    x3_max = x3_prev;

    printf("Range of unsigned short variable\n");
    printf("symbolic constants: [%hu, %hu];\n", 0, USHRT_MAX);
    printf("computation:        [%hu, %hu].\n\n", x3_min, x3_max);


    // INT
    signed int x4 = 0, x4_prev = 0, x4_min, x4_max;

    while(x4 <= x4_prev)
    {
        x4_prev = x4;
        --x4;
    }
    x4_min = x4_prev;

    x4 = x4_prev = 0;
    while(x4 >= x4_prev)
    {
        x4_prev = x4;
        ++x4;
    }
    x4_max = x4_prev;

    printf("Range of signed int variable\n");
    printf("symbolic constants: [%d, %d];\n", INT_MIN, INT_MAX);
    printf("computation:        [%d, %d].\n\n", x4_min, x4_max);

    unsigned int x5 = 0, x5_prev = 0, x5_min, x5_max;

    while(x5 <= x5_prev)
    {
        x5_prev = x5;
        --x5;
    }
    x5_min = x5_prev;

    x5 = x5_prev = 0;
    while(x5 >= x5_prev)
    {
        x5_prev = x5;
        ++x5;
    }
    x5_max = x5_prev;

    printf("Range of unsigned int variable\n");
    printf("symbolic constants: [%u, %u];\n", 0, UINT_MAX);
    printf("computation:        [%u, %u].\n\n", x5_min, x5_max);

    // LONG
    signed long x6 = 0, x6_prev = 0, x6_min, x6_max;

    while(x6 <= x6_prev)
    {
        x6_prev = x6;
        --x6;
    }
    x6_min = x6_prev;

    x6 = x6_prev = 0;
    while(x6 >= x6_prev)
    {
        x6_prev = x6;
        ++x6;
    }
    x6_max = x6_prev;

    printf("Range of signed long variable\n");
    printf("symbolic constants: [%ld, %ld];\n", LONG_MIN, LONG_MAX);
    printf("computation:        [%ld, %ld].\n\n", x6_min, x6_max);

    unsigned long x7 = 0, x7_prev = 0, x7_min, x7_max;

    while(x7 <= x7_prev)
    {
        x7_prev = x7;
        --x7;
    }
    x7_min = x7_prev;

    x7 = x7_prev = 0;
    while(x7 >= x7_prev)
    {
        x7_prev = x7;
        ++x7;
    }
    x7_max = x7_prev;

    printf("Range of unsigned long variable\n");
    printf("symbolic constants: [%lu, %lu];\n", 0, ULONG_MAX);
    printf("computation:        [%lu, %lu].\n\n", x7_min, x7_max);


    // FLOAT
    float be, be_prev, z, z_prev, z_max, z_min;
    float base = 2.0;
    float m = 1.0; // integer part of the mantissa
    float k = 0.5; // initial value of the fractional part of the mantissa (it will approaches 1)
    int n = 0; // mantissa bit counter

    //////////////////// calculate of the positive maximum value ////////////////////
    // calculate value b^e
    be = base; // be = -base for negative max
    while(be != (be * 1.1)) // increase the exponent until it leads to an overflow error
    {
        be_prev = be;
        be = be * 2.0;
    }
    be = be_prev;

    // calculate value z = m*(b^e)
    z = be;
    while(z != (z * 1.1)) // increase the value of the number until it leads to an overflow error
    {
        m = m + k; // increase the accuracy of the approximation of the number 2 by the mantissa
        k = k/2.0;
        z_prev = z;
        z = m*be;
        ++n;
    }
    n = n - 1; // the penultimate modification k led to an overflow error
    z_max = z_prev;

    //////////////////// calculate of the positive minimum value ////////////////////
    m = 1.0; // minimum possible value of the mantissa
    be = base; // be = -base for a negative min
    while(be != 0) // decrease exponent until it leads to an underflow error
    {
        be_prev = be;
        be = be/2.0;
    }
    be = be_prev; // non-normalised number

    z_min = m*be;
    for( ; n > 0; --n)
        z_min = z_min * 2.0; // correct by n bits of mantissa that the normalised number cannot use

    printf("Range of float variable\n");
    printf("symbolic constants: [%e, %e] U {0} U [%e, %e];\n", -FLT_MAX, -FLT_MIN, FLT_MIN, FLT_MAX);
    printf("computation:        [%e, %e] U {0} U [%e, %e].\n", -z_max, -z_min, z_min, z_max);
    printf("logical results of the comparisons of positive min values: %d and max: %d\n\n", z_min == FLT_MIN, z_max == FLT_MAX);


    // DOUBLE
    double be1, be1_prev, z1, z1_prev, z1_max, z1_min;
    double base1 = 2.0;
    double m1 = 1.0; // integer part of the mantissa
    double k1 = 0.5; // initial value of the fractional part of the mantissa (it will approaches 1)
    int n1 = 0; // mantissa bit counter

    //////////////////// calculate of the positive maximum value ////////////////////
    // calculate value b^e
    be1 = base1; // be1 = -base1 for negative max
    while(be1 != (be1 * 1.1)) // increase the exponent until it leads to an overflow error
    {
        be1_prev = be1;
        be1 = be1 * 2.0;
    }
    be1 = be1_prev;

    // calculate value z = m*(b^e)
    z1 = be1;
    while(z1 != (z1 * 1.1)) // increase the value of the number until it leads to an overflow error
    {
        m1 = m1 + k1; // increase the accuracy of the approximation of the number 2 by the mantissa
        k1 = k1/2.0;
        z1_prev = z1;
        z1 = m1*be1;
        ++n1;
    }
    n1 = n1 - 1; // the penultimate modification k1 led to an overflow error
    z1_max = z1_prev;

    //////////////////// calculate of the positive minimum value ////////////////////
    m1 = 1.0; // minimum possible value of the mantissa
    be1 = base1; // be1 = -base1 for a negative min
    while(be1 != 0) // decrease exponent until it leads to an underflow error
    {
        be1_prev = be1;
        be1 = be1/2.0;
    }
    be1 = be1_prev; // non-normalised number

    z1_min = m1*be1;
    for( ; n1 > 0; --n1)
        z1_min = z1_min * 2.0; // correct by n1 bits of mantissa that the normalised number cannot use

    printf("Range of double variable\n");
    printf("symbolic constants: [%e, %e] U {0} U [%e, %e];\n", -DBL_MAX, -DBL_MIN, DBL_MIN, DBL_MAX);
    printf("computation:        [%e, %e] U {0} U [%e, %e].\n", -z1_max, -z1_min, z1_min, z1_max);
    printf("logical results of the comparisons of positive min values: %d and max: %d\n\n", z1_min == DBL_MIN, z1_max == DBL_MAX);


    // LONG DOUBLE
    long double be2, be2_prev, z2, z2_prev, z2_max, z2_min;
    long double base2 = 2.0;
    long double m2 = 1.0; // integer part of the mantissa
    long double k2 = 0.5; // initial value of the fractional part of the mantissa (it will approaches 1)
    int n2 = 0; // mantissa bit counter

    //////////////////// calculate of the positive maximum value ////////////////////
    // calculate value b^e
    be2 = base2; // be2 = -base2 for negative max
    while(be2 != (be2 * 1.1)) // increase the exponent until it leads to an overflow error
    {
        be2_prev = be2;
        be2 = be2 * 2.0;
    }
    be2 = be2_prev;

    // calculate value z = m*(b^e)
    z2 = be2;
    while(z2 != (z2 * 1.1)) // increase the value of the number until it leads to an overflow error
    {
        m2 = m2 + k2; // increase the accuracy of the approximation of the number 2 by the mantissa
        k2 = k2/2.0;
        z2_prev = z2;
        z2 = m2*be2;
        ++n2;
    }
    n2 = n2 - 1; // the penultimate modification k2 led to an overflow error
    z2_max = z2_prev;

    //////////////////// calculate of the positive minimum value ////////////////////
    m2 = 1.0; // minimum possible value of the mantissa
    be2 = base2; //be2 = -base2 for a negative min
    while(be2 != 0) // decrease exponent until it leads to an underflow error
    {
        be2_prev = be2;
        be2 = be2/2.0;
    }
    be2 = be2_prev; // non-normalised number

    z2_min = m2*be2;
    for( ; n2 > 0; --n2)
        z2_min = z2_min * 2.0; // correct by n2 bits of mantissa that the normalised number cannot use

    printf("Range of long double variable\n");
    printf("symbolic constants: [%Le, %Le] U {0} U [%Le, %Le];\n", -LDBL_MAX, -LDBL_MIN, LDBL_MIN, LDBL_MAX);
    printf("computation:        [%Le, %Le] U {0} U [%Le, %Le].\n", -z2_max, -z2_min, z2_min, z2_max);
    printf("logical results of the comparisons of positive min values: %d and max: %d\n\n", z2_min == LDBL_MIN, z2_max == LDBL_MAX);

    return 0;
}

