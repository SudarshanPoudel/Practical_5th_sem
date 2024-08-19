// C program to implement selection sort
#include <stdio.h>

void selectionSort(int array[], int size) {
    int i, j, minIndex, temp;

    for (i = 0; i < size - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i){
            temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
    }
}


int main(){
    int arr[100], i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
      scanf("%d", &arr[i]);

    selectionSort(arr, n);
    
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
      printf("%d ", arr[i]);
    return 0;
}
