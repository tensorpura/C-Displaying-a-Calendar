#include <iostream>
using namespace std;

/* Declare function GetWeekDay to determine the day of the week for a given date */
int GetWeekDay(int, int, int);

/* Declare function KnowMonthDays to find out the number of days in a given month of a given year */
int KnowMonthDays(int, int);

/* Declare function CheckLeap to check if a given year is a leap year */
int CheckLeap(int);

/* Declare function PrintMonthCalender to print the calendar of a given month */
int PrintMonthCalender(int, int);

main()
{
    /* Define variables, startDay for the weekday of the first day of the month,
    * days for the number of days in the month
    */
    int year, month, startDay, days;
    printf("input the year and month(YYYY-MM):");
    scanf("%d-%d", &year, &month);
    printf("\n\t\t\t%d-%d\n", year, month);

    /* Use function GetWeekDay to find the weekday of the first day of the month */
    startDay = GetWeekDay(year, month, 1);

    /* Use function KnowMonthDays to find out the number of days in the month */
    days = KnowMonthDays(year, month);
    PrintMonthCalender(startDay, days);
    return(0);
}

/* Define function GetWeekDay to determine the day of the week for a given date */
int GetWeekDay(int year, int month, int day)
{
    /* Define variables, days is the number of days since January 1, 0001,
    * weekday is the day of the week, i is a variable to control the month
    */
    int days, weekday, i;
    days = year * 365 + year / 400 + year / 4 - year / 100;

    /* Calculate the total days until the month since January 1, 0001 */
    for (i = 12; i >= month; i--)
        days = days - KnowMonthDays(year, i);

    /* Calculate the total days until the date since January 1, 0001 */
    days = days + day;

    /* Calculate the weekday for the date */
    weekday = days % 7;
    return weekday;
}

/* Define function KnowMonthDays to find out the number of days in a given month of a given year */
int KnowMonthDays(int year, int month)
{
    /* Discuss months with different number of days separately */
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
    {
        /* Separate discussion for February */
        if (month == 2)
        {
            /* Check for a leap year */
            if (CheckLeap(year))
                return 29;
            else
                return 28;
        }
        else
            return 31;
    }
}

/* Define function PrintMonthCalender to print the calendar of a given month */
int PrintMonthCalender(int startDay, int days)
{
    int num, count;
    num = -startDay;
    printf("\nSun.\tMon.\tTue.\tWed.\tThu.\tFri.\tSat.\n");

    /* Control the number of days to output */
    while (num <= days)
    {
        printf("\n");

        /* Control for seven days a week */
        for (count = 1; count <= 7; count++)
        {
            num = num + 1;

            /* Control the number of days to output */
            if (num >= 1 && num <= days)
                printf("%d\t", num);
            else
                printf("\t");
        }
    }
    printf("\n");
}

/* Define function CheckLeap to check if a given year is a leap year */
int CheckLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}
