#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

struct vector{
    float *data;
    int size;
};

struct matrix {
    struct vector rows[4];
};

void print_vector(struct vector v){
    for(int i = 0; i < v.size; i++){
        printf("%f ", v.data[i]);
    }
    printf("\n");
}

void print_matrix(struct matrix m){
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("%f ", m.rows[i].data[j]);
        }
        printf("\n");
    }
}

float vector_sum(struct vector v){
    float res = 0.0;
    for(int i = 0; i < v.size; i++)
        res += v.data[i];
    return res;
}

void vector_sum_helper(struct vector v){
    printf("\nOriginal vector: ");
    print_vector(v);
    printf("Vector sum: %f\n", vector_sum(v));
}

void vector_reverse(struct vector *v){
    int i, j;
    float temp[(*v).size];
    for(i = 0; i < (*v).size; i++)
        temp[i] = (*v).data[i];
    for(i = 0, j = (*v).size - 1; i < (*v).size; i++, j--)
        (*v).data[i] = temp[j];
}

void vector_reverse_helper(struct vector *v){
    printf("\nOriginal vector: ");
    print_vector(*v);
    vector_reverse(&(*v));
    printf("Reversed vector: ");
    print_vector(*v);
}

void vector_dist(struct vector v, int *pos, int*neg){
    for(int i = 0; i < v.size; i++){
        if(v.data[i] > 0)
            (*pos) = (*pos) + 1;
        else if(v.data[i] < 0)
            (*neg) = (*neg) + 1;
    }
}

void vector_dist_helper(struct vector v){
    int pos = 0, neg = 0;
    printf("\nOriginal vector: ");
    print_vector(v);
    vector_dist(v, &pos, &neg);
    printf("Positive values: %d\tNegative values: %d\n", pos, neg);
}

struct vector vector_mirror(struct vector v){
    struct vector res;
    int i, j;
    if(v.size < 4){
        res.size = v.size * 2;
        res.data = (float *)malloc(sizeof(float) * res.size);
        for(i = 0, j = 0; i < v.size; i++, j++)
            res.data[j] = v.data[i];
        for(i = v.size-1; i >= 0; i--, j++)
            res.data[j] = v.data[i];
    } else {
        res.size = 8;
        res.data = (float *)malloc(sizeof(float) * res.size);
        for(i = 0, j = 0; i < 4; i++, j++)
            res.data[j] = v.data[i];
        for(i = 3; i >= 0; i--, j++)
            res.data[j] = v.data[i];
    }
    return res;
}

void vector_mirror_helper(struct vector v){
    printf("\nOriginal vector: ");
    print_vector(v);
    struct vector v2 = vector_mirror(v);
    printf("Mirrored vector: ");
    print_vector(v2);
}

float matrix_sum(struct matrix m){
    float res = 0.0;
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            res += m.rows[i].data[j];
        }
    }
    return res;
}

void matrix_sum_helper(struct matrix m){
    printf("\nOriginal matrix:\n");
    print_matrix(m);
    printf("\nMatrix sum: %f\n", matrix_sum(m));
}

void matrix_reverse(struct matrix *m){
    int i, j, k;
    float temp;
    for(i = 0; i < 4; i++){
        for(j = 0, k = 3; j < 2; j++, k--){
            temp = (*m).rows[j].data[i];
            (*m).rows[j].data[i] = (*m).rows[k].data[i];
            (*m).rows[k].data[i] = temp;
        }
    }
}

void matrix_reverse_helper(struct matrix *m){
    printf("\nOriginal matrix:\n");
    print_matrix(*m);
    matrix_reverse(&(*m));
    printf("\nReversed matrix:\n");
    print_matrix(*m);
}

float matrix_dist(struct matrix m, int *pos, int *neg){
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(m.rows[i].data[j] > 0)
                (*pos) = (*pos) + 1;
            else if(m.rows[i].data[j] < 0)
                (*neg) = (*neg) + 1;
        }
    }
}

void matrix_dist_helper(struct matrix m){
    int pos = 0, neg = 0;
    printf("\nOriginal matrix:\n");
    print_matrix(m);
    matrix_dist(m, &pos, &neg);
    printf("\nPositive values: %d\tNegative values: %d\n", pos, neg);
}

int matrix_kazaam(struct matrix m, struct matrix *res){
    int i, j, mul, neg = 0;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(m.rows[i].data[j] >= 0)
                mul = 2;
            else if(m.rows[i].data[j] < 0){
                mul = -3;
                neg++;
            }
            (*res).rows[i].data[j] = m.rows[i].data[j]*mul;
        }
    }
    return neg;
}

void matrix_kazaam_helper(struct matrix m){
    struct matrix res;
    int i;
    for(i = 0; i < 4; i++){
        res.rows[i].size = 4;
        res.rows[i].data = (float*)malloc(sizeof(float)*4);
    }
    printf("\nOriginal matrix:\n");
    print_matrix(m);
    int neg = matrix_kazaam(m, &res);
    printf("\nKazaam matrix:\n");
    print_matrix(res);
    printf("\nOriginal negative values: %d\n", neg);
}

void vector_input(struct vector *v){
    int i;
    float input;
    (*v).size = 0;
    for(i = 0; i < 8; i++){
        printf("Enter a number: ");
        scanf("%f", &input);
        if(input == -1.0)
            break;
        else{
            (*v).size = (*v).size + 1;
            (*v).data[i] = input;
        }
    }
}

void matrix_input(struct matrix *m){
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("Enter a number: ");
            scanf("%f", &(*m).rows[i].data[j]);
        }
    }
}

int main(){
    int i, vector_filled = false, matrix_filled = false, input;
    struct vector v1;
    v1.data = (float*)malloc(sizeof(float)*8);
    struct matrix m;
    for(i = 0; i < 4; i++){
        m.rows[i].size = 4;
        m.rows[i].data = (float*)malloc(sizeof(float)*4);
    }
    while(true){
        printf("\nEnter the option:\n1 for filling the vector\n2 for filling the matrix\n3 vector sum\n");
        printf("4 reverse vector\n5 vector distribution\n6 mirror the vector\n7 matrix sum\n");
        printf("8 reverse matrix\n9 matrix distribution\n10 Matrix kazaam\n0 for exit\n");
        scanf("%d", &input);
        if(input == 0)
            break;
        else if((input >= 3 && input <= 6) && !vector_filled){
            printf("No info in the vector. Please fill it up\n");
        } else if((input >= 7 && input <= 10) && !matrix_filled){
            printf("No info in the matrix. Please fill it up\n");
        } else {
            switch(input){
                case 1:
                    vector_input(&v1);
                    vector_filled = true;
                    break;
                case 2:
                    matrix_input(&m);
                    matrix_filled = true;
                    break;
                case 3:
                    vector_sum_helper(v1);
                    break;
                case 4:
                    vector_reverse_helper(&v1);
                    break;
                case 5:
                    vector_dist_helper(v1);
                    break;
                case 6:
                    vector_mirror_helper(v1);
                    break;
                case 7:
                    matrix_sum_helper(m);
                    break;
                case 8:
                    matrix_reverse_helper(&m);
                    break;
                case 9:
                    matrix_dist_helper(m);
                    break;
                case 10:
                    matrix_kazaam_helper(m);
                    break;
            }
        }
    }
    return 0;    
}