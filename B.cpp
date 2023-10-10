#include <iostream>

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
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int number;
    std::cin >> number;
    int array[number];

    for (int i = 0; i < number; i++) {
        std::cin >> array[i];
    }
    quicksort(array,number);

    for (int i = 0; i < number; i++) {
        std::cout << array[i] << ' ';
    }

    return 0;
}
