#include <stdio.h>

int main(){
    char c = 35;
    char d = 'G';
    int x = -42;
    float f = 17.25;
    int j = 1099563008;
    double a = 17.25;
    
    int i;
    printf("Bits usados en c: %d\n", sizeof(c)*8);
    for(i = sizeof(c)*8-1; i >= 0; i--){
        printf("%d ", ((c>>i) & 1));
    }

    printf("\nBits usados en d: %d\n", sizeof(d)*8);
    for(i = sizeof(d)*8-1; i >= 0; i--){
        printf("%d ", ((d>>i) & 1));
    } 

    printf("\nBits usados en x: %d\n", sizeof(x)*8);
    for(i = sizeof(x)*8-1; i >= 0; i--){
        printf("%d ", ((x>>i) & 1));
    }

    printf("\nBits usados en j: %d\n", sizeof(j)*8);
    for(i = sizeof(j)*8-1; i >= 0; i--){
        printf("%d ", ((j>>i) & 1));
    }
    printf("\n");

    return 0;
}