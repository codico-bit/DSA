#include <stdio.h>

int merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // number of elements in left array
    int n2 = right - mid; // number of elements in right array
    int L[n1], R[n2]; // the left and the right arrays
    int comparisons = 0;

    for (int i = 0; i < n1; i++) L[i] = arr[left + i]; // store the elements in left array
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j]; // store the elements in right array

    int i = 0, j = 0, k = left; 
    while (i < n1 && j < n2) { // iterate through the arrays and put them in correct position in arr
        if (L[i] <= R[j]) {
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
        k++;
        comparisons++; // one comparision everytime you push an element
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    return comparisons;
}

int mergeSort(int arr[], int left, int right) {
    int comparisons = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        comparisons += mergeSort(arr, left, mid);
        comparisons += mergeSort(arr, mid + 1, right);
        comparisons += merge(arr, left, mid, right);
    }
    return comparisons;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int comparisons = mergeSort(arr, 0, n - 1);
    printf("Sorted array: ");
    display(arr, n);
    printf("Number of comparisons: %d\n", comparisons);
    return 0;
}
