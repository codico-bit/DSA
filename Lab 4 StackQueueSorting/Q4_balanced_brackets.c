#include <stdio.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

bool isMatchingPair(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}

bool checkBalancedBrackets(char* exp) {
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1 || !isMatchingPair(pop(), exp[i])) {
                return false;
            }
        }
    }
    return (top == -1);
}

int main() {
    char exp[MAX];
    printf("Enter an expression with brackets: ");
    scanf("%s", exp);
    if (checkBalancedBrackets(exp)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    return 0;
}