#include <stdio.h>
#define SIZE 10

int input(int *a);
void output(int *a);
void quick_sort(int *a, int first, int last);

int main() {
    int data1[SIZE], data2[SIZE];
    if (input(data1) && input(data2)) {
        quick_sort(data1, 0, SIZE-1);
        //output(data1);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a) {
    for (int *p = a; p - a < SIZE; p++) {
        if (scanf("%d", p) != 1) {
            return 0;
        }
    }
    return 1;
}

void output(int *a) {
    for (int *p = a; p - a < SIZE; p++) {
        (p - a == 0) ? printf("%d", *p) : printf(" %d", *p);
    }
}

void swap(int *a, int *b) {
    int save_a = *a;
    *a = *b;
    *b = save_a;
}

void quick_sort(int *a, int first, int last) {
    if (first < last){
        int left = first, right = last, middle = a[(left + right) / 2];
        do{
            while (a[left]<middle)
                left++;
            while (a[right] > middle)
                right--;
            if (left <= right){
                swap(a+left, a+right);
                left++;
                right--;
            }
        }while (left<=right);
        quick_sort(a, first, right);
        quick_sort(a, left, last);
    }
}
