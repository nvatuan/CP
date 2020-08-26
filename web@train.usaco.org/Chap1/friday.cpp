/*
ID: nvatuan2
TASK: friday
LANG: C++                 
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

bool leap(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int N;

int day = 0;
int month = 0;
int weekday = 0;
int year = 1900;

int fullmonth[] = {1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};
// MON = 0, TUE = 1, ... FRI = 4, ..

int ans[7];

void next_day() {
    int lastday = 0;
    if(month == 1) { // Feb
        lastday = 28 + leap(year);
    } else {
        lastday = 30 + fullmonth[month];
    }
    // --
    weekday = (weekday + 1) % 7;
    day++; 
    assert(day <= lastday);
    if(day == lastday) {
        day = 0;
        month++;
    }
    if(month == 12) {
        month = 0;
        year++;
    }
    // --
    ans[weekday] += (day == 12);
}

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    //
    scanf("%d", &N);
    while(year - 1900 < N) {
        next_day();
    }
    //
    for(int i = 5; i < 5+7; i++) {
        if(i < 5+6) printf("%d ", ans[i%7]);
        else printf("%d\n", ans[i%7]);
    }
}