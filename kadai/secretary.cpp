#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>
#include <utility>
#include <vector>
using namespace std;

//���炩�̎��Ԃ������鏈��
void something_to_do() {
  using namespace std::chrono_literals;
  std::this_thread::sleep_for(100ms);
}

int main() {
  // �鏑�̔z��(���l�͔鏑�̔\��, �傫���قǔ\�͂�����=�̗p������)
  int secretaries[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  // �z��̃T�C�Y
  int size = sizeof(secretaries) / sizeof(secretaries[0]);

  // ���ݍ̗p���̔鏑�̔\��
  int currentSecretary = 0;

  // �z��̊e�v�f�Ƀ����_���ɗD��x��t��, �D��x���Ƀ\�[�g
  srand((unsigned int)time(NULL));
  vector<pair<int, int>> secretaries_pair(size);
  for (int i = 0; i < size; i++) {
    int val = rand() % (size * size * size) + 1;
    secretaries_pair[i].first = val;
    secretaries_pair[i].second = secretaries[i];
  }
  sort(secretaries_pair.begin(), secretaries_pair.end());

  //���Ԍv���J�n
  auto start = chrono::system_clock::now();

  for (int i = 0; i < size; i++) {
    // ���ݍ̗p���̔鏑�����D�ꂽ�\�͂�
    if (currentSecretary < secretaries_pair[i].second) {
      something_to_do();  // �̗p�葱��(���炩�̎��Ԃ������鏈��)
      currentSecretary = secretaries_pair[i].second;
    }
  }

  // ���Ԍv���I��
  auto end = chrono::system_clock::now();

  // �����������Ԃ̕\��
  cout << chrono::duration_cast<chrono::milliseconds>(end - start).count()
       << " msec" << endl;
}
