#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc != 6){
        printf("Wrong number of parameters, you enter %d and should be 6\n", argc);
    } else {
        int i;
        for(i = 0; i < 6; i++){
            if(i % 2 == 0){
                printf("%c ", argv[i][0]);
            } else {
                printf("%c ", argv[i][1]);
            }
        }
        printf("\n");
    }
    return 0;
}