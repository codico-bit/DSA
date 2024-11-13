#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Output array to store sorted elements
    int i, count[10] = {0}; // Count array to store count of digits (0-9)

    // Count occurrences of each digit
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Update count array to contain actual positions of digits
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1]; // prefix sum of count

    // Build the output array
    // Go backwards, reduce prefix sum by 1 everytime you add an element to output array
    // See slides
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted elements back to the original array
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
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
    radixSort(arr, n);
    printf("Sorted array: ");
    display(arr, n);
    return 0;
}