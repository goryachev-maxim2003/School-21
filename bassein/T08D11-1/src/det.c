#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n, int m);
void input(double **matrix, int *n, int *m);
void output(double det);

int main()
{
    int n,m;
    double **matrix = NULL;
    input(matrix, &n,&m);
    free(matrix);

}
void input(double **matrix, int *n, int *m){
    
    if (scanf("%d %d", n,m)!=2){
        printf("n/a");
    }
    else{
        matrix = malloc((*n)*(*m)*sizeof(int) + (*n)*sizeof(int*));
        double * p = (double *) matrix+(*n); 
        for (int i = 0; i < *n; i++)
            matrix[i] = p+(*m)*i;
        int flag = 0;
        for (int i = 0; i < *n; i++){
            for (int j = 0; j < *m; j++)
            {
                if (scanf("%lf", &matrix[i][j]) != 1)
                {
                    printf("%lf", matrix[i][j]);
                    printf("n/a");
                    flag = 1;
                    free(matrix);
                    break;
                }
                
            }
            printf("\n");
            if (flag) break;
        }
    }
    
}

