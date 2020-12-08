#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 左右両方からの貪欲

/*
    参考リンク
    ABC 161 E - Yutori
      https://atcoder.jp/contests/abc161/tasks/abc161_e
*/

int main() {
  int n, k, c;
  string s;
  cin >> n >> k >> c >> s;

  // Llimit[i]: i回目の労働日はLlimit[i]から始められる
  // Rlimit[i]: i回目の労働日はRlimit[i]までに終えないといけない
  vector<int> Llimit(n + 1), Rlimit(n + 1);
  // bef: 前の働いた日の日数
  int bef = -2 * c - 1;
  int cnt = 0;
  for (int i = 0; i < n && cnt < k; i++) {
    if (s[i] == 'o') {
      if (i - bef > c) {
        Llimit[cnt] = i + 1;
        cnt++, bef = i;
      }
    }
  }

  bef = n + 2 * c + 1;
  cnt = k - 1;
  for (int i = n - 1; i >= 0 && cnt >= 0; i--) {
    if (s[i] == 'o') {
      if (bef - i > c) {
        Rlimit[cnt] = i + 1;
        cnt--, bef = i;
      }
    }
  }

  rep(i, k) {
    if (Llimit[i] == Rlimit[i] && Llimit[i] != 0) {
      cout << Llimit[i] << endl;
    }
  }
  return 0;
}