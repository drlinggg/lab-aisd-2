#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        array[i] = i+1;
    }
    for (int i = 2; i < n; i++) {
        std::swap(array[i], array[i/2]);
    }
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    return 0;
}
