#include <stdio.h>
#include <stdlib.h>

/*
Qns) 
- Which functions are you trying to do
- What arguments are needed to build a stack?
- While pushing you do ++top, while popping you do top--, 
and top stores the highest variable 

*/

// Function to push an element to the top of the stack
void push(int *stack, int *top, int size, int data) {
    if (*top == size - 1) {
        printf("Stack Overflow\\n");
        return;
    }
    stack[++*top] = data;
}

// Function to pop an element from the top of the stack
void pop(int *stack, int *top) {
    if (*top == -1) {
        printf("Stack Underflow\\n");
        return;
    }
    printf("Popped element: %d\\n", stack[*top--]);
}

// Function to display the elements of the stack
void display(int *stack, int top) {
    if (top == -1) {
        printf("Stack is empty\\n");
        return;
    }
    printf("Stack elements:\\n");
    for (int i = top; i >= 0; i--)
        printf("%d\\n", stack[i]);
}

int main() {
    int size, choice, value;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    
    // Dynamically allocate the stack
    int *stack = (int *)malloc(size * sizeof(int));
    int top = -1;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, &top, size, value);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                free(stack);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
