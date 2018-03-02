#include <stdio.h>
#include <stdlib.h>
#define length(x) (sizeof(x)/sizeof(*x))

void print_matrix(int row, int col, double **matrix){
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void reading_values(int row, int cols, double **matrix){
    printf("Enter the values for the matrix:\n");
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < cols; j++){
            scanf("%lf", &matrix[i][j]);
        }
    }
}

int main(){
    double **m1, **m2, **mr;
    int m1_rows, m1_cols, m2_rows, m2_cols, mr_rows, mr_cols;

    printf("Size first matrix (rows, cols): ");
    scanf("%d %d", &m1_rows, &m1_cols);
    printf("Size second matrix (rows, cols): ");
    scanf("%d %d", &m2_rows, &m2_cols);

    mr_rows = m1_rows;
    mr_cols = m2_cols;
    int i, j, k;

    m1 = (double **) malloc(m1_rows*sizeof(double));
    for(i = 0; i < m1_rows; i++)
        m1[i] = (double *) malloc(m1_cols*sizeof(double));

    m2 = (double **) malloc(m2_rows*sizeof(double));
    for(i = 0; i < m2_rows; i++)
        m2[i] = (double *) malloc(m2_cols*sizeof(double));

    mr = (double **) malloc(mr_rows*sizeof(double));
    for(i = 0; i < mr_rows; i++)
        mr[i] = (double *) malloc(mr_cols*sizeof(double));

    reading_values(m1_rows, m1_cols, m1);

    reading_values(m2_rows, m2_cols, m2);

    double sum;
    for(i = 0; i < m1_rows; i++){
        for(j = 0; j < m2_cols; j++){
            sum = 0;
            for(k = 0; k < m2_rows; k++){
                sum += m1[i][k]*m2[k][j];
            }
            mr[i][j] = sum;
        }
    }

    printf("\nMatrix Multiplied\n");
    print_matrix(mr_rows, mr_cols, mr);

    return 0;
}