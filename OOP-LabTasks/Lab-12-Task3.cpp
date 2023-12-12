#include <stdio.h>

int main() {
    int cakesSoldPerDay[] = {20, 15, 25, 10, 18, 12};
    int *p = cakesSoldPerDay;
    int totalCakesSoldPerWeek = 0;
    for (int i = 0; i < 6; i++) {
        totalCakesSoldPerWeek = totalCakesSoldPerWeek + *(p + i);
    }
    totalCakesSoldPerWeek =totalCakesSoldPerWeek*7;
    printf("The total number of cakes sold per week is %d.\n", totalCakesSoldPerWeek);
    return 0;
}