#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read(FILE* input, int* matrix, int dimension){
    for(int i = 0; i < dimension*dimension; i++){
        fscanf(input, "%d", &matrix[i]);
    }
    //printf("all good \n");
}

void print(int* matrix, int dimension){
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            printf("%d", matrix[i*dimension + j]);
            if(j != dimension - 1)    
                printf(" ");
        }
        printf("\n");
    }
    //printf("all good \n");
}

int findExp(FILE* input){
    int num;
    fscanf(input, "%d", &num);
    return num;
    //printf("all good \n");
}

void duplicate(int* original, int* result, int dimension){
    for(int i = 0; i < dimension*dimension; i++){
        result[i] = original[i];
    }
    //printf("all good \n");
}

int* multiply(int* current, int* new, int dimension){
    int* final = malloc(dimension*dimension*sizeof(int));
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            final[i*dimension + j] = 0;
            for (int k = 0; k < dimension; k++) {
                final[i*dimension + j] += current[i*dimension + k] * new[k*dimension + j];
            }
        }
    }
    return final;
}

int main(int argc, char **argv){
    FILE* input = fopen(argv[1], "r");
    int dimension, exp;
    fscanf(input, "%d", &dimension);
    //printf("all good \n");
    int *original = malloc(dimension*dimension*sizeof(int));
    int *result = malloc(dimension*dimension*sizeof(int));
    read(input, original, dimension);
    exp = findExp(input);
    if(exp == 0){
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                if(i != j)
                    original[i*dimension + j] = 0;
                else{
                    original[i*dimension + j] = 1;
                }
            }
        }
    }
    duplicate(original, result, dimension);
    if(exp != 0){
        for(int i = 1; i < exp; i++){
            int *previousResult = result;
            result = multiply(result, original, dimension);
            free(previousResult);
        }
    }
    print(result, dimension);
    free(original);
    free(result);
    fclose(input);
}
