#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void reverseListIterative(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;
    //keep traversing till you reach last node
    while (curr != NULL) {
        //reverse the pointers, how?
        // set curr node to point to prev node 
        // move prev to curr
        // move curr to next
        // next is just used to store the next node
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    reverseListIterative(&head);
    displayList(head);
    return 0;
}
