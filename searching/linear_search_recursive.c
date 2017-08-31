#include <stdio.h>
#include <stdlib.h>

int linear_search(int [], int , int, int);

int linear_search(int a[], int start, int end, int val){
    if (end <= start) {
        return -1;
    }
    if (a[start] == val) {
        return val;
    }
    return linear_search(a, start + 1, end, val);
}

int main(void){
    int n;
    int a[5] = {5, 4, 3, 2, 1};
    printf("Enter number that you want to search: ");
    scanf("%d", &n);
    int x = linear_search(a, 0, 4, n);
    x == -1 ? printf("Not found!!\n") : printf("Found it!!\n");
}
