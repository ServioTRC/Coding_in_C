#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char buffer[200] = "";
int index = 0;

void cprintf(char *s){
    int i;
    for(i = 0; i < strlen(s); i++){
        if(s[i] != '%'){
            buffer[index] = s[i];
            index++;
        } else {
            printf("%s", buffer);
            memset(buffer, '\0', sizeof(buffer));
            index = 0;
        }
    }
}

void flush_rest(){
    if(index != 0){
        printf("%s", buffer);
        memset(buffer, '\0', sizeof(buffer));
        index = 0;
    }
}

int main(){
    cprintf("Test\n");
    sleep(1);
    cprintf("Re%Test\n");
    sleep(1);
    cprintf("All done \n%");
    cprintf("hihihi");
    flush_rest();
    return 0;
}