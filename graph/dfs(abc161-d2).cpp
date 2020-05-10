#include <bits/stdc++.h>
using namespace std;

void rec(int d, long long val, vector<long long> &all) {
  // 格納
  all.push_back(val);

  // 10 桁だったらそれ以上やらずに打ち切り
  if (d == 10) return;

  // 次の桁へ進む処理
  for (int j = -1; j <= 1; ++j) {
    int add = (val % 10) + j;
    if (add >= 0 && add <= 9) rec(d + 1, val * 10 + add, all);
  }
}

int main() {
  int K;
  cin >> K;
  vector<long long> all;
  for (int v = 1; v < 10; ++v) rec(1, v, all);

  // 小さい順に並び替える
  sort(all.begin(), all.end());

  // K 番目
  cout << all[K - 1] << endl;
}