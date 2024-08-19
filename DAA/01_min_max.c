// C program to find Minimum and maximum element in array with recursive function

#include <stdio.h>

void findMinMax(int arr[], int left, int right, int *min, int *max) {
    if (left == right) {
        *min = *max = arr[left];
        return;
    }
    
    if (left == right - 1) {
        if (arr[left] < arr[right]) {
            *min = arr[left];
            *max = arr[right];
        } else {
            *min = arr[right];
            *max = arr[left];
        }
        return;
    }

    int mid = (left + right) / 2;
    int min1, max1, min2, max2;
    findMinMax(arr, left, mid, &min1, &max1);
    findMinMax(arr, mid + 1, right, &min2, &max2);
    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

int main() {
    int size, min, max;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    findMinMax(arr, 0, size - 1, &min, &max);

    printf("Min: %d\nMax: %d\n\n\n", min, max);

    return 0;
}
