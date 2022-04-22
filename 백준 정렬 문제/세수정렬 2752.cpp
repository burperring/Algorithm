#include<stdio.h>

int arr[3];

int main(void) {
    int temp, min, index, i, j;
    for (i = 0; i < 3; i++)
    {
        scanf_s("%d", &arr[i]);
    }

    for (i = 0; i < 3; i++) {
        min = 1000001;
        for (j = i; j < 3;j++) {
            if (min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    for (i = 0; i < 3; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}