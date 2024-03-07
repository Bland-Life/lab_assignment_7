#include <stdio.h>
#include <stdlib.h>

int bubble_sort(int arr[], int size);
int selection_sort(int arr[], int size);
void initialize_array(int arr[], int size);

int main(void) {
    int arr_one[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr_two[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    // selection_sort(arr_one, 9);
    bubble_sort(arr_one, 9);

    // selection_sort(arr_two, 9);
    bubble_sort(arr_two, 9);

    return 0;
}

int bubble_sort(int arr[], int size) {
    int total_swaps = 0;
    int value_swap_count[size];
    initialize_array(value_swap_count, size);

    for (int i = 0; i < size; i++) {
        int index = 0;
        for (int j = 0; j < size - i; j++) {
            if (arr[index] > arr[j]) {
                int temp = arr[index];
                value_swap_count[index] += 1;
                arr[index] = arr[j];
                value_swap_count[j] += 1;
                arr[j] = temp;
                index = j;
                total_swaps++;
            }
        }
    }

    printf("Swaps: %d\n", total_swaps);
    for (int i = 0; i < size; i++) {
        printf("Index %d   Value: %d   Swap Count: %d\n", i, arr[i], value_swap_count[i]);
    }
    printf("\n\n");
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

            // If the minimum value stored is greater than the current element's value
            // then change the minimum value to be the current value and store the index of that value
            if (min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }

        // If there was an update to our index, swap the minimum value to the starting value of this iteration
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