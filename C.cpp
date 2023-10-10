#include <iostream>

void quicksort(int* array, int* second_array, int size) {
    int index_left_side_element = 0;
    int index_right_side_element = size - 1;

    if (size < 2) {
        return;
    }#include <iostream>

void quicksort(int* array, int size) {
    int index_left_side_element = 0;
    int index_right_side_element = size - 1;

    if (size < 2) {
        return;
    }

    int middle = array[size/2];

    while (index_left_side_element <= index_right_side_element) {
        while (array[index_left_side_element] < middle) {
            index_left_side_element++;
        }
        while (array[index_right_side_element] > middle) {
            index_right_side_element--;
        }
        if (index_left_side_element <= index_right_side_element) {
            if (index_left_side_element != index_right_side_element) {
                std::swap(array[index_left_side_element], array[index_right_side_element]);
            }
            index_left_side_element++;
            index_right_side_element--;
        }
    }
    quicksort(array,index_right_side_element+1);
    quicksort(array + index_left_side_element, size - index_left_side_element);
}

int main() {
    long long total_S = 0;
    int k = 0;
    long long sides = 1;
    int number_of_sticks;
    std::cin >> number_of_sticks;
    int sticks[number_of_sticks];

    for (int i = 0; i < number_of_sticks; i++) {
        std::cin >> sticks[i];
    }

    quicksort(sticks,number_of_sticks);

    for (int i = number_of_sticks-1; i >= 1; i--) {
        if ((sticks[i] - sticks[i-1]) <= 1) {
            if ((sticks[i] - sticks[i-1]) == 1) {
                sticks[i]--;
            }
            sides *= sticks[i];
            k++;
            i--;
        }
        if (k == 2) {
            total_S += sides;
            sides = 1;
            k = 0;
        }
    }
    std::cout << total_S;
    return 0;
}
