#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  // �鏑�̔z��(���l�͔鏑�̔\��, �傫���قǔ\�͂�����=�̗p������)
  int secretaries[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  // �z��̃T�C�Y
  int size = sizeof(secretaries) / sizeof(secretaries[0]);

  // �̗p�����鏑�̔\�͂̍��v�l
  int secretarySum = 0;

  srand((unsigned int)time(NULL));
  for (int i = 0; i < 1000; i++) {
    // �z��̊e�v�f�Ƀ����_���ɗD��x��t��, �D��x���Ƀ\�[�g
    vector<pair<int, int>> secretaries_pair(size);
    for (int j = 0; j < size; j++) {
      int val = rand() % (size * size * size) + 1;
      secretaries_pair[j].first = val;
      secretaries_pair[j].second = secretaries[j];
    }
    sort(secretaries_pair.begin(), secretaries_pair.end());

    // ���ݍ̗p���̔鏑�̔\��
    int currentSecretary = 0;

    // �I�����C���ٗp�A���S���Y��
    int mx_3 = 0;
    for (int j = 0; j < size; j++) {
      if (j == 0 || j == 1 || j == 2) {
        mx_3 = max(mx_3, secretaries_pair[j].second);
        continue;
      }

      if (mx_3 >= 100) {
        currentSecretary = secretaries_pair[size - 1].second;
        break;
      }

      currentSecretary = max(currentSecretary, secretaries_pair[j].second);
    }
    secretarySum += currentSecretary;
  }

  // �̗p�����鏑�̔\�͂̕��ς�\��
  cout << (float)secretarySum / 1000.0f << endl;
}
