#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in a Doubly Linked List
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

// Function to create a new node
struct DNode* createDNode(int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front
void insertFrontD(struct DNode** head, int data) {
    struct DNode* newNode = createDNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to insert a node at the end
void insertEndD(struct DNode** head, int data) {
    struct DNode* newNode = createDNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct DNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a node at a specified position
void insertAtPositionD(struct DNode** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertFrontD(head, data);
        return;
    }
    struct DNode* newNode = createDNode(data);
    struct DNode* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to delete a node at the front
void deleteFrontD(struct DNode** head) {
    if (*head == NULL) return;
    struct DNode* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete a node at the end
void deleteEndD(struct DNode** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct DNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Function to delete a node at a specified position
void deleteAtPositionD(struct DNode** head, int position) {
    if (*head == NULL || position < 1) return;
    if (position == 1) {
        deleteFrontD(head);
        return;
    }
    struct DNode* temp = *head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
}

// Function to traverse and print the list
void traverseD(struct DNode* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to demonstrate the doubly linked list operations
int main() {
    struct DNode* head = NULL;

    insertFrontD(&head, 10);
    insertEndD(&head, 20);
    insertAtPositionD(&head, 15, 2);
    traverseD(head);

    deleteFrontD(&head);
    traverseD(head);

    deleteEndD(&head);
    traverseD(head);

    deleteAtPositionD(&head, 1);
    traverseD(head);

    return 0;
}
