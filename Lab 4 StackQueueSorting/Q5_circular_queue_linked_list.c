#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Function to enqueue an element into the circular queue
void enqueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (front == NULL) {
        front = newNode;
        rear = newNode;
        newNode->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

// Function to dequeue an element from the circular queue
void dequeue() {
    if (front == NULL) {
        printf("Queue is Empty\\n");
        return;
    }
    struct Node* temp = front;
    if (front == rear) {
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    printf("Dequeued element: %d\\n", temp->data);
    free(temp);
}

// Function to display the elements of the circular queue
void display() {
    if (front == NULL) {
        printf("Queue is Empty\\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements:\\n");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
