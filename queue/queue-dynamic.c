#include <stdio.h>
#include <stdlib.h>

struct queue{
    int data;
    struct queue* next;
};

struct queue* front = NULL, *rear = NULL;

void enqueue(int data){
    struct queue* ptr;
    ptr = (struct queue*)malloc(sizeof(struct queue));
    ptr->data = data;
    if(rear == NULL){
        front = ptr;
        rear = ptr;
    }else{
        rear->next = ptr;
        rear = rear->next;
    }
}

void dequeue(){
    if (front == NULL) {
        printf("queue is empty\n");
    } else {
        struct queue* current;
        current = front;
        front = front->next;
        printf("%d was dequeued\n", current->data);
        free(current);
    }
}

void display(){
    struct queue* current = front;
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
}

int main(void){
    int data, options;
    do {
        printf("***************** Main Menu *****************\n");
        printf("1) Insert an element\n");
        printf("2) Delete an element\n");
        printf("3) Display the queue\n");
        printf("4) Exit\n");
        printf("Enter your option: ");
        scanf("%d", &options);
        switch (options) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
    } while (options != 4);
}
