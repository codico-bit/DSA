#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int front, rear;
    int data[MAX];
};

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\\n");
        return;
    }
    q->data[++q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (q->front > q->rear) {
        printf("Queue Underflow\\n");
        return -1;
    }
    return q->data[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

struct Stack {
    struct Queue q1, q2;
};

void push(struct Stack* s, int value) {
    enqueue(&s->q2, value);
    while (!isEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    struct Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int pop(struct Stack* s) {
    return dequeue(&s->q1);
}

void display(struct Stack* s) {
    struct Queue temp = s->q1;
    while (!isEmpty(&temp)) {
        printf("%d ", dequeue(&temp));
    }
    printf("\\n");
}

int main() {
    struct Stack s = {{0, -1}, {0, -1}};
    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                printf("Popped element: %d\n", pop(&s));
                break;
            case 3:
                display(&s);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
