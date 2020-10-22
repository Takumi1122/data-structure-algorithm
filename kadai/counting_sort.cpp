#include <iostream>

//�J�E���e�B���O�\�[�g���s���֐�
//�z���0�I���W���ł��邱�Ƃɒ���
void counting_sort(int src[], int dest[], int temp[], int n, int k) {
  for (int i = 0; i < k; i++) temp[i] = 0;

  for (int i = 0; i < n; i++) temp[src[i]]++;
  // temp[i] �� i �ɓ������v�f�̌����܂�

  for (int i = 1; i < k; i++) temp[i] = temp[i] + temp[i - 1];
  // temp[i] �� i �ȉ��̗v�f�̌����܂�

  for (int i = n - 1; i >= 0; i--) dest[--temp[src[i]]] = src[i];
}

int main() {
  int n;  // �\�[�g��̌�
  int k;  // ���l�͈̔�(0�`k-1)

  //�f�[�^����
  std::cin >> n;
  std::cin >> k;

  int* src = new int[n];   // �\�[�g���s�����͔z��
  int* dest = new int[n];  // �\�[�g���ꂽ�z��
  int* temp = new int[k];  // �⏕�I�Ȕz��

  for (int i = 0; i < n; i++) {
    std::cin >> src[i];
  }

  //�\�[�g
  counting_sort(src, dest, temp, n, k);

  //�f�[�^�o��
  for (int i = 0; i < n; i++) {
    std::cout << dest[i] << ", ";
  }
  delete[] src;
  delete[] dest;
  delete[] temp;
  return 0;
}