static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day; pointer version */
int day_of_year(int year, int month, int day)
{
    int leap;
    char *p, *p0;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = *(daytab + leap); // pointer to the correct row
    p0 = p; // save initial address of the row
    p++; // skip column with value 0
    for( ; p - p0 < month; p++)
        day += *p;
    return day;
}

/* month_day: set month, day from day of year; pointer version */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    char *p, *p0;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = *(daytab + leap); // pointer to the correct row
    p0 = p; // save initial address of the row
    p++; // skip column with value 0
    for( ; yearday > *p; p++)
        yearday -= *p;
    *pmonth = p - p0;
    *pday = yearday;
}
