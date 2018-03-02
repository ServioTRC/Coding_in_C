#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact{
    char name[30];
    char address[30];
    char telephone[7];
};

int main(){
    struct contact data1;
    strcpy(data1.name, "John");
    strcpy(data1.address, "New York");
    strcpy(data1.telephone, "1234567");
    printf("%s\n%s\n%s\n", data1.name, data1.address, data1.telephone);
    return 0;
}