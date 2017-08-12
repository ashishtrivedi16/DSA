#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack* next;
};

struct stack* top = NULL;
struct stack* push(struct stack* );
struct stack* pop(struct stack* );
void peek(struct stack* );
void display(struct stack* );

struct stack* push(struct stack* top){
    int val = 0;
    struct stack* new_node;
    printf("Enter -1 to stop inserting values.\n");
    printf("Enter value: ");
    scanf("%d", &val);
    while (val != -1) {
        new_node = (struct stack*)malloc(sizeof(struct stack));
        new_node->data = val;
        if (top == NULL) {
            new_node->next = NULL;
            top = new_node;
        } else {
            new_node->next = top;
            top = new_node;
        }
        printf("Enter value: ");
        scanf("%d", &val);
    }
    return top;
}

struct stack* pop(struct stack* top){
    struct stack* current;
    current = top;
    if (top == NULL) {
        printf("Stack UNDERFLOW\n");
    } else {
        top = top->next;
        printf("%d was popped from the stack.\n", current->data);
        free(current);
    }
    return top;
}

void peek(struct stack* top){
    if (top == NULL) {
        printf("Stack is empty!!\n");
    } else {
        printf("%d\n", top->data);
    }
}

void display(struct stack* top){
    struct stack* current;
    current = top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main(void){
    int options;
    printf("************** Main Menu **************\n");
    printf("1) Push\n");
    printf("2) Pop\n");
    printf("3) Peek\n");
    printf("4) Display\n");
    printf("5) Exit\n");
    printf("Enter your option: ");
    scanf("%d", &options);
Again:
    switch (options) {
        case 1:
            top = push(top);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            peek(top);
            break;
        case 4:
            display(top);
            break;
        case 5:
            printf("Bye bye!!\n\n\n");
            break;
        default:
            printf("Enter a valid number!!");
            break;
    }
    printf("What do you want to do next? ");
    scanf("%d", &options);
    if (options == 5) {
        printf("Bye bye!!\n\n\n");
    } else {
        goto Again;
    }
    
}
