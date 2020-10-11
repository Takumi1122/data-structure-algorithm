#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

// �}�[�W�\�[�g o(n * log(n)) ����\�[�g���@�����\�[�g�~

void mergeSort(vector<int> &a, int left, int right) {
  if (right - left == 1) return;
  int mid = left + (right - left) / 2;

  // ������ [left, mid) ���\�[�g
  mergeSort(a, left, mid);

  // �E���� [mid, right) ���\�[�g
  mergeSort(a, mid, right);

  // ��U�u���v�Ɓu�E�v�̃\�[�g���ʂ��R�s�[���Ă��� (�E���͍��E���])
  vector<int> buf;
  for (int i = left; i < mid; i++) buf.push_back(a[i]);
  for (int i = right - 1; i >= mid; i--) buf.push_back(a[i]);

  // �}�[�W����
  int iterator_left = 0;                     // �����̃C�e���[�^
  int iterator_right = (int)buf.size() - 1;  // �E���̃C�e���[�^
  for (int i = left; i < right; i++) {
    // �����̗p
    if (buf[iterator_left] <= buf[iterator_right]) {
      a[i] = buf[iterator_left++];
    }
    // �E���̗p
    else {
      a[i] = buf[iterator_right--];
    }
  }
}

int main() {
  // ����
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  // �}�[�W�\�[�g
  mergeSort(a, 0, n);

  // �o��
  rep(i, n) cout << a[i] << ", ";
  cout << endl;

  return 0;
}