#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top_ref, int data) {
    // declare the new node with value that we wanna push
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Stack Overflow\\n");
        return;
    }
    // it points to the previous top, and becomes our new top
    new_node->data = data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

// Function to pop an element from the stack
void pop(struct Node** top_ref) {
    //condn for underflow if we run outta nodes so new node is null
    if (*top_ref == NULL) {
        printf("Stack Underflow\\n");
        return;
    }

    // temp to store previous top, which we will free later
    struct Node* temp = *top_ref;
    *top_ref = (*top_ref)->next;
    printf("Popped element: %d\\n", temp->data);
    free(temp);
}

// Function to display the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements:\\n");
    while (temp != NULL) {
        printf("%d\\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* stack = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
