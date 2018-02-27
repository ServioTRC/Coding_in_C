#include <stdio.h>
#include <string.h>

int main(){
    char input[80], output[80];
    printf("Enter a string: ");
    scanf("%s", &input);
    int i, j = 0;
    for(i = 0; i < strlen(input); i++){
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
            continue;
        else{
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';
    printf("%s\n", output);
    return 0;
}