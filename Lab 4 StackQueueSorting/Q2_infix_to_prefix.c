#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
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

void reverse(char* exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void infixToPrefix(char* exp) {
    char result[MAX], temp[MAX];
    int j = 0;
    
    reverse(exp);
    
    for (int i = 0; exp[i]; i++) {
        if (isalnum(exp[i])) {
            temp[j++] = exp[i];
        } else if (exp[i] == ')') {
            push(exp[i]);
        } else if (exp[i] == '(') {
            while (top != -1 && stack[top] != ')')
                temp[j++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i]))
                temp[j++] = pop();
            push(exp[i]);
        }
    }
    
    while (top != -1)
        temp[j++] = pop();
    
    temp[j] = '\0';
    reverse(temp);
    printf("Prefix Expression: %s\n", temp);
}

int main() {
    char exp[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", exp);
    infixToPrefix(exp);
    return 0;
}

