#include <stdio.h>

float convert(float fahr); // function prototype

/* print Fahrenheit-Celsius table */
/* for fahr = 0, 20, ..., 300; floating-point version with function */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    fahr = lower;
    printf("Fa [deg]\tC [deg]\n");
    while(fahr <= upper)
    {
        celsius = convert(fahr);
        printf("     %3.0f\t %6.1f\n",fahr,celsius);
        fahr = fahr + step;
    }
    return 0;
}

/* convert: convert temperature in degrees Fahrenheit to degrees Celsius */
float convert(float fa)
{
    float ce;

    ce = (5.0/9.0) * (fa - 32.0);

    return ce;
}
