#include <stdio.h>
#define MAX 5

int queue[MAX], front = MAX-1, rear = MAX-1;  // Initialize both to MAX-1

// Function to enqueue an element into the circular queue
void enqueue(int data) {
    if ((rear + 1) % MAX == front) {  // Simplified full condition
        printf("Queue is Full\n");
        return;
    }
    rear = (rear + 1) % MAX;  // Move rear to next position
    queue[rear] = data;
}

// Function to dequeue an element from the circular queue
void dequeue() {
    if (rear == front) {  // Simplified empty condition
        printf("Queue is Empty\n");
        return;
    }
    front = (front + 1) % MAX;  // Move front to next position
    printf("Dequeued element: %d\n", queue[front]);
}

// Function to display the elements of the circular queue
void display() {
    if (rear == front) {  // Empty condition
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements:\n");
    int i = (front + 1) % MAX;
    while (i != (rear + 1) % MAX) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
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