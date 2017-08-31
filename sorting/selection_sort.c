#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y);
void selection_sort(int a[], int size);

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int a[], int size){
    int min;
    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i+1; j < size; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(&a[min], &a[i]);
    }
}

int main(void){
    int a[5] = {5, 4, 3, 2, 1};
    selection_sort(a, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d\t", a[i]);
    }
    
}
