#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 個数制限付きナップサック問題 O(n * W)
// スライド最大値

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_G
*/

template <class T, class Compare = greater<T> >
vector<T> knapsack_limit(const vector<int> &w, const vector<int> &m,
                         const vector<T> &v, const int &W, const T &NG,
                         const Compare &comp = Compare()) {
  const int N = (int)w.size();
  vector<T> dp(W + 1, NG), deqv(W + 1);
  dp[0] = T();
  vector<int> deq(W + 1);
  for (int i = 0; i < N; i++) {
    for (int a = 0; a < w[i]; a++) {
      int s = 0, t = 0;
      for (int j = 0; w[i] * j + a <= W; j++) {
        if (dp[w[i] * j + a] != NG) {
          auto val = dp[w[i] * j + a] - j * v[i];
          while (s < t && comp(val, deqv[t - 1])) --t;
          deq[t] = j;
          deqv[t++] = val;
        }
        if (s < t) {
          dp[j * w[i] + a] = deqv[s] + j * v[i];
          if (deq[s] == j - m[i]) ++s;
        }
      }
    }
  }
  return dp;
}

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> v(n), w(n), m(n);
  rep(i, n) cin >> v[i] >> w[i] >> m[i];

  auto ret = knapsack_limit(w, m, v, W, -1);
  cout << *max_element(begin(ret), end(ret)) << endl;
}