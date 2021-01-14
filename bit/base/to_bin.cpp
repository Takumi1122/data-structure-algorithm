#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

string to_bin(ll n) {
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
    base *= 2;
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  cout << to_bin(123456789) << endl;
  return 0;
}