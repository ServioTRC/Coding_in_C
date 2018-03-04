#include <stdio.h>
#include <string.h>

struct inventory {
    char name[30];
    int count;
    float price;
} log[75];

int main(){
    FILE *file;
    struct inventory in1;
    strcpy(in1.name, "John");
    in1.count = 1;
    in1.price = 3.9;
    file = fopen("exit.txt", "w");
    fprintf(file, "name: %s, count: %d, price %f\n", in1.name, in1.count, in1.price);
    fclose(file);
    return 0;
}