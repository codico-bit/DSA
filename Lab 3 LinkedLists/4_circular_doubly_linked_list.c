#include <stdio.h>
#include <stdlib.h>

struct CDNode {
    int data;
    struct CDNode* prev;
    struct CDNode* next;
};

struct CDNode* createCDNode(int data) {
    struct CDNode* newNode = (struct CDNode*)malloc(sizeof(struct CDNode));
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

void insertFrontCD(struct CDNode** head, int data) {
    struct CDNode* newNode = createCDNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    newNode->prev = (*head)->prev;
    (*head)->prev->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertEndCD(struct CDNode** head, int data) {
    struct CDNode* newNode = createCDNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    newNode->prev = (*head)->prev;
    (*head)->prev->next = newNode;
    (*head)->prev = newNode;
}

void insertAtPositionCD(struct CDNode** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertFrontCD(head, data);
        return;
    }
    struct CDNode* newNode = createCDNode(data);
    struct CDNode* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteFrontCD(struct CDNode** head) {
    if (*head == NULL) return;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct CDNode* temp = *head;
    (*head)->prev->next = (*head)->next;
    (*head)->next->prev = (*head)->prev;
    *head = (*head)->next;
    free(temp);
}

void deleteEndCD(struct CDNode** head) {
    if (*head == NULL) return;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct CDNode* temp = (*head)->prev;
    temp->prev->next = *head;
    (*head)->prev = temp->prev;
    free(temp);
}

void deleteAtPositionCD(struct CDNode** head, int position) {
    if (*head == NULL || position < 1) return;
    if (position == 1) {
        deleteFrontCD(head);
        return;
    }
    struct CDNode* temp = *head;
    for (int i = 1; i < position && temp->next != *head; i++) {
        temp = temp->next;
    }
    if (temp->next == *head && i < position) {
        printf("Position out of bounds\n");
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void traverseCD(struct CDNode* head) {
    if (head == NULL) return;
    struct CDNode* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}