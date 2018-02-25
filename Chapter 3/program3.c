#include <stdio.h>
#define length(x) (sizeof(x)/sizeof(*x))

void print_matrix(int row, int col, float matrix[row][col]){
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    float a[2][3], b[3][2], c[2][2];
    int i, j, k, sum;
    sum = 0;
    for(i = 0; i < length(a); i++){
        for(j = 0; j < length(a[0]); j++, sum++){
            a[i][j] = sum;
        }
    }

    sum = 0;
    for(i = 0; i < length(b); i++){
        for(j = 0; j < length(b[0]); j++, sum+=2){
            b[i][j] = sum;
        }
    }

    printf("Matrix a\n");
    print_matrix(length(a), length(a[0]), a);
    printf("\nMatrix b\n");
    print_matrix(length(b), length(b[0]), b);

    for(i = 0; i < length(a); i++){
        for(j = 0; j < length(b[0]); j++){
            sum = 0;
            for(k = 0; k < length(b); k++){
                sum += a[i][k]*b[k][j];
            }
            c[i][j] = sum;
        }
    }

    printf("\nMatrix c\n");
    print_matrix(length(c), length(c[0]), c);

    return 0;
}