#include <iostream>

void mergeSort(int* a, int* tmp, int l, int r, long long& count) {
    if (l == r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(a, tmp, l, m, count);
    mergeSort(a, tmp, m + 1, r,count);
    for (int i = l; i <= r; i++) {
        tmp[i] = a[i];
    }
    int ai = l, bi = m + 1;
    for (int i = l; i <= r; i++) {
        if (bi > r || ai <= m && tmp[ai] <= tmp[bi]) {
            a[i] = tmp[ai++];
        }
        else {
            a[i] = tmp[bi++];
            count += m - ai + 1;
        }
    }
}


long long count = 0;

int main() {
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    int tmp[n];
    mergeSort(array, tmp, 0, n-1, count);
    std::cout << count;
    return 0;
}
