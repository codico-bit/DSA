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

void concatenateLists(struct Node** list1, struct Node* list2) {
    if (*list1 == NULL) {
        *list1 = list2;
        return;
    }
    struct Node* temp = *list1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = list2;
}

void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    insertEnd(&list1, 1);
    insertEnd(&list1, 3);
    insertEnd(&list1, 5);
    insertEnd(&list2, 2);
    insertEnd(&list2, 4);
    insertEnd(&list2, 6);
    concatenateLists(&list1, list2);
    displayList(list1);
    return 0;
}
