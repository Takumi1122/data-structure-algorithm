#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    AtCoder Beginner Contest 141 E - Who Says a Pun?
      https://atcoder.jp/contests/abc141/tasks/abc141_e
*/

// z-algorithm
// O(n) の前処理で配列 lcp を求める
vector<int> Zalgo(const string &S) {
  int N = (int)S.size();
  vector<int> res(N);
  res[0] = N;
  int i = 1, j = 0;
  while (i < N) {
    while (i + j < N && S[j] == S[i + j]) ++j;
    res[i] = j;
    if (j == 0) {
      ++i;
      continue;
    }
    int k = 1;
    while (i + k < N && k + res[k] < j) res[i + k] = res[k], ++k;
    i += k, j -= k;
  }
  return res;
}

int main() {
  int n;
  string S;
  cin >> n >> S;

  int res = 0;
  for (int i = 0; i < n; ++i) {
    string T = S.substr(i);
    auto lcp = Zalgo(T);

    for (int j = 0; j < T.size(); ++j) {
      int l = min(lcp[j], j);
      res = max(res, l);
    }
  }

  cout << res << endl;
}