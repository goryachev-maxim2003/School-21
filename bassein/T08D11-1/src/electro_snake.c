#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
// void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
// void sort_horizontal(int **matrix, int n, int m, int **result_matrix);


void input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);


void main()
{
    int **matrix = NULL;//, **result;
    int n,m;

    
    input(matrix, &n, &m);
    output(matrix, n, m);

//     input(matrix);
    
//     sort_vertical(matrix, n, m, result);
//     output(result);
    
//     sort_horizontal(matrix, n, m, result);
//     output(result);
    free(matrix);
}

void input(int **matrix, int *n, int *m){
    if (scanf("%d %d",n,m)!=2){
        printf("n/a");
    }
    else{
        matrix = malloc((*n)*(*m)*sizeof(int) + (*n)*sizeof(int*));
        int *p = (int *) matrix+(*n);
        for (int i = 0; i<(*n); i++) 
            matrix[i] = p+(*m)*i;
        int flag = 0;
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                if (scanf("%d",&matrix[i][j])!=1){
                    printf("n/a");
                   flag = 1;
                   break;
                }
            }
            if (flag) break;
        }
    }
}
void output(int **a, int n, int m){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            (j==m-1) ? printf("%d", a[i][j]) : printf("%d ", a[i][j]);
        }
        if (i!=n-1) printf("\n");
    }
}