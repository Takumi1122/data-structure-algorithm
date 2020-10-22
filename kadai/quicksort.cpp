#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

//��������ɗv�f����ёւ���֐�
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

//�N�C�b�N�\�[�g���s���֐�
void quicksort(int data[], int begin, int end) {
  if (begin < end) {
    int q = partition(data, begin, end);
    quicksort(data, begin, q);
    quicksort(data, q + 1, end);
  }
}

int main() {
  //�f�[�^����
  int n;
  std::cin >> n;
  int* data = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> data[i];
  }

  //�\�[�g
  quicksort(data, 0, n - 1);

  //�f�[�^�o��
  for (int i = 0; i < n; i++) {
    std::cout << data[i] << ", ";
  }
  delete[] data;
  return 0;
}