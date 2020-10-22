#include <algorithm>
#include <cmath>
#include <iostream>

//���R��n�Ɋւ���d���ڂ̐��l�𓾂�֐�
int getDigitValue(int n, int d) {
  return (n % int(pow(10, d + 1))) / int(pow(10, d));
}

//��\�[�g���s���֐�
void radix_sort_impl(int src[], int dest[], int n, int d) {
  int* temp = new int[10];
  for (int i = 0; i < 10; i++) temp[i] = 0;

  for (int i = 0; i < n; i++) {
    int num = getDigitValue(src[i], d);
    temp[num]++;
  }

  for (int i = 1; i < 10; i++) temp[i] = temp[i] + temp[i - 1];

  for (int i = n - 1; i >= 0; i--)
    dest[--temp[getDigitValue(src[i], d)]] = src[i];
}

//��\�[�g���ĂԊ֐�
void radix_sort(int data[], int n, int d) {
  int* dest = new int[n];
  for (int i = 0; i < d; i++) {
    radix_sort_impl(data, dest, n, i);
    std::copy_n(dest, n, data);
  }
  delete[] dest;
}

int main() {
  int n;  // �\�[�g��̌�
  int d;  // ����

  //�f�[�^����
  std::cin >> n;
  std::cin >> d;

  int* data = new int[n];  // �\�[�g���s�����͔z��
  for (int i = 0; i < n; i++) {
    std::cin >> data[i];
  }

  //�\�[�g
  radix_sort(data, n, d);

  //�f�[�^�o��
  for (int i = 0; i < n; i++) {
    std::cout << data[i] << ", ";
  }
  delete[] data;
  return 0;
}