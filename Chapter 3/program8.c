#include <stdio.h>
#include <string.h>

int main(){
    char input[30], temp;
    printf("Enter a string no bigger than 30 chars: ");
    scanf("%s", input);
    printf("%s\n", input);
    int i, j;
    for(i = 0; i < strlen(input); i++){
        for(j = 0; j < strlen(input)-1; j++){
            if(input[j] > input[j+1]){
                temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }        
    }
    printf("%s\n", input);
}