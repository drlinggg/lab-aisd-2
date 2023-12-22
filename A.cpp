#include <iostream>

int main() {
    int number_of_tapoks;
    std::cin >> number_of_tapoks;
    int tapki[number_of_tapoks];
    for (int i = 0; i < number_of_tapoks; i++) {
        std::cin >> tapki[i];
    }
    for (int i = 1; i < number_of_tapoks; i++) {
        int currect = i;
        while (tapki[currect] < tapki[currect-1] && currect > 0) {
            std::swap(tapki[currect], tapki[currect-1]);
            currect--;
        }
    }
    for (int i = 0; i < number_of_tapoks; i++) {
        std::cout << tapki[i] << " ";
    }
    return 0;

}
