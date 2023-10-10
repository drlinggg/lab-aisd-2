#include <iostream>

void quicksort(int* array, int* second_array, int size) {
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
                std::swap(second_array[index_left_side_element], second_array[index_right_side_element]);
            }
            index_left_side_element++;
            index_right_side_element--;
        }
    }
    quicksort(array, second_array, index_right_side_element+1);
    quicksort(array + index_left_side_element, second_array + index_left_side_element, size - index_left_side_element);
}

int main()
{
    int n;
    long long count = 0;
    long long TempCount = 0;
    std::cin >> n;
    int ArrayOfDeadlines[n];
    int ArrayOfWorkingDays[n];
    for (int i = 0; i < n; i++) {
        std::cin >> ArrayOfWorkingDays[i];
        std::cin >> ArrayOfDeadlines[i];
    }
    quicksort(ArrayOfWorkingDays, ArrayOfDeadlines, n);
    int day = 0;
    while (day < n) {
        TempCount += ArrayOfWorkingDays[day];
        count += ArrayOfDeadlines[day] - TempCount;
        day++;
    }
    std::cout << count;
    return 0;
}
