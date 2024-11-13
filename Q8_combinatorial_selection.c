// Write a program to count all possible ways of selecting R different objects from N given objects.
#include <stdio.h>

int combination(int n, int r) {
    if (r == 0 || r == n) return 1;
    return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main() {
    int N, R;
    printf("Enter N followed by R: ");
    scanf("%d %d", &N, &R);
    if (R > N || R < 0) {
        printf("Invalid input. R should be less than or equal to N and non-negative.\n");
        return 1;
    }
    int result = combination(N, R);
    printf("Answer is %d\n", result);
    return 0;
}
