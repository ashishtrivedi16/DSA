#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void insert(int queue[], int* val, int* front, int* rear);
void delete(int queue[], int* front, int* rear);
void peek(int queue[], int* front, int* rear);
void display(int queue[], int* front, int* rear);

void insert(int queue[], int* val, int* front, int* rear){
    if (*rear == 9) {
        printf("Overflow!!\n");
        return;
    } else if(*front == -1 && *rear == -1){
        *front = *rear = 0;
    } else{
        (*rear)++;
    }
    queue[*rear] = *val;
    printf("%d was inserted in the queue!\n", queue[*rear]);
}

void delete(int queue[], int* front, int* rear){
    if (*front == -1 || *front > *rear) {
        printf("Underflow!!\n");
    } else {
        printf("%d was deleted!\n", queue[*front]);
        (*front)++;
        if (*front > *rear) {
            *front = *rear = -1;
        }
        
    }
}

void peek(int queue[], int* front, int* rear){
    if (*front == -1 || *front > *rear) {
        printf("Queue is empty!!\n");
    } else {
        printf("%d\n", queue[*front]);
    }
}

void display(int queue[], int* front, int* rear){
    if (*front == -1 || *front > *rear) {
        printf("Queue is empty!!\n");
    } else {
        for (int i = *front; i <= *rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main(void){
    int queue[10];
    int front = -1, rear = -1, val = 0, options;
    do {
        printf("***************** Main Menu *****************\n");
        printf("1) Insert an element\n");
        printf("2) Delete an element\n");
        printf("3) Peek\n");
        printf("4) Display the queue\n");
        printf("5) Exit\n");
        printf("Enter your option: ");
        scanf("%d", &options);
        switch (options) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &val);
                insert(queue, &val, &front, &rear);
                break;
            case 2:
                delete(queue, &front, &rear);
                break;
            case 3:
                peek(queue, &front, &rear);
                break;
            case 4:
                display(queue, &front, &rear);
                break;
            default:
                break;
        }
    } while (options != 5);
}
