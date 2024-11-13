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

void sortList(struct Node* head) {
    struct Node* i = head;
    while (i != NULL) {
        struct Node* j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

int compareElements(struct Node* list1, struct Node* list2) {
    sortList(list1);
    sortList(list2);
    return compareLists(list1, list2);
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    insertEnd(&list1, 3);
    insertEnd(&list1, 2);
    insertEnd(&list1, 1);
    insertEnd(&list2, 1);
    insertEnd(&list2, 2);
    insertEnd(&list2, 3);
    int result = compareElements(list1, list2);
    if (result)
        printf("Lists have the same elements\n");
    else
        printf("Lists do not have the same elements\n");
    return 0;
}
