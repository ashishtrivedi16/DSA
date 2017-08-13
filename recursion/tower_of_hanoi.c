#include <stdio.h>
#include <stdlib.h>

void towerofhanoi(int n, char, char, char);

void towerofhanoi(int n, char source, char aux, char dest){
    if (n == 1) {
        printf("Moving disk 1 from %c to %c\n", source, dest);
        return;
    }
    towerofhanoi(n-1, source, dest, aux);
    printf("Moving disk %d from %c to %c\n", n, source, dest);
    towerofhanoi(n-1, aux, source, dest);
}

int main(void){
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    towerofhanoi(n, 'A', 'B', 'C');
}
