#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// stoi("0234") => 234

/*
    参考リンク
    ABC 192 C - Kaprekar Number
      https://atcoder.jp/contests/abc192/tasks/abc192_c
*/

int g1(int n) {
  string s = to_string(n);
  sort(s.rbegin(), s.rend());
  return stoi(s);
}
int g2(int n) {
  string s = to_string(n);
  sort(s.begin(), s.end());
  return stoi(s);
}

int f(int n) { return g1(n) - g2(n); }

int main() {
  int n, k;
  cin >> n >> k;
  rep(i, k) n = f(n);
  cout << n << endl;
  return 0;
}