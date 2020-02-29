#include <iostream>
#include <vector>
using namespace std;

vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

// 目的の値 key の index を返すようにする (ない場合は -1)
int binary_search(int key) {
  int left = 0, right = (int)a.size() - 1;  // 配列 a の左端と右端
  while (right >= left) {
    int mid = left + (right - left) / 2;  // 区間の真ん中
    if (a[mid] == key)
      return mid;
    else if (a[mid] > key)
      right = mid - 1;
    else if (a[mid] < key)
      left = mid + 1;
  }
  return -1;
}

int main() {
  cout << binary_search(51) << endl;   // a[4] = 51 (他に a[3], a[5] も)
  cout << binary_search(1) << endl;    // a[0] = 1
  cout << binary_search(910) << endl;  // a[9] = 910

  cout << binary_search(52) << endl;   // -1
  cout << binary_search(0) << endl;    // -1
  cout << binary_search(911) << endl;  // -1
}