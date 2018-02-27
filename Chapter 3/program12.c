#include <stdio.h>
#include <string.h>
#define true 1
#define false 0

int main(){
    char input[300], output[300];
    printf("Enter the filename: ");
    scanf("%s", &input);
    int i, j = 0, suffix = false;
    for(i = 0; i < strlen(input); i++){
        if(suffix){
            output[j] = input[i];
            j++;
        } else if(input[i] == '.')
            suffix = true;
    }
    output[j] = '\0';
    printf("%s\n", output);
    return 0;
}