#include <stdio.h>
#include <string.h>
#define true 1
#define false 0


void string_to_char(char input[], char *res, int start, int end){
    char temp = 0;
    int i, j = 0;
    for(i = end-1; i >= start; i--, j++){
        if(input[i] == '1')
            temp = temp | (1 << j);
    }
    (*res) = temp;
}

int check_string(char input[]){
    if(strlen(input) != 15)
        return false;
    else {
        for(int i = 0; i < 7; i++){
            if(input[i] == '1' || input[i] == '0')
                continue;
            else
                return false;
        }

        if(input[7] != '+' && input[7] != '-' && input[7] != '*' && input[7] != '/')
            return false;

        for(int i = 8; i < 15; i++){
            if(input[i] == '1' || input[i] == '0')
                continue;
            else
                return false;
        }
        return true;
    }
}

void perform_operation(char a, char b, char ope){
    int res, error = false;
    switch(ope){
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            if(b == 0){
                error = true;
                printf("Division by zero\n");
            }
            else
                res = a / b;
            break;
    }
    if(!error){
        if(res > 127)
            printf("Overflow\n");
        else if(res < -128)
            printf("Underflow\n");
        else{
            printf("Res: ");
            for(int i = 7; i >= 0; i--)
                printf("%d ", (res >> i) & 1);
        }
        printf("\n");
    }
}

int main(){
    char input[300], a, b;
    while(true){
        printf("Enter the BSD operation (7 bits, operator, 7 bits) or exit: ");
        scanf("%s", &input);
        if(strcmp(input, "exit") == 0)
            break;
        else{
            if(check_string(input)){
                string_to_char(input, &a, 0, 7);
                string_to_char(input, &b, 8, 15);
                perform_operation(a, b, input[7]);
            }
            else
                printf("Please re-try your input\n");
        }
    }
    return 0;
}