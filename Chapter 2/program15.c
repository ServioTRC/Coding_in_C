#include <stdio.h>
#include <string.h>
#define true 1
#define false 0

void alter_bit(int *num, int pos, int set){
    if(set)
        (*num) = (*num) | (1 << pos);
    else
        (*num) = (*num) & (~(1 << pos));
}

int main(){
    int num = 0, i, val;
    int set;
    char input[300];
    while(true){
        printf("\n\nCurrent value of the int: %d\nAs binary: ", num);
        for(i = 31; i >= 0; i--)
            printf("%d ", (num >> i) & 1);
        printf("\n");

        printf("Enter the function to perform: set, clear, exit\n");
        scanf("%s", &input);
        if(strcmp(input, "exit") == 0)
            break;
        else if(strcmp(input, "set") == 0){
            set = true;
            while(true){
                printf("Enter the bit position to set: ");
                scanf("%d", &val);
                if(val <= 31 && val >= 0){
                    alter_bit(&num, val, set);
                    break;
                } else {
                    printf("Wrong position, please re-try\n");
                }
            }
        }
        else if(strcmp(input, "clear") == 0){
            set = false;
            while(true){
                printf("Enter the bit position to clear: ");
                scanf("%d", &val);
                if(val <= 31 && val >= 0){
                    alter_bit(&num, val, set);
                    break;
                } else {
                    printf("Wrong position, please re-try\n");
                }
            }
        }
        else
            printf("Wrong input please re-try\n");
    }
    return 0;
}