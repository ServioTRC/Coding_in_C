#include <stdio.h>

struct rec{
    char name[30];
    double ppg;
    int years;
} team[12];

int main(){
    team[0].ppg=1000;
    printf("%f\n", team[0].ppg);
    return 0;
}