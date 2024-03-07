#include <stdio.h>
#include <stdlib.h>

int bubble_sort(int arr[], int size);
int selection_sort(int arr[], int size);
void initialize_array(int arr[], int size);

int main(void) {
    int arr_one[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr_two[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    selection_sort(arr_one, 9);
    selection_sort(arr_two, 9);

    return 0;
}

int bubble_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++) {

        }
    }
    return 0;
}

int selection_sort(int arr[], int size) {
    int total_swaps = 0;
    int value_swap_count[size];
    initialize_array(value_swap_count, size);

    // For every element
    for (int i = 0; i < size; i++) {
        int min = arr[i];
        int index = i;

        // For every element after the sorted elements
        for (int j = i; j < size; j++) {

            // If 
            if (min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }

        if (index > i) {
            arr[index] = arr[i];
            value_swap_count[index] += 1;
            arr[i] = min;
            value_swap_count[i] += 1;
            total_swaps++;
        }
    }

    printf("Swaps: %d\n", total_swaps);
    for (int i = 0; i < size; i++) {
            printf("Index %d   Value: %d   Swap Count: %d\n", i, arr[i], value_swap_count[i]);
    }
    printf("\n\n");
    
    return 0;
}

void initialize_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}