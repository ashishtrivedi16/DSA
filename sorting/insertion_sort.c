#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int a[], int size);

void insertion_sort(int a[], int size){
    int j;
    for (int i = 1; i < size; i++) {
        int key = a[i];
        j = i-1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(void){
    int a[5] = {5, 4, 3, 2, 1};
    insertion_sort(a, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d\t", a[i]);
    }
    
}
