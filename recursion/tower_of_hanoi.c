#include <stdio.h>
#include <stdlib.h>

int count = 1;
void towerofhanoi(int n, char, char, char);

void towerofhanoi(int n, char source, char aux, char dest){
    if (n == 1) {
        printf("Step:%d Moved disk 1 from %c to %c\n", count, source, dest);
        return;
    }
    towerofhanoi(n-1, source, dest, aux);
    count++;
    printf("Step:%d Moved disk %d from %c to %c\n", count, n, source, dest);
    count++;
    towerofhanoi(n-1, aux, source, dest);
}

int main(void){
    int n;
    printf("Enter number of disks: \n");
    scanf("%d", &n);
    towerofhanoi(n, 'A', 'B', 'C');
}
