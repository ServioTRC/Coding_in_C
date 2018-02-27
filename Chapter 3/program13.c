#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    int i, j;
    for(i = 0; i < argc; i++){
        for(j = i+1; j < argc; j++){
            if(strcmp(argv[i], argv[j]) == 0){
                printf("%s pos1 %d and pos2 %d\n", argv[i], i, j);
            }
        }
    }
    return 0;
}