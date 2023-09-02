#include <stdio.h>

#define MAX_SIZE 100

void insert(int arr[], int *size, int index, int value) {
    if (*size >= MAX_SIZE) {
        printf("Array is full, cannot insert.\n");
        return;
    }

    if (index < 0 || index > *size) {
        printf("Invalid index for insertion.\n");
        return;
    }

    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    (*size)++;
}

int delete(int arr[], int *size, int index) {
    if (*size <= 0) {
        printf("Array is empty, cannot delete.\n");
        return;
    }

    if (index < 0 || index >= *size) {
        printf("Invalid index for deletion.\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}

void display(int arr[], int size) {
    if (size <= 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    insert(arr, &size, 0, 10);
    insert(arr, &size, 1, 20);
    insert(arr, &size, 2, 30);
    display(arr, size);

    delete(arr, &size, 1);
    display(arr, size);

    return 0;
}