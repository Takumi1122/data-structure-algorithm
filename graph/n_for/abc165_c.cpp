#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 165 C - Many Requirements
      https://atcoder.jp/contests/abc165/tasks/abc165_c
*/

// 入力
int n, m, q;
vector<ll> a, b, c, d;

// 数列 A のスコアを計算
ll score(const vector<int> &A) {
  ll res = 0;
  rep(i, q) if (A[b[i]] - A[a[i]] == c[i]) res += d[i];
  return res;
}

// 数列 A に要素を付け加えて行って、最終的にできる数列のうちの
// スコアの最大値を返す
// 特に、最初の呼出しに対する返り値が答え
ll dfs(vector<int> &A) {
  if (A.size() == n) {
    return score(A);
  }

  ll res = 0;
  int prev_last = (A.empty() ? 1 : A.back());

  for (int add = prev_last; add <= m; ++add) {
    A.push_back(add);
    res = max(res, dfs(A));  // 再帰呼出しながら、スコア最大値を更新
    A.pop_back();
  }

  return res;
}

int main() {
  cin >> n >> m >> q;
  a.resize(q);
  b.resize(q);
  c.resize(q);
  d.resize(q);
  rep(i, q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i], --b[i];
  }
  vector<int> A;
  cout << dfs(A) << endl;
}