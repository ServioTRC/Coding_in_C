#include <stdio.h>
#include <string.h>
#define true 1
#define false 0

void search_word(char *search, char *input){
    int i, found = true;
    for(i = 0; i < strlen(search); i++){
        if(search[i] != input[i]){
            found = false;
            break;
        }            
    }
    if(found)
        printf("%s\n", input);
}

int main(int argc, char *argv[]){
    FILE *input;
    
    if(argc != 2){
        printf("Invalid number of arguments\n");
        return -1;
    }

    input = fopen(argv[1], "r");
    if(input == NULL){
        printf("Problem opening the file\n");
        return -1;
    }

    char search[100];
    printf("Enter the word to search: ");
    scanf("%s", search);
    char word[100];
    while (fscanf(input, " %99s", word) == 1) {
        search_word(search, word);
    }
    fclose(input);
    return 0;
}