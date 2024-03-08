#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bubble_sort(int arr[], int size);
int selection_sort(int arr[], int size);
void initialize_array(int arr[], int size);
void print_array(int arr[], int size);

int main(void) {
    
    int arr_one[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr_two[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int testing_duplicate[9];

    

    printf("Selection Sort: \n\n");
    memcpy(testing_duplicate, arr_one, sizeof(arr_one));
    selection_sort(testing_duplicate, 9);
    print_array(testing_duplicate, 9);

    memcpy(testing_duplicate, arr_two, sizeof(arr_two));
    selection_sort(testing_duplicate, 9);
    print_array(testing_duplicate, 9);

    printf("Bubble Sort: \n\n");
    memcpy(testing_duplicate, arr_one, sizeof(arr_one));
    bubble_sort(testing_duplicate, 9);
    print_array(testing_duplicate, 9);

    memcpy(testing_duplicate, arr_two, sizeof(arr_two));
    bubble_sort(testing_duplicate, 9);
    print_array(testing_duplicate, 9);

    return 0;
}

int bubble_sort(int arr[], int size) {
    int total_swaps = 0;
    int value_swap_count[size];
    initialize_array(value_swap_count, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            if (j + 1 < size && arr[j] > arr[j+1]) {
                int temp = arr[j];
                value_swap_count[j] += 1;
                arr[j] = arr[j + 1];
                value_swap_count[j + 1] += 1;
                arr[j + 1] = temp;
                total_swaps++;
            }
        }
    }

    printf("Swaps: %d\n", total_swaps);
    for (int i = 0; i < size; i++) {
        printf("Index %d   Value: %d   Swap Count: %d\n", i, arr[i], value_swap_count[i]);
    }
    printf("\n");
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
    printf("\n");
    
    return 0;
}

void initialize_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n-----------------------------------------\n");
}