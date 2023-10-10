#include <iostream>

int bubble_sort(int *array, int number) {
    while (true) {
        int flag = 0;
        for (int i = 0; i < number-1; i++) {
            if (array[i] - array[i+1] == 1) {
                return 0;
            }
            if (array[i] - array[i + 1] > 1) {
                array[i]--;
                array[i+1]++;
                std::swap(array[i], array[i + 1]);
            }
        }
        for (int i = 0; i < number-1; i++) {
            if (array[i] > array[i + 1]) {
                flag = 1;
            }
        }
        if (flag == 0) {
            return 1;
        }
    }
}

int main() {
    int number;
    std::cin >> number;
    int array[number];
    for (int i = 0; i < number; i++) {
        std::cin >> array[i];
    }
    int ans = bubble_sort(array,number);
    if (ans == 1) {
        for (int i = 0; i < number; i++) {
            std::cout << array[i] << " ";
        }
    }
    else {
        std::cout << ":(";
    }
    return 0;
}
