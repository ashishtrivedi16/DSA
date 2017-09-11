#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void push(int stack[], int* top, int postfix);
int pop(int stack[], int* top);

void push(int stack[], int* top, int val){
    if (*top == 9) {
        return;
    } else {
        (*top)++;
        stack[*top] = val;
    }
}

int pop(int stack[], int* top){
    if (*top == -1) {
        return -1;
    } else {
        int x = stack[*top];
        (*top)--;
        return x;
    }
}

int main(void){
    int stack[10];
    int top = -1, i = 0;
    char postfix[20];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    while (i != strlen(postfix) ) {
        if (isdigit(postfix[i])) {
            push(stack, &top, postfix[i] - '0');
            i++;
        }else {
            int val1 = pop(stack, &top);
            int val2 = pop(stack, &top);
            switch (postfix[i])
            {
                case '+':
                    push(stack, &top, val2 + val1);
                    break;
                case '-':
                    push(stack, &top, val2 - val1);
                    break;
                case '*':
                    push(stack, &top, val2 * val1);
                    break;
                case '/':
                    push(stack, &top, val2/val1);
                    break;
            }
            i++;
        }
    }
    printf("%d\n",stack[top]);
}
