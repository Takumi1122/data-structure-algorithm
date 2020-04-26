#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int N;
vector<int> w;
vector<vector<int>> dp;
int rec(int l = 0, int r = N) {  // メモ化再帰
  if ((r - l) <= 1) return 0;
  if ((r - l) == 2) {
    if (abs(w[l] - w[l + 1]) <= 1) {  // 隣り合う2つの差が1以下
      return 2;
    } else {
      return 0;
    }
  }
  int &ret = dp[l][r];
  if (ret != -1) return ret;  // 既に計算済みならその値を使う
  // 1. 全部取り除けるとき
  if (abs(w[l] - w[r - 1]) <= 1 && rec(l + 1, r - 1) == r - l - 2)
    chmax(ret, r - l);
  // 2. そうでない時
  for (int i = l + 1; i <= r - 1; i++) {
    chmax(ret, rec(l, i) + rec(i, r));
  }
  return ret;
}
int main() {
  vector<int> ans;
  while (true) {
    cin >> N;
    if (N == 0) break;
    w.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> w.at(i);
    }
    dp.assign(N + 2, vector<int>(N + 2, -1));  // 初期化
    ans.push_back(rec());
  }
  for (auto i : ans) {
    cout << i << endl;
  }
  return 0;
}
