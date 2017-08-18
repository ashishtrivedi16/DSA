#include <stdio.h>
#include <stdlib.h>

void push(int stack[], int* top, int* val);
void pop(int stack[], int* top);
void peek(int stack[], int* top);
void display(int stack[], int* top);
void empty(int stack[], int* top);

void push(int stack[], int* top, int* val){
    if (*top == 9) {
        printf("Stack Overflow!!\n");
    } else {
        printf("Enter data: ");
        scanf("%d", val);
        (*top)++;
        stack[*top] = *val;
    }
}

void pop(int stack[], int* top){
    if (*top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("%d was popped from the stack.\n", stack[*top]);
        (*top)--;
    }
}

void peek(int stack[], int* top){
    if (*top == -1) {
        printf("Empty stack!\n");
    } else {
        printf("%d\n", stack[*top]);
    }
}

void display(int stack[], int* top){
    for (int i = *top; i >= 0; (i)--) {
        printf("%d\n", stack[i]);
    }
}

void empty(int stack[], int* top){
    if (*top == -1) {
        printf("Stack is empty!!\n");
    } else {
        printf("Stack has %d elements in it!\n", *top + 1);
    }
}

int main(void){
    int stack[10];
    int top = -1, val = 0, options;
    printf("************** Main Menu **************\n");
    printf("1) Push\n");
    printf("2) Pop\n");
    printf("3) Peek\n");
    printf("4) Display\n");
    printf("5) Empty check\n");
    printf("6) Exit\n");
    printf("Enter your option: ");
    scanf("%d", &options);
Again:
    switch (options) {
        case 1:
            push(stack, &top, &val);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            peek(stack, &top);
            break;
        case 4:
            display(stack, &top);
            break;
        case 5:
            empty(stack, &top);
            break;
        case 6:
            printf("Bye bye!!\n\n\n");
            break;
        default:
            printf("Enter a valid number!!");
            break;
    }
    printf("What do you want to do next? ");
    scanf("%d", &options);
    if (options == 6) {
        printf("Bye bye!!\n\n\n");
    } else {
        goto Again;
    }
    
}
