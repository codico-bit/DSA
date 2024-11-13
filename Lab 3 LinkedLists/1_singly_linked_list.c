#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in a Singly Linked List
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front
void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node at a specified position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertFront(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node at the front
void deleteFront(struct Node** head) {
    //if head is null nothin happens
    if (*head == NULL) return;
    //else create temp pointer pointing to head
    // move the head
    // free the original node
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node at the end
void deleteEnd(struct Node** head) {
    // if head is null nothing happens
    if (*head == NULL) return;
    /// if only one node, free it up
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    // else iterate till you reach second last node
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // free the node after the second last node(ie last node)
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node at a specified position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL || position < 1) return;
    if (position == 1) {
        deleteFront(head);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Function to traverse and print the list
void traverse(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to demonstrate the singly linked list operations
int main() {
    struct Node* head = NULL;

    insertFront(&head, 10);
    insertEnd(&head, 20);
    insertAtPosition(&head, 15, 2);
    traverse(head);

    deleteFront(&head);
    traverse(head);

    deleteEnd(&head);
    traverse(head);

    deleteAtPosition(&head, 1);
    traverse(head);

    return 0;
}
