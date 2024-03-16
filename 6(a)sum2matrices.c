#include<stdio.h>

int mat1[10][10], mat2[10][10];
int add[10][10], sub[10][10];

void read_matrix(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
}

void read_matrix2(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
}

void addition(int mat1[10][10], int mat2[10][10], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            add[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtract(int mat1[10][10], int mat2[10][10], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            sub[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void print_matrix(int n, int a[10][10]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, choice;

    printf("Enter the size of matrix\n");
    scanf("%d", &n);

    printf("Enter the first matrix:\n");
    read_matrix(n);

    printf("Enter the second matrix:\n");
    read_matrix2(n);

    printf("Enter the choice for matrix:\n");
    printf("1. Addition of the matrix\n2. Subtraction of matrix\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            addition(mat1, mat2, n);
            printf("The matrix after addition:\n");
            print_matrix(n, add);
            break;

        case 2:
            subtract(mat1, mat2, n);
            printf("The matrix after substraction:\n");
            print_matrix(n, sub);
            break;
    }

    return 0;
}
