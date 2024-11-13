#include <stdio.h>
#include <stdlib.h>

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    int i, j, k, count = 0;

    // Define a Node structure for linked list implementation of buckets
    struct Node {
        float data;
        struct Node* next;
    };

    // Create an array of 10 buckets, each initialized to NULL
    struct Node* bucket[10] = { NULL };

    // Distribute elements into buckets
    for (i = 0; i < n; i++) {
        // Calculate bucket index
        int bi = arr[i] * 10;
        // Create a new node
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->data = arr[i];
        // Insert the node at the beginning of the bucket
        new_node->next = bucket[bi];
        bucket[bi] = new_node;
    }

    // Sort each bucket and concatenate the results
    for (i = 0; i < 10; i++) {
        struct Node* temp = bucket[i];
        float bucketArr[n];
        k = 0;

        // Transfer bucket elements to an array
        while (temp != NULL) {
            bucketArr[k++] = temp->data;
            temp = temp->next;
        }

        // Sort the array using insertion sort
        for (int m = 1; m < k; m++) {
            float key = bucketArr[m];
            int l = m - 1;
            while (l >= 0 && bucketArr[l] > key) {
                bucketArr[l + 1] = bucketArr[l];
                l--;
                count++;
            }
            bucketArr[l + 1] = key;
        }

        // Copy sorted elements back to the original array
        for (j = 0; j < k; j++) {
            arr[count++] = bucketArr[j];
        }
    }

    // Print the total number of comparisons made during sorting
    printf("Total comparisons: %d\n", count);
}

// Function to display the array
void display(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    float arr[n];
    printf("Enter %d float elements (between 0 and 1):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array: ");
    display(arr, n);
    return 0;
}