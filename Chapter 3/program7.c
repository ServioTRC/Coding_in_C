#include <stdio.h>
#include <string.h>
#define true 1
#define false 0


int main(){
    char name[50], first[25], last[25];
    printf("What is your name? ");
    scanf("%s", &name);
    int i, j, upper = false, end = false;
    first[0] = name[0];
    i = 1;

    while(true){
        if(name[i] >= 65 && name[i] <= 90)
            break;
        first[i] = name[i];
        i++;
    }
    first[i] = '\0';
    j = 0;

    while(i < strlen(name)){
        last[j] = name[i];
        i++;
        j++;
    }
    last[j] = '\0';

    printf("%s %s", first, last);

    return 0;
}