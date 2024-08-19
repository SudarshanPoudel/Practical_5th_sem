// C program to implement binary search
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(void) {
    int arr[] = {1, 4, 6, 7, 9, 10, 11, 13, 17, 25, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]), x;

    printf("Enter element to search : ");
    scanf("%d", &x);
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element is not present");
    else
        printf("Element is present at index %d", result);

    printf("\n\n\n");
    return 0;
}