#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Data = pair<ll, vector<int> >;

/*
    参考リンク
    ABC 123 D - Cake 123
      https://atcoder.jp/contests/abc123/tasks/abc123_d
*/

int main() {
  // x,y,z
  vector<ll> n(3);
  rep(i, 3) cin >> n[i];
  int k;
  cin >> k;
  // a,b,c
  vector<vector<ll> > v(3);
  rep(i, 3) {
    v[i].resize(n[i]);
    rep(j, n[i]) cin >> v[i][j];
    sort(v[i].begin(), v[i].end(), greater<ll>());
  }

  priority_queue<Data> que;
  set<Data> se;
  que.push(Data(v[0][0] + v[1][0] + v[2][0], vector<int>({0, 0, 0})));

  rep(i, k) {
    auto c = que.top();
    que.pop();
    cout << c.first << endl;

    // 次の三候補
    rep(j, 3) {
      if (c.second[j] + 1 < n[j]) {
        ll sum = c.first - v[j][c.second[j]] + v[j][c.second[j] + 1];
        auto num = c.second;
        num[j]++;
        auto d = Data(sum, num);
        // すでに push されたもの以外
        if (!se.count(d)) se.insert(d), que.push(d);
      }
    }
  }
}