#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX], top = -1;
void push(int stack[], int val);
int pop(int stack[]);
int peek(int stack[]);
void display(int stack[]);


void push(int stack[], int val){
    if (top == MAX -1) {
        printf("Stack OVERFLOW\n");
    } else {
        while (1) {
            printf("Enter value to be inserted: ");
            scanf("%d", &val);
            if (val == -1) {
                break;
            }
            top++;
            stack[top] = val;
        }
    }
}

int pop(int stack[]){
    int val;
    if (top == -1) {
        printf("Stack UNDERFLOW\n");
        return -1;
    } else {
        val = stack[top];
        top--;
        return val;
    }
}

int peek(int stack[]){
    if (top == -1) {
        printf("Stack is empty!!\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display(int stack[]){
    if (top == -1) {
        printf("Stack is empty!!\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main(void){
    int val = 0, options;
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
            printf("Enter -1 to stop inserting values.\n");
            push(stack, val);
            break;
        case 2:
            val = pop(stack);
            printf("%d was popped from the stack.\n", val);
            break;
        case 3:
            val = peek(stack);
            printf("%d\n", val);
            break;
        case 4:
            display(stack);
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
