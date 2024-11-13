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

int compareLists(struct Node* list1, struct Node* list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->data != list2->data)
            return 0;
        list1 = list1->next;
        list2 = list2->next;
    }
    return list1 == NULL && list2 == NULL;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    insertEnd(&list1, 1);
    insertEnd(&list1, 2);
    insertEnd(&list1, 3);
    insertEnd(&list2, 1);
    insertEnd(&list2, 2);
    insertEnd(&list2, 3);
    int result = compareLists(list1, list2);
    if (result)
        printf("Lists are identical\n");
    else
        printf("Lists are not identical\n");
    return 0;
}
