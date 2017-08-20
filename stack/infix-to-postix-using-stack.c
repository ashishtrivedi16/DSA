#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int getPriority(char op);
void push(char stack[], int* top, char* val);
char pop(char stack[], int* top);
void peek(char stack[], int* top);
void display(char stack[], int* top);
void empty(char stack[], int* top);
void infixToPostfix(char infix[], char postfix[], char stack[], int* top, int* val);

int getPriority(char op){
    if (op == '*' || op == '/' || op == '%') {
        return 1;
    } else{
        return 0;
    }
}

void push(char stack[], int* top, char* val){
    if (*top == 19) {
        printf("Stack Overflow!!\n");
    } else {
        (*top)++;
        stack[*top] = *val;
    }
}

char pop(char stack[], int* top){
    char a = stack[*top];
    (*top)--;
    return a;
}

void peek(char stack[], int* top){
    if (*top == -1) {
        printf("Empty stack!\n");
    } else {
        printf("%d\n", stack[*top]);
    }
}

void display(char stack[], int* top){
    for (int i = *top; i >= 0; (i)--) {
        printf("%d\n", stack[i]);
    }
}

void empty(char stack[], int* top){
    if (*top == -1) {
        printf("Stack is empty!!\n");
    } else {
        printf("Stack has %d elements in it!\n", *top + 1);
    }
}


void infixToPostfix(char infix[], char postfix[], char stack[], int* top, int* val){
    int i = 0, j = 0;
    char temp;
    while (i != strlen(infix)) {
        if (infix[i] == '(') {
            push(stack, top, &infix[i]);
            i++;
        } else if(infix[i] == ')'){
            while (*top != -1 && (stack[*top] != '(')) {
                postfix[j] = pop(stack, top);
            }
            if (*top == -1) {
                printf("Incorrect expression!!\n");
                exit(1);
            }
            temp = pop(stack, top);
            i++;
        } else if (isdigit(infix[i]) || isalpha(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%'){
            while (*top != -1 && (stack[*top] != '(') && (getPriority(stack[*top]) > getPriority(infix[i]))) {
                postfix[j] = pop(stack, top);
                j++;
            }
            push(stack, top, &infix[i]);
            i++;
        } else {
            printf("Incorrect element in expression\n");
            exit(1);
        }
    }
    while (*top != -1 && (stack[*top] != '(')) {
        postfix[j] = pop(stack, top);
        j++;
    }
    postfix[j] = '\0';
}

int main(void){
    char stack[20];
    int top = -1, val = 0;
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix, stack, &top, &val);
    printf("%s\n", postfix);
}
