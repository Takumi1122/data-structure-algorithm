#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// std::mapの内部ではキーが昇順になるよう要素がソートされている

/*
    参考リンク
    ABC 155 C - Poll
      https://atcoder.jp/contests/abc155/tasks/abc155_c
*/

int main() {
  int n;
  cin >> n;
  map<string, int> mp;
  rep(i, n) {
    string s;
    cin >> s;
    mp[s]++;
  }

  int mx = 0;
  for (auto p : mp) mx = max(mx, p.second);
  for (auto p : mp) {
    if (p.second != mx) continue;
    cout << p.first << endl;
  }
  return 0;
}
