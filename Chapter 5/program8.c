#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define length(x) (sizeof(x)/sizeof(*x))

void word_size(char *str, int *nums){
    int i, in = 0, size;
    for(i = 0; i < strlen(str); i++){
        if(str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '\n' || str[i] == '\t' || str[i] == ':'){
            size = i-in;
            if(size >= 3 && size <= 15){
                nums[size]++;
            }
            in = i+1;
        }
    }
}

void print_res(int *nums){
    int i;
    printf("Word size\tQuantity\n");
    for(i = 3; i < 16; i++){
        printf("%d:\t\t%d\n", i, nums[i]);
    }
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

    int nums[16];
    int i;
    for(i = 0; i < 16; i++)
        nums[i] = 0;

    char * line = malloc(300);
    size_t len = 0;

    while ((fgets(line, 300, input)) != NULL) {
        word_size(line, &nums);
    }

    print_res(&nums);

    fclose(input);
    free(line);

    return 0;
}