#include <stdio.h>
#include <string.h>

int main(){
    char input[11];
    int i, num = 0;
    printf("Enter the number to compute: ");
    scanf("%s", &input);
    i = 0;
    while(input[i] != '\0'){
        num += (((int) input[i]) - 48);
        i++;
    }
    printf("Adding result: %d\n", num);
    return 0;
}