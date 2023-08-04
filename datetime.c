#include <stdio.h>
#define sec_in_day 24*60*60
#define sec_in_hour 3600
#define min_in_hour 60
#define sec_in_min 60
typedef struct datetime {
int date; // 1-31
int month; // 1-12
int year; // 1970++
int dayOfWeek; // 0-6
int hour; // 0-23
int minute; // 0-59
int second; // 0-59
} datetime_t;
int isLeapYear(int);
datetime_t createDate(int sec){
    datetime_t mydate;
    int totalday = sec / (sec_in_day);
    mydate.dayOfWeek = (3 + totalday)%7;
    int secleft = sec % (sec_in_day);
    mydate.second = secleft % (sec_in_min);
    secleft /= sec_in_min;
    mydate.minute = secleft % (min_in_hour);
    secleft /= min_in_hour;
    mydate.hour = secleft % (sec_in_hour);
    secleft /= sec_in_hour;
    mydate.year = 1970;
    while (totalday >= 365 + isLeapYear(mydate.year)) {
        totalday -= 365 + isLeapYear(mydate.year);
        mydate.year++;
    }
    int daysInmonth[] = {31,28 + isLeapYear(mydate.year),31,30,31,30,31,31,30,31,30,31};
    mydate.month = 1;
    while (totalday >= daysInmonth[mydate.month-1]){
        totalday -= daysInmonth[mydate.month-1];
        mydate.month++;
    }
    mydate.date = totalday + 1;
    return mydate;
}
void printDate(datetime_t mydate){
    const char *months[] = {
    "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
    "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};
    char *dayinweek[] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    printf("%s %d %s %d %02d:%02d:%02d\n",dayinweek[mydate.dayOfWeek],mydate.date,months[mydate.month-1],mydate.year,
    mydate.hour,mydate.minute,mydate.second);
    
}
int main(void) {
datetime_t inputDate;
int timestamp;
scanf("%d", &timestamp);
inputDate = createDate(timestamp);
printDate(inputDate);
return 0;
}
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}
