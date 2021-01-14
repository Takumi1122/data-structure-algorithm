#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 105 C - Base -2 Number
      https://atcoder.jp/contests/abc105/tasks/abc105_c
*/

string to_mbin(ll n) {
  if (n == 0) return "0";

  string res = "";
  ll base = 1;
  while (n) {
    if (n % (base * 2) == 0) {
      res += '0';
    } else {
      res += '1';
      n -= base;
    }
    base *= -2;
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  int n;
  cin >> n;

  cout << to_mbin(n) << endl;
  return 0;
}