#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>
#include <utility>
#include <vector>
using namespace std;

//何らかの時間がかかる処理
void something_to_do() {
  using namespace std::chrono_literals;
  std::this_thread::sleep_for(100ms);
}

int main() {
  // 秘書の配列(数値は秘書の能力, 大きいほど能力が高い=採用したい)
  int secretaries[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  // 配列のサイズ
  int size = sizeof(secretaries) / sizeof(secretaries[0]);

  // 現在採用中の秘書の能力
  int currentSecretary = 0;

  // 配列の各要素にランダムに優先度を付け, 優先度順にソート
  srand((unsigned int)time(NULL));
  vector<pair<int, int>> secretaries_pair(size);
  for (int i = 0; i < size; i++) {
    int val = rand() % (size * size * size) + 1;
    secretaries_pair[i].first = val;
    secretaries_pair[i].second = secretaries[i];
  }
  sort(secretaries_pair.begin(), secretaries_pair.end());

  //時間計測開始
  auto start = chrono::system_clock::now();

  for (int i = 0; i < size; i++) {
    // 現在採用中の秘書よりも優れた能力か
    if (currentSecretary < secretaries_pair[i].second) {
      something_to_do();  // 採用手続き(何らかの時間がかかる処理)
      currentSecretary = secretaries_pair[i].second;
    }
  }

  // 時間計測終了
  auto end = chrono::system_clock::now();

  // かかった時間の表示
  cout << chrono::duration_cast<chrono::milliseconds>(end - start).count()
       << " msec" << endl;
}
