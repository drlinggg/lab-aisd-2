#include <iostream>
#include <random>

int HoarePartition (int array[],int left, int right) {
    int x=array[rand() % (right - left + 1) + left];
    int i=left-1;
    int j=right+1;
    while (true) {
        do  j--; while (array[j] < x);
        do  i++; while (array[i] > x);
        if  (i < j)
            std::swap(array[i], array[j]);
        else
            return j;
    }
}

int quickselect(int array[], int left, int right, int k) {
  while (true) {
    int mid = HoarePartition(array, left, right);
    if (mid == k-1) {
      return array[mid];
    }
    else if (k-1 < mid) {
      right = mid;
    }
    else {
      left = mid + 1;
    }
  }
}


int main()
{
    int n,k, A,B,C,a1,a2;
    std::cin >> n >> k >> A >> B >> C >> a1 >> a2;
    int ans = 0;
    int array[n];
    array[0] = a1;
    array[1] = a2;
    for (int i = 2; i < n; i++) {
        array[i] = array[i-2] * A + array[i-1] * B + C;
    }
    quickselect(array, 0, n-1, k);
    for (int i = 0; i < k; i++) {
        ans ^= array[i];
    }
    std::cout << ans;
    return 0;
}
