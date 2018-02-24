#include <stdio.h>
#include <math.h>

int main(){
    char n[10];
    int x, i, j, k;
    printf("Enter a three-digit nonnegative number: ");
    scanf("%s", &n);
    
    x = 0;
    for(i = 2; i >= 0; i--){
        k = 1;
        for(j = 2; j > i; j--, k *= 10);
        x += (n[i] - 48) * k;
    }

    printf("The number is %d\n", x);
    return 0;
}