#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

//枢軸を基準に要素を並び替える関数
int partition(int data[], int begin, int end) {
  int pivot_index = (begin + end) / 2;
  int pivot = data[pivot_index];
  swap(data[pivot_index], data[end]);

  int i = begin;
  for (int j = begin; j < end; j++) {
    if (data[j] < pivot) {
      swap(data[i++], data[j]);
    }
  }
  swap(data[i], data[end]);
  return i;
}

//クイックソートを行う関数
void quicksort(int data[], int begin, int end) {
  if (begin < end) {
    int q = partition(data, begin, end);
    quicksort(data, begin, q);
    quicksort(data, q + 1, end);
  }
}

int main() {
  //データ入力
  int n;
  std::cin >> n;
  int* data = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> data[i];
  }

  //ソート
  quicksort(data, 0, n - 1);

  //データ出力
  for (int i = 0; i < n; i++) {
    std::cout << data[i] << ", ";
  }
  delete[] data;
  return 0;
}