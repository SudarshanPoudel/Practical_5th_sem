// C program to implement insertion sort

#include<stdio.h>

void insertionSort(int array[], int size) {
    int i, j, key;

    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}


int main(){
    int arr[100], i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
      scanf("%d", &arr[i]);

    insertionSort(arr, n);
    
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
      printf("%d ", arr[i]);
    return 0;
}
