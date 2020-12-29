#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 111 C - /\/\/\/
      https://atcoder.jp/contests/abc111/tasks/arc103_a
*/

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];

  map<int, int> mp1;
  map<int, int> mp2;
  rep(i, n) {
    if (i % 2 == 0) {
      mp1[v[i]]++;
    } else {
      mp2[v[i]]++;
    }
  }

  P mx1 = {0, 0};
  P mx2 = {0, 0};
  for (auto p : mp1) {
    if (mx1.second < p.second) {
      mx1 = p;
    }
  }
  for (auto p : mp2) {
    if (mx2.second < p.second && p.first != mx1.first) {
      mx2 = p;
    }
  }
  int ans1 = n - mx1.second - mx2.second;

  P mx3 = {0, 0};
  P mx4 = {0, 0};
  for (auto p : mp2) {
    if (mx3.second < p.second) {
      mx3 = p;
    }
  }
  for (auto p : mp1) {
    if (mx4.second < p.second && p.first != mx3.first) {
      mx4 = p;
    }
  }
  int ans2 = n - mx3.second - mx4.second;

  int ans = min(ans1, ans2);
  cout << ans << endl;
  return 0;
}