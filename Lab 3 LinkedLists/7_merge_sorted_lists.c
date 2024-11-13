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

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    if (list1->data <= list2->data) {
        result = list1;
        result->next = mergeSortedLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeSortedLists(list1, list2->next);
    }
    return result;
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
    struct Node* result = mergeSortedLists(list1, list2);
    displayList(result);
    return 0;
}
