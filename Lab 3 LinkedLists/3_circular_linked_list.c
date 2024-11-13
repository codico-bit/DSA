#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode* next;
};

struct CNode* createCNode(int data) {
    struct CNode* newNode = (struct CNode*)malloc(sizeof(struct CNode));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void insertFrontC(struct CNode** head, int data) {
    struct CNode* newNode = createCNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct CNode* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

void insertEndC(struct CNode** head, int data) {
    struct CNode* newNode = createCNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct CNode* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void insertAtPositionC(struct CNode** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertFrontC(head, data);
        return;
    }
    struct CNode* newNode = createCNode(data);
    struct CNode* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFrontC(struct CNode** head) {
    if (*head == NULL) return;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct CNode* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    struct CNode* toDelete = *head;
    *head = (*head)->next;
    temp->next = *head;
    free(toDelete);
}

void deleteEndC(struct CNode** head) {
    if (*head == NULL) return;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct CNode* temp = *head;
    struct CNode* prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = *head;
    free(temp);
}

void deleteAtPositionC(struct CNode** head, int position) {
    if (*head == NULL || position < 1) return;
    if (position == 1) {
        deleteFrontC(head);
        return;
    }
    struct CNode* temp = *head;
    struct CNode* prev = NULL;
    for (int i = 1; i < position && temp->next != *head; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == *head && i < position) {
        printf("Position out of bounds\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void traverseC(struct CNode* head) {
    if (head == NULL) return;
    struct CNode* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}