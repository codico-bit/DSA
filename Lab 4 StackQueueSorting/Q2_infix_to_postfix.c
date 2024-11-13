#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\\n");
        return;
    }
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\\n");
        return -1;
    }
    return stack[top--];
}

int precedence(char x) {
    switch (x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

void infixToPostfix(char* exp) {
    char output[MAX];
    int k = 0;
    for (int i = 0; exp[i]; i++) {
        if (isalnum(exp[i])) {
            output[k++] = exp[i];
        } else if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(')
                output[k++] = pop();
            pop(); 
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i]))
                output[k++] = pop();
            push(exp[i]);
        }
    }
    while (top != -1)
        output[k++] = pop();
    output[k] = '\0';
    printf("Postfix Expression: %s \n", output);
}

int main() {
    char exp[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}