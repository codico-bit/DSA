#include <stdio.h>

int partition(int arr[], int low, int high, int* comparisons) {
    // in partition, we just sort all elements to the left and to the right
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        (*comparisons)++; // increment comparisions at each iteration
        if (arr[j] <= pivot) { // keep swapping all elements lesser than pivot
            i++; 
            int temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp; 
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
// call parition once then quicksort twice. 
void quickSort(int arr[], int low, int high, int* comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
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
    int comparisons = 0;
    quickSort(arr, 0, n - 1, &comparisons);
    printf("Sorted array: ");
    display(arr, n);
    printf("Number of comparisons: %d\n", comparisons);
    return 0;
}