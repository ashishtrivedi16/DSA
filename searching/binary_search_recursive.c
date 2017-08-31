#include <stdio.h>
#include <stdlib.h>

int binary_search(int [], int, int, int);

int binary_search(int a[], int l, int r, int val){
    
    if (l > r) {
        return -1;
    }
    
    int mid = l + (r-l)/2;
    
    if (a[mid] == val) return 1;
    
    if (a[mid] > val) return binary_search(a, l, mid - 1, val);
    
    return binary_search(a, mid + 1, r, val);
}


int main(void){
    int n;
    int a[5] = {1, 2, 3, 4, 5};
    printf("Enter number that you want to search: ");
    scanf("%d", &n);
    int x = binary_search(a, 0, 4, n);
    x == -1 ? printf("Not found!!\n") : printf("Found it!!\n");
}
