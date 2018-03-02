#include <stdio.h>

struct vector{
    float *data;
    int size;
};

struct matrix {
    struct vector rows[4];
}

int main(){
    int i;
    struct vector v1;
    v1.data = (float *)malloc(sizeof(float));
    struct matriz m1;
    for(i = 0; i < 4; i++)
        m1.rows[i] = ()

    return 0;    
}