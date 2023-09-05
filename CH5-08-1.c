#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day; return -1 if an error occurs */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if(month <= 0 || month > 12)
    {
        printf("error - wrong number of month: %d\n", month);
        return -1;
    }
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if(day <= 0 || day > daytab[leap][month])
    {
        printf("error - for the given year and month there is no day: %d\n", day);
        return -1;
    }
    for(i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year; return -1 if an error occurs */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if(yearday <= 0 || yearday > 365 + leap)
    {
        printf("error - in the given year there is no day no. %d\n", yearday);
        return -1;
    }
    for(i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
    return 0;
}
