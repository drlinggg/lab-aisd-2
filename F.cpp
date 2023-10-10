#include <iostream>

void quicksort_for_2_arrays(long long *array, long long *index_rates, int size) {
    int index_left_side_element = 0;
    int index_right_side_element = size - 1;
    if (size < 2) {
        return;
    }
    long long middle = array[size/2];
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
                std::swap(index_rates[index_left_side_element], index_rates[index_right_side_element]);
            }
            index_left_side_element++;
            index_right_side_element--;
        }
    }
    quicksort_for_2_arrays(array,index_rates, index_right_side_element+1);
    quicksort_for_2_arrays(array + index_left_side_element,index_rates+index_left_side_element, size - index_left_side_element);
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int count_of_reviewers;
    int count_of_films;
    int count_of_best_films;
    std::cin >> count_of_reviewers;
    std::cin >> count_of_films;
    std::cin >> count_of_best_films;
    int authority[count_of_reviewers];
    long long rates[count_of_films];
    long long index_rates[count_of_films];
    for (int i = 0; i < count_of_films; i++) {
        index_rates[i] = i;
    }
    for (int i = 0; i < count_of_films; i++) {
        rates[i] = 0;
    }
    for (int i = 0; i < count_of_reviewers; i++) {
        std::cin >> authority[i];
    }
    for (int i = 0; i < count_of_films; i++) {
        for (int j = 0; j < count_of_reviewers; j++) {
            long long currect_rate;
            std::cin >> currect_rate;
            rates[i] += (authority[j] * currect_rate);
            rates[i] = rates[i] % 1000000007;
        }
    }
    quicksort_for_2_arrays(rates, index_rates, count_of_films);
    for (int i = 0; i < count_of_best_films; i++) {
        std::cout << index_rates[count_of_films-1-i]+1 << ' ';
    }
    return 0;
}
