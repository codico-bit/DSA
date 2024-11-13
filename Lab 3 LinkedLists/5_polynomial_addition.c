#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node* next;
};

void insertEnd(struct Node** head, int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
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

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertEnd(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertEnd(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insertEnd(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertEnd(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertEnd(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

void displayPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    insertEnd(&poly1, 3, 2);
    insertEnd(&poly1, 5, 1);
    insertEnd(&poly1, 6, 0);
    insertEnd(&poly2, 6, 1);
    insertEnd(&poly2, 4, 0);
    struct Node* result = addPolynomials(poly1, poly2);
    displayPolynomial(result);
    return 0;
}
