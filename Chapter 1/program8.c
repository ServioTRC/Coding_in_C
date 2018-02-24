#include <stdio.h>
#include <math.h>

int main(){
    int num;
    float partial, temp;
    printf("Enter number for the closest number square root: ");
    scanf("%d", &num);
    partial = pow(num, 0.5);
    num = (int) partial;
    temp = fmod(partial, 1.0);
    if(temp >= 0.5)
        num++;
    printf("Closest root: %d\n", (int) pow(num, 2));
    return(0);
}