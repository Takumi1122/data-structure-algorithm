#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  // 秘書の配列(数値は秘書の能力, 大きいほど能力が高い=採用したい)
  int secretaries[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  // 配列のサイズ
  int size = sizeof(secretaries) / sizeof(secretaries[0]);

  // 採用した秘書の能力の合計値
  int secretarySum = 0;

  srand((unsigned int)time(NULL));
  for (int i = 0; i < 1000; i++) {
    // 配列の各要素にランダムに優先度を付け, 優先度順にソート
    vector<pair<int, int>> secretaries_pair(size);
    for (int j = 0; j < size; j++) {
      int val = rand() % (size * size * size) + 1;
      secretaries_pair[j].first = val;
      secretaries_pair[j].second = secretaries[j];
    }
    sort(secretaries_pair.begin(), secretaries_pair.end());

    // 現在採用中の秘書の能力
    int currentSecretary = 0;

    // オンライン雇用アルゴリズム
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

  // 採用した秘書の能力の平均を表示
  cout << (float)secretarySum / 1000.0f << endl;
}
